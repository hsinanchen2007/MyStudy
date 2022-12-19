### 解题思路
![图片.png](https://pic.leetcode-cn.com/ee0c1fe7ef8ed9e77561f7313eebab8ab429ee7d9da19b88b1424eaa1ab163ba-%E5%9B%BE%E7%89%87.png)


### 代码

```c
#include <math.h> 
int myAtoi(char * str)
{
    long number = 0;
	char *temp_str = NULL;
	char a[58];
	a[48] = 0, a[49] = 1, a[50] = 2, a[51] = 3, a[52] = 4,
	a[53] = 5, a[54] = 6, a[55] = 7, a[56] = 8, a[57] = 9; 
	
	while(*str == ' ')
	str++; 
	
	if((*str < 48 && *str != 43 && *str != 45) || *str > 57 || *str == '\0')
	return 0;
	
	temp_str = str;
	if(*str == 43 || *str == 45)	
	for(str += 1; *str >= 48 && *str <= 57; number = number*10+a[*str++])
	if(number > pow(2, 31)) 
	if(*temp_str == 45)
	    return -pow(2, 31);
	else
	    return pow(2, 31);

	str = temp_str;
	
	if(*str == 45)
	number = - number;

    if(number < -2147483648)
    return -pow(2, 31);
	
	if(*str >= 48 && *str <= 57)
	for(; *str >= 48 && *str <= 57; number = number*10+a[*str++])
	if(number > pow(2, 31)-1) 
	    return pow(2, 31)-1;

    if(number >= 2147483648)
	return pow(2, 31)-1;
    else
    return number;
}
```