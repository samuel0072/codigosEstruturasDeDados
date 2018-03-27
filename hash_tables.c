#include <stdio.h>
#include <stdlib.h>

typedef struct element element;
typedef struct hash_table hash_table;

struct element{
	int key;
	int value;
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
  /*Atualizando os dados :D/
  for(i = 0; i < 20; ++i)
  {
  	put(ht, i, i+(13*(i%75)));
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

/*Linear resolution implementation*/
void put(hash_table* ht, int key, int value)
{
	int h = key % 11, begin = (key % 11)-1;
	while((ht->table[h]!= NULL) && (h != begin))
	{
		begin = key % 11;
		//printf("%d %d\n", begin, h);
		if((ht->table[h]->key) == (key))
		{
			ht->table[h]->value = value;
			return;
		}
		h = (h + 1) % 11;
	}

	if(ht->table[h] == NULL)
	{
		element *new_element = (element*)malloc(sizeof(element));
		new_element->key = key;
		new_element->value = value;
		ht->table[h] = new_element;
	}
}


int get(hash_table* ht, int key)
{
	int h = key % 11, begin = h;

	do
	{
		if(ht->table[h]->key == key)
		{
			return ht->table[h]->value;
		}
		h = (h + 1) % 11;
	}while((ht->table[h]!= NULL) && (h != begin));
	return -100;
}


void remove_from_hash_table(hash_table* ht, int key)
{
	int h = key % 11, begin = h;
	do
	{
		if(ht->table[h]->key == key)
		{
			ht->table[h]->key = -1;	
			return;
		}
		h = (h + 1) % 11;
	}while(ht->table[h] != NULL && (h != begin));
}


int contains_key(hash_table* ht, int key)
{
	int h = key % 11, begin = h;
	do
	{
		if(ht->table[h]->key == key)
		{
			return 1;
		}
		h = (h + 1) % 11;
	}while((ht->table[h]!= NULL) && (h != begin));

	return 0;//not found :(
}


void print_hash_table(hash_table* ht)
{
	int i, aux;
	for(i = 0; i < 11; ++i)
	{
		aux = get(ht, i);
		if(aux != -100)
			printf("-- key = %d and value = %d\n", i, aux);
	}
}
