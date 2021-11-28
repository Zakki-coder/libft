#include <stdlib.h>
#include "unity.h"
#include "libft.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_correct_input(void) {
	printf("\n-----ft_lstnew-----\n");
	// With correct input and size
   	char a[20] = "Me fancy fine words";
	t_list *res = ft_lstnew((void *)a, sizeof(a));
	TEST_ASSERT_EQUAL_STRING (a, (char *)(*res).content);
	TEST_ASSERT_EQUAL_INT (20, (*res).content_size);
	TEST_ASSERT_EQUAL_PTR (NULL, (*res).next);
	TEST_ASSERT (a != (*res).content);
	// With NULL content
	res = ft_lstnew(NULL, sizeof(a));
	TEST_ASSERT_NULL ((char *)(*res).content);
	TEST_ASSERT_EQUAL_INT (0, (*res).content_size);
	TEST_ASSERT_NULL ((*res).content);
	TEST_ASSERT (a != (*res).content);
	// With contetn size smaller than string
	char a2[5];
	memset(a2, 'x', sizeof(a2));
	memset(a2, 'o', 3);
	res = ft_lstnew((void *)a2, 3);
	TEST_ASSERT_EQUAL_MEMORY (a2, (char*)(*res).content, 3); 
	TEST_ASSERT_EQUAL_INT (3, (*res).content_size);
	TEST_ASSERT_NULL ((*res).next);
	TEST_ASSERT (a != (*res).content);

}
//Function for testing lstdelone
void ft_memndel(void *del, size_t size)
{
	free (del);
	size = 0;
}
void test_function_lstdelone(void) {
	printf("\n-----ft_lstdelone-----\n");
	char a[] = "To NULL or NOTTONULL?!"; 
    t_list *to_null = ft_lstnew(a, 25);
	ft_lstdelone(&to_null, ft_memndel);
	TEST_ASSERT_NULL (to_null);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
	RUN_TEST(test_function_correct_input);
 	RUN_TEST(test_function_lstdelone);
    return UNITY_END();
}
