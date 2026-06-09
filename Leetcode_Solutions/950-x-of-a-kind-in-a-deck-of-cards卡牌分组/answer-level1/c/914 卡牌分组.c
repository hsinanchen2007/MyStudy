### 解题思路
此处撰写解题思路

### 代码

```c
int sign_value[10000] = {0};

bool hasSameNum(int a, int b)
{
    int i, tmp;

    if (!a || !b)
        return true;
    else if (a < 2 || b < 2)
        return false;

    tmp = a < b ? a : b;

    for(i = 2; i <= tmp; ++i)
        if (a % i == 0 && b % i == 0)
            return true;
    return false; 
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int i, tmp;

    if (deckSize < 2) {
        return false;
    }

    memset(sign_value, 0, 10000);

    for (i = 0; i < deckSize; ++i) {
        sign_value[deck[i]]++;
    }

    tmp = 0;
    for (i = 0; i < 10000; ++i) {
        if (tmp && !hasSameNum(sign_value[i], tmp))
            return false;
        else
            tmp = sign_value[i];
    }

    return true;
}
```