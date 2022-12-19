### 解题思路
大佬们的贪心算法，用C语言写的

### 代码

```c
#include<stdio.h>
#include<string.h>

char * intToRoman(int num)
{
    short hash_key[13] = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };
    const char *hash_value[13] = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
    static char str[16] = "";     //没有用动态数组的方法是不知道主函数会不会在用完之后释放
    int flag = 1;
    for (int i = 0; i < 13; i++)
    {
        while (num >= hash_key[i])
        {
            num -= hash_key[i];
            if (flag)
            {
                flag = 0;
                strcpy(str, hash_value[i]);
            }
            else
            {
                strcat(str, hash_value[i]);
            }
        }
    }
    return str;
}

```