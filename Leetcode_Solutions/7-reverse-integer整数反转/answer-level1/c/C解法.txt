### 解题思路
此处撰写解题思路
![abc.jpg](https://pic.leetcode-cn.com/a1196a322e83f03ddf88fa2d04a9bdb4d71fa80e63fe7ddcd95e2244ea021bb9-abc.jpg)

### 代码

```c
#include<stdio.h>

#define INT_MAX 2147483647  //2147483647
#define INT_MIN (-INT_MAX - 1)     //-2147483648
                //这里不能直接定义-2147483648，在C语言中这不是一个数，而是一个表达式，
                //意思是对2147483648取负运算。但是2147483648已经溢出，取负运算同样是错的。
int reverse(int x)
{
    int pop = 0, temp = 0;
    while (x != 0)
    {
        pop = x % 10;
        x /= 10;
        if (temp > INT_MAX / 10 || (temp == INT_MAX / 10 && pop > 7))
        {
            return 0;
        }
        if (temp < INT_MIN / 10 || (temp == INT_MIN / 10 && pop < -8))
        {
            return 0;
        }
        temp = temp * 10 + pop;
    }
    return temp;
}

```