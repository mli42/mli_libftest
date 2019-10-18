/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   must_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:58:10 by mli               #+#    #+#             */
/*   Updated: 2019/10/18 11:59:37 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdio.h>

char	fct_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	ft_bezero(int len)
{
	int i = 0;
	char b[len];

	printf("\t\t\t|| BZERO WITH A ARRAY: ||\n");
	ft_bzero(b, len);
	while (i < len)
		printf("%d ", b[i++]);
	printf("\n");
}

void	ft_memeccpy(int c, size_t n)
{
	char		dest[] = "012345678";
	char		dest1[] = "012345678";
	const char	src[] = "whats up";

	printf("\t\t\t|| MEMCCPY TESTS: ||\n");
	// NO NEED NULL
	printf("Yours: %s\n", (char *)ft_memccpy(dest, src, c, n));
	printf("%s\n", dest);
	printf("Real : %s\n", (char *)memccpy(dest1, src, c, n));
	printf("%s\n", dest1);
}

void	ft_hit_oa(void)
{
	printf("\t\t\t|| ITOA with 0 | 10 | -10 | MAX | MIN ||\n");
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(10));
	printf("%s\n", ft_itoa(-10));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}

void	ft_memechr(void)
{
	printf("\t\t\t|| MEMCHR  TESTS: ||\n");
	printf("Yours:%s\n", (char *)ft_memchr("\0abcde", 'b', 5));
	printf("Real :%s\n", (char *)memchr("\0abcde", 'b', 5));
}

void	ft_memecmp(void)
{
	printf("\t\t\t|| MEMCMP  TESTS: ||\n");
	if (ft_memcmp("abcd", "abcd", 4) * memcmp("abcd", "abcd", 4) < 0)
		printf("1st NOT OK\n");
	else if (ft_memcmp("abcde", "abcd", 8) * memcmp("abcde", "abcd", 8) < 0)
		printf("2st NOT OK\n");
	else if (ft_memcmp("\200", "\0", 5) * memcmp("\200", "\0", 5) < 0)
		printf("3st NOT OK\n");
	else
		printf("MEMCMP OK\n");
}

void	ft_mememove(int begin_src, int begin_dest)
{
        size_t          n = 9;
        char            str[] = "0123456789ABCDEF\0";
        char            str1[] = "0123456789ABCDEF\0";
        char            *dest = &str[begin_dest];
        char            *dest1 = &str1[begin_dest];
        const char      *src = &str[begin_src];
        const char      *src1 = &str1[begin_src];

		printf("\t\t\t|| MEMMEM  TESTS: ||\n");
        printf("Yours: %s\n", (char *)ft_memmove(dest, src, n));
        printf("Real : %s\n", (char *)memmove(dest1, src1, n));
}

void	splitsplit(char *str)
{
	int		i;
	char	**result;

	i = 0;
	result = ft_split(str, ' ');
	if (str)
		while (result[i] != NULL)
			printf("%s\n", result[i++]);
}

void	ft_stringchr(char *str)
{
	printf("STRCHR IN : %s\n", str);
	printf("with g: %s\n", ft_strchr(str, 'g'));
	printf("with 8: %s\n", ft_strchr(str, '8'));
}

void	ft_strlkat(unsigned int size)
{
    char dest[30] = "12345";
    char dest2[30] = "12345";
    char src[] = "6789";

    printf("\n%d with yours\n", (int)ft_strlcat(dest, src, size));
    printf("%s\n", dest);
    printf("%d with the real\n", (int)strlcat(dest2, src, size));
    printf("%s\n\n", dest2);
}

void	ft_strlkpy(unsigned int size)
{
	char dest[10];
	char dest2[10];
	char src[] = "hello";

	printf("%d with mine\n", (int)ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	printf("%d with the real\n", (int)strlcpy(dest2, src, size));
	printf("%s\n", dest2);
}

void	mapi(void)
{
	printf("%s\n", ft_strmapi("une phrase", &fct_upper));
}

void	ft_ncmp(void)
{
	printf("\t\t\t|| STRNCMP  TESTS: ||\n");
	if (ft_strncmp("abcd", "abcd", 4) * strncmp("abcd", "abcd", 4) < 0)
		printf("1st NOT OK\n");
	else if (ft_strncmp("1234", "123", 5) * strncmp("1234", "123", 5) < 0)
		printf("2st NOT OK\n");
	else if (ft_strncmp("\200", "\0", 5) * strncmp("\200", "\0", 5) < 0)
		printf("3st NOT OK\n");
	else
		printf("STRNCMP OK\n");
}

void	ft_nstr(char *haystack, char *needle, size_t len)
{
	printf("Test: %s\n", ft_strnstr(haystack, needle, len));
	printf("Good: %s\n", strnstr(haystack, needle, len));
}

int		main(void)
{
	ft_bezero(10);
	printf("\n");

	ft_hit_oa();
	printf("\n");

	ft_memeccpy('a', 6);
	ft_memeccpy('s', 3);

	ft_memechr();
	ft_memecmp();

	ft_mememove(0, 4);
	ft_mememove(4, 0);

	printf("\t\t|| SPLIT:\n");
	splitsplit("  a string  with a lot of spaces ");
	splitsplit(NULL);

	printf("\t\t|| STRCHR:\n");
	ft_stringchr("1  2q3 e4 egfg5er u6qhn");

	printf("\t\t|| FT_STRJOIN:\n%s\n", ft_strjoin("sentence to", " concanate ..."));

	printf("\t\t\t|| STRLCAT  TESTS: ||\n");
	ft_strlkat(3);
	ft_strlkat(7);
	ft_strlkat(16);

	printf("\t\t\t|| STRLCPY  TESTS: ||\n");
	ft_strlkpy(0);
	ft_strlkpy(3);
	ft_strlkpy(7);

	ft_ncmp();

	printf("\n\t\t\t|| STRNSTR: ||\n");
	ft_nstr("lorem ipsum dolor sit amet", "dolor", 15);
	ft_nstr("lorem ipsum dolor sit amet", "dolor", 20);
	ft_nstr("lorem ipsum dolor sit amet", "dontexist", 20);
	ft_nstr("lorem ipsum dolor sit amet", "dontexist", 200);

	printf("STRRCHR: %s\n", ft_strrchr("a sentence which has a lot of letters", 'a'));

	printf("STRTRIM: %s\n", ft_strtrim("a trim sentence with chars to trim  a", "a "));

	printf("SUBSTR: %s\n", ft_substr("0123456789ABCDEF\0", 4, 5));
	printf("SUBSTR: (should not print anything) %s\n", ft_substr("0123456789ABCDEF\0", 30, 5));
}
