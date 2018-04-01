#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node;
typedef struct queue queue;

struct node{
	int info;
	node* next;
};

struct queue{
	node* begin;
	node* end;
};
queue* create_empty_queue();

void enqueue(queue* q, int info);

node* dequeue(queue* q);

int is_empty(queue* q);

int main()
{
	queue* q = create_empty_queue();
	int i;
	node* dequeded;
	for(i = 1; i <= 10; ++i)
	{
		enqueue(q, i);
		printf("enqueded -> %d\n", q->end->info);
	}
	printf("\n");
	while(!is_empty(q))
	{
		dequeded = dequeue(q);
		printf("dequeded -> %d\n", dequeded->info);
	}
	return 0;
}

queue* create_empty_queue()
{
	queue* new_queue = (queue*)malloc(sizeof(queue*));

	new_queue->begin = NULL;
	new_queue->end = NULL;
	return new_queue;
}

void enqueue(queue* q, int info)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->info = info;

	if(q->begin == NULL)
	{
		new_node->next = NULL;
		q->begin = new_node;
		q->end = new_node; 
	}
	else
	{
		new_node->next = NULL;
		q->end->next = new_node;
		q->end = new_node;
	}
}

node* dequeue(queue* q)
{
	node* target = q->begin;

	q->begin = q->begin->next;

	target->next = NULL;

	return target;
}

int is_empty(queue* q)
{
	return (q->begin == NULL);
}
