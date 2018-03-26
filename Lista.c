#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int info;
  struct node* next;
} node;

node* create_empty_list();

node* add_to_head(node* head, int info);

void add_to_end(node* head, int info);

void print_linked_list(node* head);

node* add_sorted(node* head, int info);

void duplicate(node* head, node*next);

node* remove_from_list(node* head, int target);

node* remove_from_list_duplicated(node* head, int target);

void loop_to_sla(node* head);

void remove_duplications(node* head);

int main()
{
  node* head = create_empty_list();

  head = add_sorted(head, 20);
  head = add_sorted(head, 17);
  head = add_sorted(head, 2);
  head = add_sorted(head, 52);
  head = add_sorted(head, 1);
  head = add_sorted(head, 20);
  head = add_sorted(head, 100);
  head = add_sorted(head, 28);

  duplicate(head, head);

  print_linked_list(head);
  printf("\n");

  head = remove_from_list_duplicated(head, 2);

  loop_to_sla(head);
  
  print_linked_list(head);
  printf("\n");

  return 0;
}

node* create_empty_list()
{
  return NULL;
}

node* add_to_head(node* head, int info)
{
  node* new_node = (node*)malloc(sizeof(sizeof(node)));
  new_node->info = info;
  new_node->next = head;
  return new_node;
}

void add_to_end(node* head, int info)
{
  if(head == NULL)
  {
    printf("Lista vazia! adicionar elemento no inicio da lista primeiro\n");
    exit(0);
  }
  if(head->next == NULL)
  {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->info = info;
    new_node->next = NULL;
    head->next = new_node;
  }
  else
  {
    add_to_end(head->next, info);
  }
}

void print_linked_list(node* head)
{
  if(head!= NULL)
  {
    printf("%d ", head->info);
    print_linked_list(head->next);
  }
}

node* add_sorted(node* head, int info)
{
  node* new_node =(node*)malloc(sizeof(node));

  new_node->info = info;
  new_node->next = head;

  if(head == NULL)
  {
    return new_node;
  }

  node* previous = NULL;
  node* current = head;

  while((current!= NULL) && (current->info < info))
  {
    previous = current;
    current = current->next;
  }

  if(previous == NULL)
  {
    head = add_to_head(head, info);
    return head;
  }

  previous->next = new_node;
  new_node->next = current;

  return head;
}

void duplicate(node* head, node*next)
{
  if(next!= NULL)
  {
    duplicate(head, next->next);
    if((next->info%2) == 0)
    {
      add_sorted(head, next->info);
    }
  }
}

node* remove_from_list(node* head, int target)
{
  if(head == NULL)
  {
    printf("Lista vazia!\n");
    return head;
  }
  node *current = head, *previous = NULL;

  while(current!= NULL && current->info != target)
  {
    previous = current;
    current = current->next;
  }

  if(previous == NULL)
  {
    node *aux = head->next;
    free(head);
    return aux;
  }
  if(current == NULL)
  {
    printf("Elemento nÃ£o existe na lista!\n");
    return head;
  }
  previous->next = current->next;
  free(current);
  return head;
}

node* remove_from_list_duplicated(node* head, int target)
{
  if(head == NULL)
  {
    printf("Lista vazia!\n");
    return head;
  }
  node *current = head, *previous = NULL;

  while(current!= NULL)
  {
    if(current->info == target)
    {
      if(previous == NULL)
      {
        node* aux = head;
        head = head->next;
        free(aux);
        current = head;
      }
      else
      {
        node* aux = current;
        previous->next = current->next;
        current = previous->next;
        free(aux);
      }
    }
    else
    {
      previous = current;
      current = current->next;
    }
  }
  return head;
}

void loop_to_sla(node* head)
{
  if(head!= NULL)
  {
    remove_duplications(head);
    loop_to_sla(head->next);
  }
}

void remove_duplications(node* head)
{
  node *current, *previous;
  current = head->next;
  previous = head;

  while(current!= NULL)
  {
    if(current->info == head->info)
    {
      node* aux = current;
      previous->next = current->next;
      current = current->next;
      free(aux);
    }
    else
    {
      previous = current;
      current = current->next;
    }
  }
}
