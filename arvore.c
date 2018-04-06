#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree binary_tree;

struct binary_tree{
	int value;
	binary_tree* left;
	binary_tree* right;
};

void print_in_order(binary_tree* bt);
void print_pre_order(binary_tree* bt);
void print_post_order(binary_tree* bt);

binary_tree	*create_empty();
binary_tree	*create_tree(int value, binary_tree* left, binary_tree* right);

int is_empty(binary_tree* bt);

binary_tree* add_search_binary(binary_tree* bt, int value);
binary_tree* binary_search(binary_tree* bt, int value);
int depth_binary_search(binary_tree* bt, int value);

int height(binary_tree* bt);

binary_tree* search(binary_tree* bt, int value);
int depth(binary_tree* bt, int value);

int main()
{

	binary_tree* bt = create_empty();

	bt = create_tree(90,
			 create_tree(87,
			 	create_tree(76,
			 		create_tree(354, NULL, NULL),
			 		create_tree(68, NULL, NULL)),
			 	create_tree(34,
			 		create_tree(59, NULL, NULL),
			 		create_tree(88, NULL, NULL))),
			 create_tree(65,
			 	create_tree(46,
			 		create_tree(87, NULL, NULL),
			 		create_tree(5546, NULL, NULL)),
			 	create_tree(58,
			 		create_tree(564, NULL, NULL),
			 		create_tree(574, NULL, NULL))));
	/*bt = add_search_binary(bt, 54);
	bt = add_search_binary(bt, 50);
	bt = add_search_binary(bt, 567);
	bt = add_search_binary(bt, 52);
	bt = add_search_binary(bt, 115);
	bt = add_search_binary(bt, 5248);
	bt = add_search_binary(bt, 49);
	bt = add_search_binary(bt, 51);
	bt = add_search_binary(bt, 53);*/

	binary_tree* aux1 = search(bt, 5546);
	//print_in_order(bt);
	//printf("\n");
	if(aux1!= NULL)
	{
	    //int height_1 = height(aux1);
		int aux2 = depth(bt, aux1->value);
		printf("%d", aux2);
	}
	else
	{
		printf("No nao localizado!");
	}
	return 0;
}

binary_tree	*create_empty()
{
	return NULL;
}

binary_tree	*create_tree(int value, binary_tree* left, binary_tree* right)
{
	binary_tree* new = (binary_tree*)malloc(sizeof(binary_tree));

	new->value = value;
	new->left = left;
	new->right = right;
	return new;
}

int is_empty(binary_tree* bt)
{
	return (bt == NULL);
}

void print_in_order(binary_tree* bt)
{
	if(!is_empty(bt))
	{
		print_in_order(bt->left);
		printf("%d ", bt->value);
		print_in_order(bt->right);
	}
}

void print_pre_order(binary_tree* bt)
{
	if(!is_empty(bt))
	{
		printf("%d ", bt->value);
		print_pre_order(bt->left);
		print_pre_order(bt->right);
	}
}

void print_post_order(binary_tree* bt)
{
	if(!is_empty(bt))
	{
		print_post_order(bt->left);
		print_post_order(bt->right);
		printf("%d ", bt->value);
	}
}

binary_tree* add_search_binary(binary_tree* bt, int value)
{
	if(is_empty(bt))
	{
		bt = create_tree(value, NULL, NULL);
	}
	else if(value > bt->value)
	{
		bt->right = add_search_binary(bt->right, value);
	}
	else
	{
		bt->left = add_search_binary(bt->left, value);
	}
	return bt;
}

binary_tree* binary_search(binary_tree* bt, int value)
{
	if((is_empty(bt)) || (bt->value == value))
	{
		return bt;
	}
	else if(value > bt->value)
	{
		return binary_search(bt->right, value);
	}
	else
	{
		return binary_search(bt->left, value);
	}
}

int depth_binary_search(binary_tree* bt, int value)
{
	if(bt->value == value)
	{
		return 0;
	}
	else if(bt->value > value)
	{
		return 1 + depth(bt->left, value);
	}
	else
	{
		return 1 + depth(bt->right, value);
	}
}
int height(binary_tree* bt)
{
	if(is_empty(bt->left) || is_empty(bt->right))
	{
		return 0;
	}
	int height_left, height_right;
	height_left = height(bt->left);
	height_right= height(bt->right);

	if(height_left > height_right)
	{
		return 1 + height_left;
	}
	else
	{
		return 1 + height_right;
	}
}

binary_tree* search(binary_tree* bt, int value)
{
	if(is_empty(bt) || bt->value == value)
	{
		return bt;
	}
	else
	{
		binary_tree* target = search(bt->left, value);
		if((target == NULL) || (target->value != value))
			target = search(bt->right, value);

		return target;
	}

}

int depth(binary_tree* bt, int value)
{
	if((bt->left == NULL) && (bt->right == NULL) && (bt->value != value))
	{
		return -96486;//chegou em uma folha e não é o nó encontrado
	}
	if(bt->value == value)
	{
		return 0;
	}
	else
	{
		int depth_left = 1 + depth(bt->left, value);
		if(depth_left < 0)/*Se não encontrou o nó na sub arvore da esquerda, procure na sub arvore da direita*/
		{
			depth_left = 1 + depth(bt->right, value);
		}
		return depth_left;
	}
}
