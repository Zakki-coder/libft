#include <stdlib.h>
#include "unity.h"
#include "libft.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_ft_lstnew(void) {
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
	size += 1;
}
void test_function_lstdelone(void) {
	printf("\n-----ft_lstdelone-----\n");
	char a[] = "To NULL or NOTTONULL?!"; 
    t_list *to_null = ft_lstnew(a, 25);
	ft_lstdelone(&to_null, ft_memndel);
	TEST_ASSERT_NULL (to_null);
	//Call with NULL function
	t_list *null = ft_lstnew("Hello", 6);
	ft_lstdelone(&null, NULL);
	TEST_ASSERT_NOT_NULL (null);
}
//Testing ft_lstdel
void test_function_ft_lstdel(void)
{
	printf("\n-----ft_lstdel-----\n");
	t_list *head = ft_lstnew("This is a head which is ahead\n", 35);
	t_list *link1 = ft_lstnew("This is link nb 1\n", 30);
	t_list *link2 = ft_lstnew("This is link nb 2\n", 30);
	head->next = link1;
	head->next->next = link2;
	ft_lstdel(&head , ft_memndel);
	TEST_ASSERT_NULL (head);
	TEST_ASSERT_NULL (link1->next);
	TEST_ASSERT_NULL (link2->next);
	//Test with NULL function
	head = ft_lstnew("This is a head which is ahead\n", 35);
	link1 = ft_lstnew("This is link nb 1\n", 30);
	link2 = ft_lstnew("This is link nb 2\n", 30);
	head->next = link1;
	head->next->next = link2;
	ft_lstdel(&head, NULL);
	TEST_ASSERT_NOT_NULL (head);
	TEST_ASSERT_NOT_NULL (link1->next);
	TEST_ASSERT_NULL (link2->next);
}
// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
	RUN_TEST(test_ft_lstnew);
 	RUN_TEST(test_function_lstdelone);
 	RUN_TEST(test_function_ft_lstdel);
    return UNITY_END();
}
