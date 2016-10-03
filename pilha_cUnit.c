#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

struct elemento
{
	int value;
	struct elemento *prox;
};

typedef struct elemento Elemento;

struct pilha
{
	Elemento *top;
};

typedef struct pilha Pilha;


Pilha* new_slack()
{
	Pilha *new = (Pilha*)malloc(sizeof(Pilha));
	new -> top = NULL; 
	return new;
}

void push(Pilha *p, int item)
{
	Elemento* newtop = (Elemento*)malloc(sizeof(Elemento));
	newtop -> value = item;
	newtop -> prox = p -> top;
	p -> top = newtop;
}

int is_empty(Pilha *p)
{
	if(p -> top == NULL)
	{
		return 0;
	}
	else return 1;
}

int pop(Pilha* p)
{
	if(is_empty(p) == 0)
	{
		return 0;
	}
	else 
	{
		Elemento* t;
		int v;
		t = p -> top;
		v = t -> value;
		p -> top = t -> prox;
		free(t);
		return v;
	}
}

int peek(Pilha* p)
{
	if(is_empty(p) == 0)
	{
		return 0;
	}
	else 
	{		
		Elemento* t;
		int v;
		t = p -> top;
		v = t -> value;
		return v;
	}
}
void test_empty_stack(Pilha *p)
{
	CU_ASSERT_TRUE(is_empty(p));
}

void test_push_stack(Pilha *p)
{
	push(p, 3);
	CU_ASSERT_EQUAL(peek(p), 3);
	CU_ASSERT_NOT_EQUAL(peek(p), -1);

	push(p, 7);
	CU_ASSERT_EQUAL(peek(p), 7);
	CU_ASSERT_NOT_EQUAL(peek(p), -1);

	push(p, 13);
	CU_ASSERT_EQUAL(peek(p), 13);
	CU_ASSERT_NOT_EQUAL(peek(p), -1);

	push(p, 9999);
	CU_ASSERT_EQUAL(peek(p), 9999);
	CU_ASSERT_NOT_EQUAL(peek(p), -1);
}

void test_pop_stack(Pilha *p)
{
	push(p, 3);
	CU_ASSERT_EQUAL(pop(p), 3);

	push(p, 7);
	CU_ASSERT_NOT_EQUAL(pop(p), -1);

	push(p, 13);
	CU_ASSERT_EQUAL(pop(p), 13);

	push(p, 9999);
	CU_ASSERT_NOT_EQUAL(pop(p), -1);
}

int main()
{
	Pilha* p = new_slack();

	CU_pSuite pSuite = NULL;

	//Inicializa o cUnit
	if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

  	//Primeiro teste: Verificar se esta vazia
 	pSuite = CU_add_suite("stack_is_empty_test", 0, 0);


	if (NULL == pSuite) 
	{
	  	CU_cleanup_registry();
	  	return CU_get_error();
	}

	if(NULL == CU_add_test(pSuite, "test_empty_stack", test_empty_stack)) 
	{
	  CU_cleanup_registry();
	  return CU_get_error();
	}



	//Segundo teste: Verificar a função push
	pSuite = CU_add_suite("stack_push_test", 0, 0);	

	if (NULL == pSuite) 
	{
	  	CU_cleanup_registry();
	  	return CU_get_error();
	}
	if(NULL == CU_add_test(pSuite, "stack_push_test", test_push_stack)) 
	{
	  CU_cleanup_registry();
	  return CU_get_error();
	}


	//Terceiro teste: Verificar a função pop
	pSuite = CU_add_suite("stack_pop_test", 0, 0);	

	if (NULL == pSuite) 
	{
	  	CU_cleanup_registry();
	  	return CU_get_error();
	}
	if(NULL == CU_add_test(pSuite, "stack_pop_test", test_pop_stack)) 
	{
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	

	CU_basic_set_mode(CU_BRM_VERBOSE);
	
	CU_basic_run_tests();
	CU_cleanup_registry();
   	return CU_get_error();
}