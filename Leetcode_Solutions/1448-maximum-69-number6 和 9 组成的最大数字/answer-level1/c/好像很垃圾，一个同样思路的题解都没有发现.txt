把整数分别存放到数组中，然后从左向右遍历，找到第一个是6的数变成9，然后还原返回就可以了
```
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了100.00%的用户
```
```c
#include <stdio.h>

int maximum69Number(int num)
{
    int save[5] = {0};
    int idx     = 0;

    int res = 0;

    while(num > 0)
    {
        save[idx++] = num % 10;
        num /= 10;
    }

    int flag = 0;
    for(int i = idx - 1; i >= 0; i--)
    {
        if(flag == 0)
        {
            if(save[i] == 6)
            {
                save[i] = 9;
                flag    = 1;
            }
        }
        res = 10 * res + save[i];
    }

    return res;
}

int main(void)
{
    printf("%d\n", maximum69Number(9669));
    printf("%d\n", maximum69Number(9996));

    return 0;
}
```