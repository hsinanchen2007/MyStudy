### 解题思路
![批注 2020-03-16 230601.png](https://pic.leetcode-cn.com/89d307f6a5c717aa7f1d22e4c3bafea9416251d0998b71aecce0d5fd547cc96f-%E6%89%B9%E6%B3%A8%202020-03-16%20230601.png)
就是把它倒过来，前面比它小的减去

### 代码

```c
int swi(char ch)
{
    switch (ch)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToInt(char* s) {
    int i, sum = 0;
    for (i = 0; *(s + i + 1) != '\0'; i++);
    for (; i >= 0; i--)
    {
        if (i - 1 < 0)
            sum += swi(*(s + i));
        else if (swi(*(s + i - 1)) < swi(*(s + i)))
        {
            sum += swi(*(s + i)) - swi(*(s + i - 1));
            i--;
        }
        else
            sum += swi(*(s + i));
    }
    return sum;
}
```