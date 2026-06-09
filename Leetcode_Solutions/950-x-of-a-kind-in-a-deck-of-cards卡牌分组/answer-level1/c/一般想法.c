### 解题思路
首先计算数组中给出的数出现的个数，然后将每个数的个数赋给数组，求数组的最大公约数，如果最大公约数大于等于2，将flag赋值为true返回即可。

### 代码

```c
// 求两数的最大公约数
int greatest_common_divisor_two(int a, int b)
{
    int c;
    if(a % b == 0) return b;
    c = greatest_common_divisor_two(b, a % b);
    return c;
}

// 求数组中数的最大公约数
int greatest_common_divisor_array(int *a, int aSize)
{
    
    if(a[1] == 0) return a[0];
    else
    {
        int c = greatest_common_divisor_two(a[0], a[1]);
        for(int i = 2; i < aSize; i++)
        {
            if(a[i] != 0)
            {
                c = greatest_common_divisor_two(c, a[i]);
            }
            else break;
        }
        return c;
    }
    
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int a[10000] = {0};
    int *b = (int*)malloc(sizeof(int) * deckSize);
    int i=0,j=0;

    for(int i = 0; i < deckSize; i++)
    {
        b[i] = 0;
    }
    bool flag = false;

    // 记录每个数出现的次数
    for(int i = 0; i < deckSize; i++)
    {
        a[deck[i]]++;
    }

    while(i < 10000 && j < deckSize)
    {
        if(a[i] != 0)
        {
            b[j] = a[i];
            j++;
        }
        i++;
    }

    if(deckSize > 1)
    {
        int c = greatest_common_divisor_array(b, deckSize);
        if(c >= 2) flag = true;
    }
    
    return flag;
}
```