// Use -D flag with compiler like; -DSTRCPY

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include "libft.h"
#define ASCII_MIN 0
#define ASCII_MAX 31
#define DEL 127


#ifdef STRCPY
int main(void)
{
	printf("ft_strcpy: ");
	const char src[] = "To be or not to be, that is the question.";
	char dest[42];
	char dest_small[10];
	char *target;
	
	//printf("Addresses before function call:\n");
	//printf("Src: %p, dest: %p\n", src, dest);
	target = ft_strcpy(dest, src);
	//printf("Addresses after function call:\n");
//	printf("Src: %p, dest: %p\n", src, dest);
	assert(src != dest);
	//printf("Input: %s\n", src);
	//printf("String from dest: %s\nString from target: %s\n", dest, target);
	if (!strcmp(dest, src))
		printf("OK\n");
	else
		printf("FAIL");
	target = ft_strcpy(dest_small, src);
	//printf("\nWhen destination is too small, it overflows:\n");
	//printf("%s\n", target);	
	return (0);
}

 /* Adrress should'n change
 */
#endif

#ifdef STRLEN
int main(void)
{
	printf("ft_strlen: ");
	const char *s = "kissa";
	assert(strlen(s) == ft_strlen(s));
//	if ((strlen(s) != ft_strlen(s)))
//		printf("Error, should be: %zu is: %zu\n", strlen(s), ft_strlen(s));
//	else
//		printf("PASS, should be: %zu IS: %zu\n", strlen(s), ft_strlen(s));
	char c = 'b';
	const char *s2 = &c;
	s = s2;
	assert(strlen(s) == ft_strlen(s));
//	if ((strlen(s) != ft_strlen(s)))
//		printf("Error, should be: %zu is: %zu\n", strlen(s), ft_strlen(s));
//	else
//		printf("PASS, should be: %zu IS: %zu\n", strlen(s), ft_strlen(s));
	const char *s3 = "123";
	s = s3;
	assert(strlen(s) == ft_strlen(s));
//	if ((strlen(s) != ft_strlen(s)))
//		printf("Error, should be: %zu is: %zu\n", strlen(s), ft_strlen(s));
//	else
//		printf("PASS, should be: %zu IS: %zu\n", strlen(s), ft_strlen(s));
	printf("OK\n");
	return (0);
}
#endif

#ifdef STRDUP
int main(void)
{
	printf("ft_strdup: ");
	const char *s1 = "Cat's are cat's?";
	char *outcome = ft_strdup(s1);

	//printf("Is it correct?\n");
	//printf("Input: %s\n", s1);
	//printf("Output: %s\n", outcome);
	//printf("Answer: ");
	if (!strcmp(s1, outcome))
		printf("YES\n");
	else
		printf("NO\n");
	//printf("Value of strcmp: %d\n", strcmp(s1, outcome));
	return (0);
}
/* Must return NULL if fail malloc
 */
#endif

#ifdef STRNCPY
int main(void)
{
	const char src[] = "Luke, who's your daddy?";
	char dest_enough[30];
//	char dest_short[30];
	char dest_third[30];
	char *dest;
	int i = 0;
	int counter = 0;
	
	printf("ft_strncpy: ");
	dest = ft_strncpy(dest_enough, src, 30);
	//printf("Matching io: ");
	assert(!strcmp(src, dest));
	//printf("OK\n");	
	//printf("Input:  %s\n", src);	
	//printf("Output: %s\n", dest);
	//printf("Testing equality of destination addresses: ");
	assert(dest_enough == dest);
	//printf("OK\n");
	//printf("Address of dest: %p, Address of return: %p\n", dest_enough, dest);
	//dest = ft_strncpy(dest_short, src, 9);
	//printf("Testing for n < src. N = 9 output usually differs: %lu ", strlen(dest));
//	assert(strlen(dest) != 9);
	//printf(":OK\n");
	//printf("Input:  %s\n", src);
	//printf("Output: %s\n", dest);
	//printf("Testing if rest of array is filled with null when n > src: ");
	dest = ft_strncpy(dest_third, src, 30);
	i = 30 - (30 - strlen(src));
	while (i < 30 && dest[i] == '\0')
	{
		++i;
		++counter;
	}
	assert(counter == 30 - strlen(src));
	//printf("OK\n");
	//printf("Expected n of NULL: %lu, result: %d\n", 30 - strlen(src), counter);
	printf("OK\n");
	return (0);
}
#endif

#ifdef STRCAT

int main()
{
	printf("ft_strcat: ");
	char d1[30] = "One cat to rule ";
	const char s[] = "them all.";
	char *ret;
	
	//printf("Dest: %s\nsource: %s\n", d1, s);
	ret = ft_strcat(d1, s);
	assert(!strcmp("One cat to rule them all.", ret));
	//printf("ft_strcat: %s\n", ret);
	//printf("Compare addresses of d1 and ret, should match: ");
	assert(d1 == ret);
	//printf("OK\n");
//	printf("Address of d1: %p, ret: %p\n", d1, ret);
	char d2[17] = "One cat to rule ";
	ret = ft_strcat(d2, s);
//	printf("ft_strcat nospace, overflows?: %s\n", ret);
	assert(!strcmp("One cat to rule them all.", ret));
	printf("OK\n");
	return(0);
}
#endif

#ifdef STRNCAT

int main(void)
{
	printf("ft_strncat: ");
	char d1[30] = "One ncat to rule ";
	const char s[] = "them all.";
	char *ret = NULL;

	//printf("Dest: %s\nsource: %s\n", d1, s);
	ret = ft_strncat(d1, s, 4);
	//printf("Testing ft_strcat with n = 4:\n");
	//printf("%s\n", ret);
	//printf("Compare addresses of d1 and ret, should match: ");
	assert(d1 == ret);
	//printf("OK\n");
//	printf("Address of d1: %p, ret: %p\n", d1, ret);
	assert(d1 == ret);
	char d3[30] = "One ncat to rule ";
	//printf("Testing with large n: \n");
	ret = ft_strncat(d3, s, 30);
	assert(!strcmp("One ncat to rule them all.", ret));
	//printf("Output: %s\n", ret);
	char d2[17] = "One cat to rule ";
	ret = ft_strncat(d2, s, 10);
	assert(!strcmp("One cat to rule them all.", ret));
//	printf("ft_strncat nospace, overflows?:\n%s\n", ret);
	printf("OK\n");
	return(0);
}
/*
 * Make strncat compatible
 */
#endif

#ifdef STRLCAT
int main(void)
{
	printf("ft_strlcat: ");
	char d1[30] = "One lcat to rule ";
	char d2[30] = "One lcat to rule ";
	char d3[17] = "One lcat to rule ";
	char d4[30] = "One lcat to rule ";
	char ft_d1[30] = "One lcat to rule ";
	char ft_d2[30] = "One lcat to rule ";
	char ft_d3[17] = "One lcat to rule ";
	char ft_d4[30] = "One lcat to rule ";
	const char s[] = "them all.";
	int ret = 0;

	//printf("Dest: %s\nsource: %s\n", d1, s);
	ret = strlcat(d1, s, 4);
	//printf("*dstsize smaller than dst, n = 4*\n");
	//printf("Return strlcat: %d ", ret);
	ret = ft_strlcat(ft_d1, s, 4);
	//printf("Return ft_strlcat: %d\n", ret);
	//printf("strlcat:    %s\nft_strlcat: %s\n", d1, ft_d1);
	assert(!strcmp(d1, ft_d1));
	//printf("*Testing with large n* \n");
	ret = strlcat(d2, s, 30); //printf("Return strcat: %d ", ret);
	ret = ft_strlcat(ft_d2, s, 30);
	//printf("Return ft_strcat: %d\n", ret);
	//printf("strlcat:    %s\nft_strlcat: %s\n", d2, ft_d2);
	assert(!strcmp(d2, ft_d2));
//	ret = strlcat(d3, s, 17);
//	//printf("*Destination too small*\n");
//	//printf("Return strcat: %d ", ret);
//	ret = ft_strlcat(ft_d3, s, 17);
//	//printf("ft_strlcat: %d\n", ret);
//	//printf("strlcat:    %s\nft_strlcat: %s\n", d3, ft_d3);
	assert(!strcmp(d3, ft_d3));
	ret = strlcat(d4, s, 0);
	//printf("*With dstsizen = 0*\n");
	//printf("Return strlcat: %d ", ret);
	ret = ft_strlcat(ft_d4, s, 0);
	//printf("Return ft_strlcat: %d\n", ret);
	//printf("strlcat:    %s\nft_strlcat: %s\n", d4, ft_d4);
	assert(!strcmp(d4, ft_d4));
	printf("OK\n");
	return(0);
}
#endif

#ifdef STRCHR
int main()
{
	printf("ft_strchar: ");
	const char d1[] = "I know that i don't Know anything.";
	int c = 'i';
	char *ret;
	char *ft_ret = NULL;

	//printf("Input: %s\n", d1);
	ret = strchr(d1, c);
	ft_ret = ft_strchr(d1, c);
	//printf("* Finding '%c' *\n", (char)c);
	//printf("Return strchr: %c. Return of ft_strchr: %c\n", *ret, *ft_ret);
	//printf("Address of strchr: %p. Address of ft_strchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = 'K';
	ret = strchr(d1, c);
	ft_ret = ft_strchr(d1, c);
	//printf("* Finding '%c' *\n", c);
	//printf("Return strchr: %c. Return of ft_strchr: %c\n", *ret, *ft_ret);
	//printf("Address of strchr: %p. Address of ft_strchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = 'I';
	ret = strchr(d1, c);
	ft_ret = ft_strchr(d1, c);
	//printf("* Finding '%c' *\n", c);
	//printf("Return strchr: %c. Return of ft_strchr: %c\n", *ret, *ft_ret);
	//printf("Address of strchr: %p. Address of ft_strchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = '\0';
	ret = strchr(d1, c);
	ft_ret = ft_strchr(d1, c);
	//printf("* Finding '%c' *\n", c);
	//printf("Return strchr: %c Return of ft_strchr: %c\n", *ret, *ft_ret);
	//printf("Address of strchr: %p. Address of ft_strchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = 'G';
	ret = strchr(d1, c);
	ft_ret = ft_strchr(d1, c);
	//printf("* Finding '%c', should'nt find it. *\n", c);
	//printf("Return strchr: %c. Return of ft_strchr: %c\n", *ret, *ft_ret);
	//printf("Address of strchr: %p. Address of ft_strchr: %p.\n", ret, ft_ret);
	//assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = ' ';
	ret = strchr(d1, c);
	ft_ret = ft_strchr(d1, c);
	//printf("* Finding '%c' *\n", c);
	//printf("Return strchr: %c Return of ft_strchr: %c\n", *ret, *ft_ret);
	//printf("Address of strchr: %p. Address of ft_strchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	printf("OK\n");
	return(0);
}
#endif

#ifdef STRRCHR
int main()
{
	printf("ft_strrchar: ");
	const char d1[] = "I know that i don't Know.";
	int c = 'i';
	char *ret;
//	char delete = 'z';
	char *ft_ret = NULL;
	
	//printf("Input: %s\n", d1);
	ret = strrchr(d1, c);
	ft_ret = ft_strrchr(d1, c);
	//printf("* Finding '%c' *\n", (char)c);
	//printf("Return strrchr: %c Return of ft_strrchr: %c\n", *ret, *ft_ret);
	//printf("Address of strrchr: %p. Address of ft_strrchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = 'K';
	ret = strrchr(d1, c);
	ft_ret = ft_strrchr(d1, c);
	//printf("* Finding '%c' *\n", c);
	//printf("Return strrchr: %c. Return of ft_strrchr: %c\n", *ret, *ft_ret);
	//printf("Address of strrchr: %p. Address of ft_strrchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = 'I';
	ret = strrchr(d1, c);
	ft_ret = ft_strrchr(d1, c);
	//printf("* Finding '%c' *\n", c);
	//printf("Return strrchr: %c. Return of ft_strrchr: %c\n", *ret, *ft_ret);
	//printf("Address of strrchr: %p. Address of ft_strrchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = '\0';
	ret = strrchr(d1, c);
	ft_ret = ft_strrchr(d1, c);
	//printf("* Finding '%c' a.k.a NULL *\n", c);
	//printf("Return strrchr: %c Return of ft_strrchr: %c\n", *ret, *ft_ret);
	//printf("Address of strrchr: %p. Address of ft_strrchr: %p.\n", ret, ft_ret);
	assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	c = 'G';
	ret = strrchr(d1, c);
	ft_ret = ft_strrchr(d1, c);
	//printf("* Finding '%c', should'nt find it. *\n", c);
	//printf("Return strrchr: %c. Return of ft_strrchr: %c\n", *ret, *ft_ret);
	//printf("Address of strrchr: %p. Address of ft_strrchr: %p.\n", ret, ft_ret);
	//assert(!strcmp(ret, ft_ret));
	assert(ret == ft_ret);
	printf("OK\n");
	return(0);
}
#endif

#ifdef STRCMP
int main(void)
{
	printf("ft_strcmp: ");
//	char *s1 = "What is fun, is fun, indeed";
	const char *s2 = "Hello underworld";
	char n2[] = "Hello underworld\n";
	int res;
	int ft_res;
	
//	printf("* Testing matching strings *\n");
	res = strcmp(s2, n2);
	ft_res = ft_strcmp(s2, n2);
//	printf("strcmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
//	printf("* Testing unmatching strings *\n");
	char *ch = "hippo";
//	printf("%s vs %s\n", ch, s2);	
	res = strcmp(s2, ch);
	ft_res = ft_strcmp(s2, ch);
//	printf("strcmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
//	printf("* Testing unmatching strings *\n");
	char *ch1 = "Hello ";
//	printf("%s vs %s\n", ch1, s2);	
	res = strcmp(s2, ch1);
	ft_res = ft_strcmp(s2, ch1);
//	printf("strcmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
//	printf("* Testing unmatching strings *\n");
//	printf("%s vs space\n", s2);	
	res = strcmp(s2, " ");
	ft_res = ft_strcmp(s2, " ");
//	printf("strcmp:    %d\nft_strcmp: %d", res, ft_res);
	assert(res == ft_res);
	printf("OK\n");
	return (0);
}
#endif

#ifdef STRNCMP
int main(void)
{
	printf("ft_strncmp: ");
	const char *s2 = "Hello underworld";
	char n2[] = "Hello underworld";
	int res;
	int ft_res;
	int n = 7;
	
//	printf("* Testing matching strings with n: %d*\n", n);
	res = strncmp(s2, n2, n);
	ft_res = ft_strncmp(s2, n2, n);
//	printf("strncmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
//	printf("* Testing unmatching strings *\n");
	char *ch = "hippo";
//	printf("%s vs %s\n", ch, s2);	
	res = strncmp(s2, ch, n);
	ft_res = ft_strncmp(s2, ch, n);
//	printf("strncmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
//	printf("* Testing unmatching strings *\n");
	n = 10;
	char *ch1 = "Hello  ";
//	printf("%s vs %s\n", ch1, s2);	
	res = strncmp(s2, ch1, n);
	ft_res = ft_strncmp(s2, ch1, n);
//	printf("strncmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
//	printf("* Testing unmatching strings *\n");
//	printf("%s vs Space\n", s2);
	const char c = ' ';	
	const char *c_ptr = &c;
	res = strncmp(s2, c_ptr, n);
	ft_res = ft_strncmp(s2, c_ptr, n);
//	printf("strncmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
	n = 100;
//	printf("* Testing matching strings with large n: %d *\n", n);
	res = strncmp(s2, n2, n);
	ft_res = ft_strncmp(s2, n2, n);
//	printf("strncmp:    %d\nft_strcmp: %d\n", res, ft_res);
	assert(res == ft_res);
	printf("OK\n");
	return (0);
}
#endif
#ifdef STRSTR
int main(void)
{
	printf("ft_strstr: ");
	const char *haystack = "What is fun, is fun, period";
	char *needle = "is";
	char *res;
	char *ft_res;
	
//	printf("*  finding '%s' from '%s'  *\n", needle, haystack);
	res = strstr(haystack, needle);
	ft_res = ft_strstr(haystack, needle);
//	printf("strstr:    %s\nft_strstr: %s\n", res, ft_res);
	assert(!strcmp(res, ft_res));
//	printf("*  finding '%s' from '%s'  *\n", haystack, needle);
	res = strstr(needle, haystack);
	ft_res = ft_strstr(needle, haystack);
//	printf("strstr:    %s\nft_strstr: %s\n", res, ft_res);
	assert(res == ft_res);
	char *needle_1 = "What is fun, is fun, period";	
	needle = needle_1;
//	printf("*  finding '%s' from '%s'  *\n", needle, haystack);
	res = strstr(haystack, needle);
	ft_res = ft_strstr(haystack, needle);
//	printf("strstr:    %s\nft_strstr: %s\n", res, ft_res);
	assert(!strcmp(res, ft_res));
	res = strstr("Hello Hellou", "Hellou");
	ft_res = ft_strstr("Hello Hellou", "Hellou");
	assert(!strcmp(res, ft_res));
	
	char c = ASCII_MIN;
	needle = &c;
	while(c <= ASCII_MAX)
	{
		if(*haystack == 27)
			++c;
		res = strstr(haystack, needle);
		ft_res = ft_strstr(haystack, needle);
		assert(res == ft_res);
	/*//	printf("Line nb: %d  *   Haystack: %s *  *  Needle: %s  *  *\n", c, haystack, needle);
	//	printf("strstr:    %s\n", res);
	//	printf("ft_strstr: %s\n", ft_res);
	*/	++c;
	}
	
	printf("OK\n");
	return (0);
}
#endif
#ifdef STRNSTR
// Is not standard library so won't work when testing from home
int g_no_error = 1;

void test_print(char *o_res, char *you_res)
{
	
	if ((o_res != NULL && you_res != NULL) && strcmp(o_res, you_res))
	{
		g_no_error = 0;
		printf("\tOriginal: %s\n\tYours:    %s\n\n", o_res, you_res);
	}
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("Address original: %p\nAddress yours:    %p\n", o_res, you_res);
	}
	return ;
}

int main(void)
{
	printf("ft_strnstr: ");
	const char *haystack = "What is fun, is fun, period";
	char *needle = "is";
//	char *res;
//	char *ft_res;
	int n = 2;
//	int test_nb = 0;
	
	//1. Should return NULL, n too short to find needle
//	printf("%d.\n", ++test_nb);
//	printf("* Haystack: %s\n* Needle: %s\n* n: %d\n", haystack, needle, n);
	test_print(strnstr(haystack, needle, n), ft_strnstr(haystack, needle, n));
	//2. Testing with n just long enough
//	printf("%d.\n", ++test_nb);
	n = 7;
//	printf("* Haystack: %s\n* Needle: %s\n* n: %d\n", haystack, needle, n);
	test_print(strnstr(haystack, needle, n), ft_strnstr(haystack, needle, n));
	//3. Test haystack agains haystack
	n = strlen(haystack);
//	printf("%d.\n", ++test_nb);
//	printf("* Haystack: %s\n* Needle: %s\n* n: %d\n", haystack, haystack, n);
	test_print(strnstr(haystack, haystack, n), ft_strnstr(haystack, haystack, n));
	//4. Test finding haystack from needle
//	printf("%d.\n", ++test_nb);
	n = 7;
//	printf("* Haystack: %s\n* Needle: %s \n* n: %d\n", needle, haystack, n);
	test_print(strnstr(needle, haystack, n), ft_strnstr(needle, haystack, n));
	//5. Test empty needle, should return haystack
//	printf("%d.\n", ++test_nb);
	char *c = "";
	needle = c;	
	n = strlen(haystack);
//	printf("* Haystack: %s\n* Needle: %s \n* n: %d\n", haystack, needle, n);
	test_print(strnstr(haystack, needle, n), ft_strnstr(haystack, needle, n));
	//6. Test n = 0
//	printf("%d.\n", ++test_nb);
	needle = "is";	
	n = 0;
//	printf("* Haystack: %s\n* Needle: %s \n* n: %d\n", haystack, needle, n);
	test_print(strnstr(haystack, needle, n), ft_strnstr(haystack, needle, n));
	//7. Overflow with unmatching needle
//	printf("%d.\n", ++test_nb);
	n = strlen(haystack) + 10;
	needle = "can't find this";
//	printf("* Haystack: %s\n* Needle: %s\n* n: %d\n", haystack, needle, n);
	test_print(strnstr(haystack, needle, n), ft_strnstr(haystack, needle, n));

	//8
//	printf("%d.\n", ++test_nb);
	haystack = "Hello Hellou";
	needle = "Hellou";
	n = strlen(haystack);
//	printf("* Haystack: %s\n* Needle: %s\n* n: %d\n", haystack, needle, n);
	test_print(strnstr(haystack, needle, n), ft_strnstr(haystack, needle, n));
	if (g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef ISALPHA
int g_no_error = 1;
void test_alpha(int c)
{
	int o_res = isalpha(c);
	int you_res = ft_isalpha(c);
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("%d.\n\tOriginal: %d\n\tYours:    %d\n\n", c, o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (c <= 127)
	return ;
}
int main(void)
{
	printf("ft_isalpha: ");
	int c = 0;
	//Test all ascii 0-300, prints only failures after 127	
	while (c < 300)
		test_alpha(c++);
	//Test negative
	c = -1;
	while (c >= -12)
		test_alpha(c--);
	//Test NULL
	test_alpha('\0');
	if (g_no_error)
		printf("OK\n");
}
#endif
#ifdef ISDIGIT
int g_no_error = 1;

void test_isdigit(int c)
{
	int o_res = isdigit(c);
	int you_res = ft_isdigit(c);
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("Char: %c\n\tOriginal: %d\n\tYours:    %d\n\n", (char)c, o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");		
	}	
	return ;
}
int main(void)
{
	printf("ft_isdigit: ");
	int c = '0';

	//Test from '0' to '9'
	while (c <= '9')
		test_isdigit(c++);
	//Test ASCII
	c = 0;
	while (c <= 127)
		test_isdigit(c++);
	//Test NULL
	test_isdigit('\0');
	//Test negativ
	c = -1;
	while (c >= -12)
		test_isdigit(c--);
	if(g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef ISALNUM
int g_no_error = 1;

void test_isdigit(int c)
{
	int o_res = isalnum(c);
	int you_res = ft_isalnum(c);
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("Char: %c\n\tOriginal: %d\n\tYours:    %d\n\n", c, o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (c <= 127)	
//		printf("Char: %c\n\tOriginal: %d\n\tYours:    %d\n\n", c, o_res, you_res);
	return ;
}
int main(void)
{
	printf("ft_isalnum: ");
	int c = 0;

	//Test ASCII
	while (c <= 200)
		test_isdigit(c++);
	//Test NULL
	test_isdigit('\0');
	//Test negativ
	c = -1;
	while (c >= -12)
		test_isdigit(c--);
	if (g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef ISASCII
int g_no_error = 1;

void test_isascii(int c)
{
	int o_res = isascii(c);
	int you_res = ft_isascii(c);
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("Char: %c\n\tOriginal: %d\n\tYours:    %d\n\n", c, o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (c <= 127)	
//		printf("Char: %c\n\tOriginal: %d\n\tYours:    %d\n\n", c, o_res, you_res);
	return ;
}
int main(void)
{
	printf("ft_isascii: ");
	int c = 0;

	//Test ASCII and more
	while (c <= 200)
		test_isascii(c++);
	//Test NULL
	test_isascii('\0');
	//Test negativ
	c = -1;
	while (c >= -12)
		test_isascii(c--);
	if (g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef ISPRINT
int g_no_error = 1;

void test_isprint(int c)
{
	int o_res = isprint(c);
	int you_res = ft_isprint(c);
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("Char: %c\n\tOriginal: %d\n\tYours:    %d\n\n", c, o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (c <= 127)	
//		printf("Char: %c\n\tOriginal: %d\n\tYours:    %d\n\n", c, o_res, you_res);
	return ;
}
int main(void)
{
	printf("ft_isprint: ");
	int c = 0;

	//Test ASCII and more
	while (c <= 200)
		test_isprint(c++);
	//Test NULL
	test_isprint('\0');
	//Test negativ
	c = -1;
	while (c >= -12)
		test_isprint(c--);
	if(g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef TOUPPER
int g_no_error = 1;

void test_toupper(int c)
{
	int o_res = toupper(c);
	int you_res = ft_toupper(c);
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("Char: %c\n\tOriginal: %c\n\tYours:    %c\n\n", c, o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (c <= 127)	
//		printf("Char: %c\n\tOriginal: %c\n\tYours:    %c\n\n", c, o_res, you_res);
	return ;
}
int main(void)
{
	printf("ft_toupper: ");
	int c = 0;

	//Test ASCII and more
	while (c <= 200)
		test_toupper(c++);
	//Test NULL
	test_toupper('\0');
	//Test negativ
	c = -1;
	while (c >= -12)
		test_toupper(c--);
	if (g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef TOLOWER
int g_no_error = 1;

void test_tolower(int c)
{
	int o_res = tolower(c);
	int you_res = ft_tolower(c);
	if (o_res != you_res)
	{
		g_no_error = 0;
		printf("Char: %c\n\tOriginal: %c\n\tYours:    %c\n\n", c, o_res, you_res);
	}
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
//	if (c <= 127)	
	return ;
}
int main(void)
{
	printf("ft_tolower: ");
	int c = 0;

	//Test ASCII and more
	while (c <= 200)
		test_tolower(c++);
	//Test NULL
	test_tolower('\0');
	//Test negativ
	c = -1;
	while (c >= -12)
		test_tolower(c--);
	if (g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef MEMSET
int g_testnb = 1;
int g_no_error = 1;

void char_test_memset(void *s1, void *s2, int c, size_t n)
{
//	printf("Test: %d\n", g_testnb++);
	char *o_res = (char *)memset(s1, c, n);
	char *you_res = (char *)ft_memset(s2, c, n);
	if (strcmp(o_res, you_res))
	{
		g_no_error = 0;
		printf("\tOriginal: %s\n\tYours:    %s\n\n", o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (o_res != you_res)
//		printf("* * * *ERROR: original function and your function have different address");
	return ;
}
void int_test_memset(void *s1, void *s2, int c, size_t n, int len)
{
//	printf("Test: %d\n", g_testnb++);
	int *o_res = (int *)memset(s1, c, n);
	int *you_res = (int *)ft_memset(s2, c, n);
	int i = 0;

//	if (o_res != you_res)
//	printf("* * * *ERROR: original function and your function have different address");
	while (i < len)
	{
		if (o_res[i] != you_res[i])
		{
			g_no_error = 0;
			printf("\tOriginal: %d\n\tYours:    %d\n\n", o_res[i], you_res[i]);
		}
//			printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	++i;
	}
	return ;
}

	
int main(void)
{
	printf("ft_memset: ");
	//int c = 48;
	char a1[] = "Kekkonen fished and Kekkonen skied";
	int nb1[] = {0, 1, 2, 3, 4, 5, 6};
	char a2[] = "Kekkonen fished and Kekkonen skied";
	int nb2[] = {0, 1, 2, 3, 4, 5, 6};
//	void *avoid = "Dont know";
	//First letter should be changed to a
	char_test_memset(a1, a2, 'a', 3);
	//Test with exacti size, sometimes weird behaviour because NULL is overwritten.
	char_test_memset(a1, a2, 'z', sizeof(a1) - 1);
	//Should fill up to nb 3 with 0 (4 bytes)
	int_test_memset(nb1, nb2, 0, 4 * sizeof(int), 7);
	//Should fill up to nb 1 with -1
	int_test_memset(nb1, nb2, -1, 4, 7);
	if (g_no_error)
		printf("OK\n");
	
//Test NULL segfaults
//	input = NULL;
//	memset(input, 42, 4);
//	void *input segfaults
//	input = avoid;
//	memset(input, 'a', 1);
	return (0);
}
#endif
#ifdef BZERO
int g_testnb = 1;
int g_no_error = 1;

void char_test_bzero(void *s1, void *s2, size_t n)
{
//	printf("Test: %d\n", g_testnb++);
	char *o_res = (char *)s1;
	char *you_res = (char *)s2;
	bzero(s1, n);
	ft_bzero(s2, n);
	if (strcmp(o_res, you_res))
	{
		g_no_error = 0;
		printf("\tOriginal: %s\n\tYours:    %s\n\n", o_res, you_res);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (o_res != you_res)
//		printf("* * * *ERROR: original function and your function have different address");
//	o_res += n;
//	you_res += n;
//	printf("\tOriginal: %s\n\tYours:    %s\n\n", o_res, you_res);
	return ;
}
void int_test_bzero(void *s1, void *s2, size_t n, int len)
{
//	printf("Test: %d\n", g_testnb++);
	int *o_res = (int *)s1;
	int *you_res = (int *)s2;
	bzero(s1, n);
	ft_bzero(s2, n);
	int i = 0;

//	if (o_res != you_res)
//	printf("* * * *ERROR: original function and your function have different address");
	while (i < len)
	{
		if (o_res[i] != you_res[i])
		{
			g_no_error = 0;
			printf("\tOriginal: %d\n\tYours:    %d\n\n", o_res[i], you_res[i]);
//			printf("* * * *ERROR: original functions return differs from yours* * * *\n");
		}
	++i;
	}
	return ;
}

int main(void)
{
	printf("ft_bzero: ");
	//int c = 48;
	char a1[] = "Kekkonen fished and Kekkonen skied";
	int nb1[] = {0, 1, 2, 3, 4, 5, 6};
	char a2[] = "Kekkonen fished and Kekkonen skied";
	int nb2[] = {0, 1, 2, 3, 4, 5, 6};
//	void *avoid = "Dont know";
	//First 3 letter should be changed to 0
	char_test_bzero(a1, a2, 3);
	//Test with exacti size, sometimes weird behaviour because NULL is overwritten.
	char_test_bzero(a1, a2, sizeof(a1));
	//Should fill up to nb 3 with 0 (4 bytes)
	int_test_bzero(nb1, nb2, 4 * sizeof(int), 7);
	if(g_no_error)
		printf("OK\n");
	
//Test NULL segfaults
//	input = NULL;
//	bzero(input, 42, 4);
//	void *input segfaults
//	input = avoid;
//	bzero(input, 'a', 1);
	return (0);
}
#endif
#ifdef MEMCPY
int g_testnb = 1;
int g_no_error = 1;
/*
void printn(char *s1, size_t n)
{
	size_t i = 0;
	s1 -= 1;
	while (i < n + 2)
		printf("%c", s1[i++]);
	printf("\n");
	}
*/
void char_test_memcpy(void *d1, void *d2, const void *s1, size_t n)
{
//	printf("Test: %d\n", g_testnb++);
	char *o_res = (char *)memcpy(d1, s1, n);
	char *you_res = (char *)ft_memcpy(d2, s1, n);
	if (strcmp(o_res, you_res))
	{
		g_no_error = 0;
		printf("\tOriginal: %s\n\tYours:    %s\n\n", o_res - 1, you_res - 1);
	//	printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (o_res != you_res)
//		printf("* * * *ERROR: original function and your function have different return address\n");
/*	printf("\tOriginal: ");
	printn(o_res, n);
	printf("\tYours:    ");
	printn(you_res, n);
	printf("\n");
*/	return ;
}

int main(void)
{
	printf("ft_memcpy: ");
	//int c = 48;
	const char s1[] = "Kekkonen skied and Kekkonen fished";
//	const char s2[] = "Kekkonen fished and Kekkonen skied";
	char *d1 = (char *)malloc(sizeof(s1) + 2);
	char *d2 = (char *)malloc(sizeof(s1) + 2);
	bzero(d1, sizeof(s1) + 2);
	bzero(d2, sizeof(s1) + 2);
	d1[0] = '*';
	d2[0] = '*';
	//Adding stars before and end of source string to see over/underflow
	d1[sizeof(s1) + 1] = '*';
	d2[sizeof(s1) + 1] = '*';
	//First 3 letter should be copied
	char_test_memcpy(d1 + 1, d2 + 1, s1, 3);
	//Test with exacti size, sometimes weird behaviour because NULL is overwritten.
	char_test_memcpy(d1 + 1, d2 + 1, s1, sizeof(s1));
	//Test overflow, might segfault the free if d1 writes to d2	
	char_test_memcpy(d1 + 1, d2 + 1, s1, sizeof(s1) + 10);
	if(g_no_error)
		printf("OK\n");
	free(d1);
	free(d2);
	return (0);
}
#endif
#ifdef MEMCCPY
void test(char *s, int c, size_t n)
{
	char *orig_dest = (char *)malloc(sizeof(char) * n + 1);
	char *your_dest = (char *)malloc(sizeof(char) * n + 1);
	bzero(orig_dest, n + 1);
	bzero(your_dest, n + 1);
	char *orig_ret;
	char *your_ret;
	int flags = 0; //0000

	orig_ret = memccpy(orig_dest, s, c, n);
	your_ret = ft_memccpy(your_dest, s, c, n);
	if (orig_ret == NULL)
	{
		if (your_ret != NULL)
		{
			printf("FALSE\t");
			printf("Was expecting: %p  got: %p\n", orig_ret, your_ret);
			return ;
		}
		else
		{
			printf("OK    ");
			return ;
		}
	}
	if (strcmp(orig_dest, your_dest))
		flags = flags | 1; // 0001
	if (strcmp(orig_ret, your_ret))
		flags = flags | 2; //0010
	if (flags == 0) //0000
	{
		printf("OK    ");
	//	printf ("\nReturned pointer, was expecting: %s, got: %s", orig_ret, your_ret);
	//	printf ("\nDestination string, was expecting: %s, got: %s", orig_dest, your_dest);
		return ;
	}
	else
		printf("FAIL\t");
	if (flags == 3) //0011;
	{
		printf ("\nReturned pointer, was expecting: %s, got: %s", orig_ret, your_ret);
		printf ("\nDestination string, was expecting: %s, got: %s", orig_dest, your_dest);
		return;
	}	
	if (flags == 2) //0010
	{
		printf ("\nReturned pointer, was expecting: %s, got: %s", orig_ret, your_ret);
		return;
	}
	if (flags == 1) //0001
	{
		printf ("\nDestination string, was expecting: %s, got: %s", orig_dest, your_dest);
		return;
	}
}

int main(void)
{
	printf("ft_memccpy: ");
	test("Kekkonen skied and Kekkonen fished", 'K', 20 );
	test("Kekkonen skied and Kekkonen fished", 'f', 50 );
	test("Kekkonen skied and Kekkonen fished", 'z', 50 );
	test("Kekkonen skied and Kekkonen fishedz", 'z', 50 );
	printf("\n");
	return (0);
}

#endif
#ifdef MEMMOVE
int g_testnb = 1;
int g_no_error = 1;
/*
void printn(char *s1, size_t n)
{
	size_t i = 0;
	s1 -= 1;
	while (i < n + 2)
		printf("%c", s1[i++]);
	printf("\n");
	}
*/
void char_test_memmove(void *d1, void *d2, const void *s1, size_t n)
{
//	printf("Test: %d\n", g_testnb++);
	char *o_res = (char *)memmove(d1, s1, n);
	char *you_res = (char *)ft_memmove(d2, s1, n);
	if (strcmp(o_res, you_res))
	{
		g_no_error = 0;
		printf("\tOriginal: %s\n\tYours:    %s\n\n", o_res - 1, you_res - 1);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
//	if (o_res != you_res)
//		printf("* * * *ERROR: original function and your function have different return address\n");
//	printf("\tOriginal: ");
//	printn(o_res, n);
//	printf("\tYours:    ");
//	printn(you_res, n);
//	printf("\n");
	return ;
}

int main(void)
{
	printf("ft_memmove: ");
	const char s1[] = "Kekkonen skied and Kekkonen fished";
	char *d1 = (char *)malloc(sizeof(s1) + 2);
	char *d2 = (char *)malloc(sizeof(s1) + 2);
	bzero(d1, sizeof(s1) + 2);
	bzero(d2, sizeof(s1) + 2);
	d1[0] = '*';
	d2[0] = '*';
	//Adding stars before and end of source string to see over/underflow
	d1[sizeof(s1) + 1] = '*';
	d2[sizeof(s1) + 1] = '*';
	//First 3 letter should be copied
	char_test_memmove(d1 + 1, d2 + 1, s1, 3);
	//Test with exacti size, sometimes weird behaviour because NULL is overwritten.
	char_test_memmove(d1 + 1, d2 + 1, s1, sizeof(s1));
	//Test overflow, might segfault the free if d1 writes to d2	
	char_test_memmove(d1 + 1, d2 + 1, s1, sizeof(s1) + 10);
	//Test with overlap
	//printf("Test: %d\n", g_testnb++);
	memmove(d1, d1 + 4, sizeof(s1));
	ft_memmove(d2, d2 + 4, sizeof(s1));
	if (strcmp(d1, d2))
	{
		g_no_error = 0;
		printf("\tOriginal: %s\n\tYours:    %s\n\n", d1, d2);
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
	}
	if (g_no_error)
		printf("OK\n");
	free(d1);
//	free(d2);
	return (0);
}
#endif
#ifdef MEMCHR
int g_testnb = 1;
int g_no_error = 1;

void printn(char *s1, size_t n)
{
	size_t i = 0;
	s1 -= 1;
	while (i < n + 2)
		printf("%c", s1[i++]);
	printf("\n");
	}

void char_test_memchr(const void *s1, int c, size_t n)
{
	char *o_res = (char *)memchr(s1, c, n);
	char *you_res = (char *)ft_memchr(s1, c, n);
	if (strcmp(o_res, you_res))
	{
		g_no_error = 0;
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
		printf("\tOriginal: %s\n\tYours:    %s\n\n", o_res - 1, you_res - 1);
	}
	if (o_res != you_res)
	{
		g_no_error = 0;
//		printf("* * * *ERROR: original function and your function have different return address\n");
		printf("\tOriginal: %p\n\tYours:    %p\n\n", o_res - 1, you_res - 1);
	}	
	return ;
}

void char_test_memchr_no_cmp(const void *s1, int c, size_t n)
{
	char *o_res = (char *)memchr(s1, c, n);
	char *you_res = (char *)ft_memchr(s1, c, n);
	if (o_res != you_res)
	{
		g_no_error = 0;
//		printf("* * * *ERROR: original function and your function have different return address\n");
		printf("\tOriginal: %p\n\tYours:    %p\n\n", o_res - 1, o_res - 1);
	}

	return ;
}
int main(void)
{
	printf("ft_memchr: ");
	const char s1[] = "Kekkonen skied and Kekkonen fished";
	char *d1 = (char *)malloc(sizeof(s1) + 2);
	char *d2 = (char *)malloc(sizeof(s1) + 2);
	d1[0] = '*';
	d2[0] = '*';
	//Adding stars before and end of source string to see over/underflow
	d1[sizeof(s1) + 1] = '*';
	d2[sizeof(s1) + 1] = '*';
	//First 10 bytes search
	char_test_memchr(s1, 's', 10);
	//Test with exacti size, sometimes weird behaviour because NULL is overwritten.
	char_test_memchr(s1, '\0', sizeof(s1) + 5);
	//Find something which is not there	
	char_test_memchr_no_cmp(s1, 'z', sizeof(s1));
//	free(d2);
	if (g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef MEMCMP
int g_testnb = 1;
int g_no_error = 1;

void char_test_memcmp(const void *s1, const void *s2, size_t n)
{
//	printf("Test: %d\n", g_testnb++);
	int o_res = memcmp(s1, s2, n);
	int you_res = ft_memcmp(s1, s2, n);
	if (o_res != you_res)
	{
		g_no_error = 0;
//		printf("* * * *ERROR: original functions return differs from yours* * * *\n");
		printf("\tOriginal: %d\n\tYours:    %d\n\n", o_res, you_res);
	}
	return ;
}

int main(void)
{
	printf("ft_memcmp: ");
	const char s1[] = "Kekkonen skied and Kekkonen fished";
	const char s2[] = "Kekkonen skied and Kekkonen fished";
	
	//First 10 bytes search
	char_test_memcmp((const void *)s1, (const void *)s2, 10);
	//Test with exacti size, sometimes weird behaviour because NULL is overwritten.
	char_test_memcmp((const void *)s1, (const void *)s2, sizeof(s1));
	//Find something which is not there	
	char_test_memcmp("Ahtisaari", (const void *)s2, sizeof(s1));
	//Search ending
	char_test_memcmp("hed", (const void *)s2 + sizeof(s1) - 4, 3);
	//Search hed with overflow
	char_test_memcmp("hed", (const void *)s2 + sizeof(s1) - 4, sizeof(s1));
//	free(d2);
	if (g_no_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef ATOI
int main(void)
{
	printf("ft_atoi: ");
	char c = 0;
	int res;
	int you_res;
	const char *ch = &c;
	char *input = malloc(sizeof(*input) * 5);
	int not_error = 1;
	input[2] = '4';
	input[3] = '2';
	input[4] = '\0';

	while ( *ch < 127)
	{
		input[0] = c;
		input[1] = c;
		ch = input;
		res = atoi(ch);
		you_res = ft_atoi(ch);
		if (res != you_res)
		{
			not_error = 0;
			printf("Input: %s, atoi: %d, your ft_atoi: %d\n", ch, res, you_res);
			//printf("* * *Look at me* * *");
		}
		c = c + 1;
	}
	input[1] = '4';
	input[3] = '2';
	input[4] = '\0';
	c = 0;
	ch = &c;
	while ( *ch < 127)
	{
		input[0] = c;
		input[2] = c;
		ch = input;
		res = atoi(ch);
		you_res = ft_atoi(ch);
		if (res != you_res)
		{
			not_error = 0;
			printf("Input: %s, atoi: %d, your ft_atoi: %d\n", ch, res, you_res);
			//printf("* * *Look at me* * *");
		}
		c = c + 1;
	}
	char *pm = "+-42";
	char *mp = "-+42";
	char *tp = "\t +42";
	res = atoi(pm);
	you_res = ft_atoi(pm);
	if (res != you_res)
	{
		not_error = 0;
		printf("Input: %s, atoi: %d, your ft_atoi: %d\n", ch, res, you_res);
//		printf("* * *Look at me* * *");
	}
	res = atoi(mp);
	you_res = ft_atoi(mp);
	if (res != you_res)
	{	
		not_error = 0;
		printf("Input: %s, atoi: %d, your ft_atoi: %d\n", ch, res, you_res);
//		printf("* * *Look at me* * *");
	}
	res = atoi(tp);
	you_res = ft_atoi(tp);
	if (res != you_res)
	{
		not_error = 0;
		printf("Input: %s, atoi: %d, your ft_atoi: %d\n", ch, res, you_res);
//		printf("* * *Look at me* * *");
	}
	if (not_error)
		printf("OK\n");
	return (0);
}
#endif
#ifdef MEMALLOC
int main(void)
{
	printf("ft_memalloc: ");
	char *res;
	size_t size = 5;
	size_t n = 0;
	int error = 0;

	res = (char *)ft_memalloc(size);
	while(n < size)
	{
		if(res[n] != 0)
		{
			printf("Index: %ld. Expected 0 got :%d\n", n, res[n]);
			error = 1;
		}
		++n;
	}
	if (!error)
		printf ("OK\n");
	free (res);
	return (0);
}
/* Should allocate space for 16 bytes not 16 INT or LONG int or waeva
 * Malloc fail check
 * Test should print only 0
 */ 
#endif
#ifdef MEMDEL
int main(void)
{
	printf("ft_memdel: ");
//	struct mallinfo2 before, after;
//	before = mallinfo2();
	void *ptr = malloc(sizeof(char) * 16);
//	after = mallinfo2();
//	printf("Address before function call: %p\n", ptr);
	ft_memdel (&ptr);
//	int mem = before.uordblks - after.uordblks;
	if (ptr != NULL)
		printf("Was expecting NULL got: %p\n", ptr);
	else
		printf("OK\n");
	return (0);
}
#endif
#ifdef STRNEW
int main(void)
{
	printf("ft_strnew: ");
	char *res = ft_strnew(5);

	strcpy(res, "funny");
	if (strcmp("funny", res))
		printf("Was expecting: funny, got %s\n", res);
	else
		printf("OK\n");
	free(res);
	return (0);
	}
#endif
#ifdef STRDEL 
int main(void)
{
	printf("ft_strdel: ");
//	struct mallinfo2 beore, after;
//	before = mallinfo2();
	char *ptr = malloc(sizeof(char) * 16);
//	after = mallinfo2();
	ft_strdel(&ptr);
//	int mem = before.uordblks - after.uordblks;
	if (ptr != NULL)
		printf("Was expecting NULL got: %p\n", ptr);
	else
		printf("OK\n");
	return (0);
}
#endif
#ifdef STRCLR 
void print(char *a, int n)
{
	int nb = 0;

	while(nb < n && a[nb++] == 0)
		;
	if (nb != n)
		printf("Expected nul on index: %d got: %c\n", n - 1 - nb, a[nb]);
	else
		printf("OK\n");
}
int main(void)
{
	printf("ft_strclr: ");
	char a[] = "A nice giraffe"; 
	int len = strlen(a);
//	printf("before function call: ");
//	print(a, len);
	ft_strclr(a);
//	printf("after function call:");
	print(a, len);
	return (0);
}
#endif
#ifdef STRITER 
void toup(char *c)
{
	int difference = 'a' - 'A';

	if (*c >= 'a' && *c <= 'z')
		*c -= difference;
}

void test(char *s)
{
//	int difference = 'a' - 'A';

	while (*s != '\0' && ((*s >= 'A' && *s <= 'Z') || *s == ' '))
		++s;
	if (*s != '\0')
		printf("Was expecting something else than: %c\n", *s);
	else
		printf("OK\n");
}
int main(void)
{
	printf("ft_striter: ");
	char a[] = "A nice giraffe"; 
//	printf("before function call: %s\n", a);
	ft_striter(a, &toup);
	test(a);
//	printf("after function call: %s\n", a);
	return (0);
}
#endif
#ifdef STRITERI 
void toup_if_first(unsigned int i, char *c)
{
	int difference = 'a' - 'A';

	if (*c >= 'a' && *c <= 'z' && (*c - difference) == *(c - i))
		*c -= difference;
}

int main(void)
{
	printf("ft_striteri: ");
	char a[] = "A nice giraffe"; 
//	printf("before function call:    %s\n", a);
//	printf("small a should be big A: %s\n", a);
//	printf("call with null:\n");
	ft_striteri(NULL, NULL);
	ft_striteri(a, &toup_if_first);
	if (strcmp("A nice girAffe", a))
		printf("Was expecting: A nice girAffe got: %s\n", a);
	else
		printf("OK\n");
	return (0);
}
#endif
#ifdef STRMAP 
char toup(char c)
{
	int difference = 'a' - 'A';

	if (c >= 'a' && c <= 'z')
		c -= difference;
	return (c);
}

void test(char *s1, char *s2)
{
	if (s1 == s2)
		printf("* * *Error input and output have same address * * *");
	return;
}
int main(void)
{
	printf("ft_strmap: ");
	char a[] = "A nice giraffe"; 
	char *res;

//	printf("Input:  %s\n", a);
	res = ft_strmap(a, &toup);
//	printf("Output: %s\n", res);
//	printf("call with null:\n");
	ft_strmap(NULL, NULL);
	test(a, res);
	if (strcmp("A NICE GIRAFFE", res))
		printf("Was expecting: A NICE GIRAFFE got: %s\n", res);
	else
		printf("OK\n");
	free(res);
	return (0);
}
#endif
#ifdef STRMAPI 
char toup_if_first(unsigned int i, char c)
{
	int difference = 'a' - 'A';

	if (c >= 'a' && c <= 'z' && i < 2147483647)
		c -= difference;
	return (c);
}
void test(char *s1, char *s2)
{
	if (s1 == s2)
		printf("* * *Error input and output have same address * * *");
	else if (strcmp("A NICE GIRAFFE", s2))
		printf("Was expecting: A NICE GIRAFFE got: %s\n", s2);
	else
		printf("OK\n");
	return;
}
int main(void)
{
	printf("ft_strmapi: ");
	char *res;
	char a[] = "A nice giraffe"; 
	
//	printf("before function call:    %s\n", a);
	res = ft_strmapi(a, &toup_if_first);
//	printf("small a should be big A: %s\n", res);
//	printf("call with null:\n");
	ft_strmapi(NULL, NULL);
	test(a, res);
	return (0);
}
#endif
#ifdef STREQU 
void test(char *s1, char *s2)
{
	static int nb = 1;
	int res = 0;

	res = ft_strequ(s1, s2);
	if(strcmp(s1, s2) != 0 && res != 0)
		printf("Test %d failed was expecting 0 got: %d\n", nb, res);
	else if(strcmp(s1, s2) == 0 && res != 1)
		printf("Test %d failed was expecting 1 got: %d\n", nb, res);
	else if (nb > 3)
		printf("OK\n");
	else
		++nb;
}
int main(void)
{
	printf("ft_strequ: ");
	char a[] = "A nice giraffe"; 
	char *a2 = " nice";
	char *a3 = "a nice";
	char *s1, *s2;
//	int res = 0;

	s1 = a;
	s2 = a;
//	printf("s1: %s\ns2: %s\n", s1, s2);
//	res = ft_strequ(s1, s2);
	ft_strequ(NULL, NULL);
	test(s1, s2);
//	printf("Function should reuturn 1, it returns: %d\n", res);
	s1 = a;
	s2 = "A nic";
//	printf("s1: %s\ns2: %s\n", s1, s2);
//	res = ft_strequ(s1, s2);
	test(s1, s2);
//	printf("Function should reuturn 0, it returns: %d\n", res);

	s1 = a;
	s2 = a2;
//	printf("s1: %s\ns2: %s\n", s1, s2);
//	res = ft_strequ(s1, s2);
	test(s1, s2);
//	printf("Function should reuturn 0, it returns: %d\n", res);
	s1 = a;
	s2 = a3;
//	printf("s1: %s\ns2: %s\n", s1, s2);
//	res = ft_strequ(s1, s2);
	test(s1, s2);
//	printf("Function should reuturn 0, it returns: %d\n", res);

//	printf("call with null:\n");
//	printf("Function should reuturn 0, it returns: %d\n", res);
	return (0);
}
#endif
#ifdef STRNEQU 
void test(char *s1, char *s2, int len)
{
	static int nb = 1;
	int res = 0;

	res = ft_strnequ(s1, s2, len);
	if(strncmp(s1, s2, len) != 0 && res != 0)
		printf("Test %d failed was expecting 0 got: %d\n", nb, res);
	else if(strncmp(s1, s2, len) == 0 && res != 1)
		printf("Test %d failed was expecting 1 got: %d\n", nb, res);
	else if (nb > 4)
		printf("OK\n");
	else
		++nb;
}
int main(void)
{
	printf("ft_strnequ: ");
	char a[] = "A nice giraffe"; 
	char *a2 = " nice";
	char *a3 = "a nice";
	char *s1, *s2;
//	int res = 0;

	s1 = a;
	s2 = a;
	ft_strnequ(NULL, NULL, 50);
//	printf("s1: %s\ns2: %s\n", s1, s2);
	test(s1, s2, strlen(a) + 1);
//	printf("Function should reuturn 1, it returns: %d\n", res);
	s1 = a;
	s2 = "A nic";
//	printf("s1: %s\ns2: %s\n", s1, s2);
	test(s1, s2, 5);
//	printf("Function should reuturn 1, it returns: %d\n", res);

	s1 = a;
	s2 = a2;
//	printf("s1: %s\ns2: %s\n", s1, s2);
	test(s1, s2, 7);
//	printf("Function should reuturn 0, it returns: %d\n", res);
	s1 = a;
	s2 = a3;
//	printf("s1: %s\ns2: %s\n", s1, s2);
	test(s1, s2, 100);
//	printf("Function should reuturn 0, it returns: %d\n", res);
	s1 = a;
	s2 = "giraffe";
//	printf("s1: %s\ns2: %s\n", s1, s2);
	test(s1, s2, 100);
//	printf("Function should reuturn 0, it returns: %d\n", res);
//	printf("call with null:\n");
//	printf("Function should reuturn 0, it returns: %d\n", res);
	return (0);
}
#endif
#ifdef STRSUB 
int main(void)
{
	printf("ft_strsub: ");
	char a[] = "A nice giraffe"; 
	char *res;
	int nb = 1;

	res = ft_strsub(a, 2, 4);
	if (strcmp("nice", res))
		printf("Test %d. Should return: nice, returns: %s\n", nb, res);
	else
		++nb;
	res = ft_strsub(a, 2, 0);
	if (strcmp("", res))
		printf("Test %d. Should return:, returns: %s\n",nb, res);
	else
		++nb;
	res = ft_strsub(a, 0, 14);
	if (strcmp("A nice giraffe", res))
		printf("Test %d. Should return: A nice giraffe, returns: %s\n", nb, res);
	else
		++nb;
	//printf("Testing NULL\n");
	res = ft_strsub(NULL, 5, 50);
	if (nb > 2)
		printf ("OK\n");
	return (0);
}
#endif
#ifdef STRJOIN 
int main(void)
{
	printf("ft_strjoin: ");
	char a[] = "Urho kal";
	char *a2 = "eva Kekkonen";
	char *res;

//	printf("Concatenating words; '%s' and '%s'\n", a, a2);
	res = ft_strjoin(a, a2);
	assert(!strcmp("Urho kaleva Kekkonen", res));
//	printf("Result: %s\n", res);
//	printf("Testing NULL\n");
	res = ft_strjoin(NULL, NULL);
	printf("OK\n");
	return (0);
}
#endif
#ifdef STRTRIM 
/*
void test_matching(char *a, char *res)
{
	if (strcmp(a, res))
		printf("* * * ERROR: should return input\n");
	if (a != res)
		printf("* * * ERROR: expecting same address for output and input * * *\n");
	printf("\n");
}
void test_unmatching(char *a, char *res)
{
	if (!strcmp(a, res))
		printf("* * * ERROR: input and output do match\n");
	if (a == res)
		printf("* * * ERROR: expecting different address for output and input * * *\n");
	printf("\n");
}
*/
int main(void)
{
	printf("ft_strtrim: ");
	char a1[] = "";
	char *a2 = "@ ^!Macaroni without\tcheese?";
	char *a3 = " \t\nWhat is zero what is NULL?";
	char *a4 = "What is zero what is NULL? \t\n";
	char *a5 = NULL;
	char *a6 = " \t\nWhat is zero\b what is NULL? \t\n";
	char *a7 = " \t\t  ";
	char *a8 = " a";
	char *a9 = "a ";
	char *a10= " ";
	char *res;

//	printf("Input:  '%s'\n", a1);
	res = ft_strtrim(a1);
//	printf("Output: '%s'\n", res);
//	test_matching(a1, res);
	assert(!strcmp(a1, res));
//	printf("Input:  '%s'\n", a2);
	res = ft_strtrim(a2);
//	printf("Output: '%s'\n", res);
//	test_matching(a2, res);
	assert(!strcmp(a2, res));
//	printf("Input:  '%s'\n", a3);
	res = ft_strtrim(a3);
//	printf("Output: '%s'\n", res);
//	test_unmatching(a3, res);
	assert(strcmp(a3, res));
//	printf("Input:  '%s'\n", a4);
	res = ft_strtrim(a4);
//	printf("Output: '%s'\n", res);
//	test_unmatching(a4, res);
	assert(strcmp(a4, res));
//	printf("Input:  '%s'\n", a5);
	res = ft_strtrim(a5);
//	printf("Output: '%s'\n", res);
//	if (res != a5)
//		printf("* * * ERROR: expecting same address for output and input * * *\n");
	assert(a5 == res);
//	printf("\n");
//	printf("Input:  '%s'\n", a6);
	res = ft_strtrim(a6);
//	printf("Output: '%s'\n", res);
//	test_unmatching(a6, res);
	assert(strcmp(a6, res));
//	printf("Input:  '%s'\n", a7);
	res = ft_strtrim(a7);
//	printf("Output: '%s'\n", res);
//	test_unmatching(a7, res);
	assert(strcmp(a7, res));
//	printf("Input:  '%s'\n", a8);
	res = ft_strtrim(a8);
//	printf("Output: '%s'\n", res);
//	test_unmatching(a8, res);
	assert(strcmp(a8, res));
//	printf("Input:  '%s'\n", a9);
	res = ft_strtrim(a9);
//	printf("Output: '%s'\n", res);
//	test_unmatching(a9, res);
	assert(strcmp(a9, res));
//	printf("Input:  '%s'\n", a10);
	res = ft_strtrim(a10);
//	printf("Output: '%s'\n", res);
//	test_unmatching(a10, res);
	assert(strcmp(a10, res));
//	printf("Testing NULL\n");
	res = ft_strtrim(NULL);
	free(res);
	printf("OK\n");
	return (0);
}
#endif
#ifdef STRSPLIT

#include "Unity/unity.h"
#include "Unity/unity.c"
#include "Unity/unity_internals.h"

int g_counter = 0;
void setUp(void){
}

void tearDown(void) {
}
/*
void print_split(char **res)
{
	printf("Test: %d\n", ++g_counter);
	if(res == NULL)
	{
		//printf("NULL returned\n\n");
		return ;
	}
	while(*res)
		printf("%s\n", *res++);
	printf("\n");
}
*/
void test_correct_array(void)
{
	char **res;
	res = ft_strsplit("*Is*this*planet*earth*", '*');
	char *correct[5] = {"Is", "this", "planet", "earth", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 5);
	
	res = ft_strsplit("Is this planet earth", ' ');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 5);

	res = ft_strsplit("****Is*this****planet*earth", '*');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 5);
}
void test_return_input(void)
{
	char **res;
	char *correct[2] = {"*Is*this*planet*earth*", NULL};
	res = ft_strsplit("*Is*this*planet*earth*", '$');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 2);

	res = ft_strsplit("*Is*this*planet*earth*", '\0');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 2);
}
void test_hello(void)
{
	char **res;
	char *correct[2] = {"Hello", NULL};
	res = ft_strsplit("*Hello*", '*');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 2);

	res = ft_strsplit("*Hello", '*');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 2);

	res = ft_strsplit("Hello*", '*');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 2);

	res = ft_strsplit("         Hello", ' ');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 2);

	res = ft_strsplit("Hello              ", ' ');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 2);
}
void test_with_null(void)
{
	char **res;
	res = ft_strsplit(NULL, '*');
	TEST_ASSERT_NULL(res);
}
void test_extra_case(void)
{
	char **res;
	char *correct[11] = {"Happy", "boy", "is", "taking", "a", "walk", "with", "a", "laughing", "dog.", NULL};
	char *s = "Happy boy is taking a walk with a laughing dog.";
	res = ft_strsplit(s, ' ');
	TEST_ASSERT_EQUAL_STRING_ARRAY(correct, res, 11);
}

int main(void)
{
	//Maybe do test file for evaluations
	//Test with NULL input
	//Test with unmatching delimiter
	//Test finding \0
	//Test with multiple delimiters
	//Test delimiter word \0 pattern
	//1
	UNITY_BEGIN();
	RUN_TEST(test_correct_array);
	RUN_TEST(test_return_input);
	RUN_TEST(test_hello);
	RUN_TEST(test_with_null);
	RUN_TEST(test_extra_case);
	return UNITY_END();
	//print_split(res);
	//2
	//print_split(res);
	//3
//	print_split(res);
	//4
//	print_split(res);
	//5
//	print_split(res);
	//6
//	res = ft_strsplit("   *  Is*this**   ***planet *earth*", '*');
//	print_split(res);
	//7
//	print_split(res);
	//8
//	print_split(res);
	//9
//	print_split(res);
	//10
//	print_split(res);
	//11
//	print_split(res);
	//12
//	print_split(res);
	//13
	//printf("%s\n", res[0]);
//	print_split(res);
	return (0);
}
#endif
#ifdef ITOA
int main(void)
{
	printf("ft_itao: ");
	char *res;
	int nb = 1;

	res = ft_itoa(nb);
	assert(!strcmp("1", res));
	//printf("%s\n", res);
	nb = -1;
	res = ft_itoa(nb);
	assert(!strcmp("-1", res));
	//printf("%s\n", res);
	nb = INT_MAX;
	res = ft_itoa(nb);
	assert(!strcmp("2147483647", res));
//	printf("%s\n", res);
	nb = INT_MIN;
	res = ft_itoa(nb);
	assert(!strcmp("-2147483648", res));
//	printf("%s\n", res);
	nb = 0;
	res = ft_itoa(nb);
	assert(!strcmp("0", res));
//	printf("%s\n", res);
	printf("OK\n");	
	return (0);
}
#endif
#ifdef PUTCHAR
int main(void)
{
	ft_putchar('x');
	ft_putchar('\n');
	ft_putchar('\0');
	ft_putchar('\n');
	return (0);
}
#endif
#ifdef PUTSTR
int main(void)
{
	ft_putstr("Nice to meet, World\n");
	ft_putstr("\0\n");
	return (0);
}
#endif
#ifdef PUTENDL
int main(void)
{
	ft_putendl("Is there an end?");
	return (0);
}
#endif
#ifdef PUTNBR
int main(void)
{
	int nb = -9;
	
	while (nb <= 9)
	{
		ft_putnbr(nb++);
		ft_putchar('\n');
	}
	ft_putnbr(INT_MIN);
	ft_putchar ('\n');
	ft_putnbr(INT_MAX);
	ft_putchar ('\n');
	ft_putnbr(42);
	ft_putchar ('\n');
	ft_putnbr(-42);
	ft_putchar ('\n');
	return (0);
}
#endif
#ifdef PUTCHAR_FD
int main(void)
{
	ft_putchar_fd('z', 1);
	printf("\n");
	return (0);
}
#endif
#ifdef PUTSTR_FD
int main(void)
{
	ft_putstr_fd("A string\n", 1);
	return (0);
}
#endif
#ifdef PUTENDL_FD
int main(void)
{
	ft_putendl_fd("The end is near.", 1);
}
#endif
#ifdef PUTNBR_FD
int main(void)
{
	int nb = -9;
	
	while (nb <= 9)
	{
		ft_putnbr_fd(nb++, 1);
		ft_putchar('\n');
	}
	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar ('\n');
	ft_putnbr_fd(INT_MAX, 1);
	ft_putchar ('\n');
	ft_putnbr_fd(42, 1);
	ft_putchar ('\n');
	ft_putnbr_fd(-42, 1);
	ft_putchar ('\n');
	return (0);
}
#endif
