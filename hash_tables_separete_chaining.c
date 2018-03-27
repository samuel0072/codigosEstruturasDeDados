#include <stdio.h>
#include <stdlib.h>

typedef struct element element;
typedef struct hash_table hash_table;

struct element{
	int key;
	int value;
	element* next;
};

struct hash_table{
	element* table[11];
};

hash_table* create_hash_table();

void put(hash_table* ht, int key, int value);

int get(hash_table* ht, int key);

void remove_from_hash_table(hash_table* ht, int key);

int contains_key(hash_table* ht, int key);

void print_hash_table(hash_table* ht);

/*Funções para manipular a lista*/
element* create_empty_list();

element* add_to_head(element* head, int key, int value);

element* remove_from_list(element* head, int key);


int main()
{
  hash_table* ht = create_hash_table();
  int i, aux;
  for(i = 0; i < 20; ++i)
  {
  	put(ht, i, i+(7*(i%75)));
  }
  for(i = 0; i < 20; ++i)
  {
  	aux = get(ht, i);
  	if(aux != -100)
  	{
  		printf("get(ht, %d) = %d\n", i, aux);
  	}
  }
  
  print_hash_table(ht);

  return 0;
}

hash_table* create_hash_table()
{
	hash_table *new_hash_table = (hash_table*)malloc(sizeof(hash_table));
	int i;
	for(i = 0; i < 11; ++i)
	{
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

void put(hash_table* ht, int key, int value)
{
	int h = key % 11;
	if(ht->table[h] == NULL)
	{
		ht->table[h] = create_empty_list();
	}
	ht->table[h] = add_to_head(ht->table[h], key, value);
}


int get(hash_table* ht, int key)
{
	int h = key % 11;
	
	element* current = ht->table[h];

	while(current!= NULL)
	{
		if(current->key == key)
		{
			return current->value;
		}
		current = current->next;
	}
	return -100;
}


void remove_from_hash_table(hash_table* ht, int key)
{
	int h = key % 11;
	ht->table[h] = remove_from_list(ht->table[h], key);
}


int contains_key(hash_table* ht, int key)
{
	int h = key % 11;

	element* current = ht->table[h];

	while(current != NULL)
	{
		if(current->key == key)
		{
			return 1;
		}
	}

	return 0;//not found :(
}


void print_hash_table(hash_table* ht)
{
	int i, aux;
	for(i = 0; i < 20; ++i)
	{
		aux = get(ht, i);
		if(aux != -100)
			printf("-- key = %d and value = %d\n", i, aux);
	}
}

/*funções para manipular a lista*/
element* create_empty_list()
{
	return NULL;
}


element* add_to_head(element* head, int key, int value)
{
	element* new_element = (element*)malloc(sizeof(element));
	new_element->key = key;
	new_element->value = value;
	new_element->next = head;
	return new_element;
}


element* remove_from_list(element* head, int key)
{
	if(head == NULL)
    {
	    printf("Lista vazia!\n");
	    return head;
  	}
  	element *current = head, *previous = NULL;

  	while(current!= NULL && current->key != key)
  	{
    	previous = current;
    	current = current->next;
  	}

  	if(previous == NULL)
  	{
    	element *aux = head->next;
    	free(head);
    	return aux;
  	}
  	if(current == NULL)
  	{
    	printf("Elemento nao existe na lista!\n");
    	return head;
  	}
  	previous->next = current->next;
  	free(current);
	return head;
}


