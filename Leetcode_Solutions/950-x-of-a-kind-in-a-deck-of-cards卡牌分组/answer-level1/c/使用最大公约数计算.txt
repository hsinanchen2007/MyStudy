### 解题思路
首先对数组各个字符串分别计数，然后对计数的数组继续查找。
找到前后两个数量的最大公约数，并加入数组，同时记录最大公约数的最小值。
只有当所有的最大公约数都能够整除当前记录的最小值，才算全部能够分组，其余情况全部false。

### 代码

```c
bool hasGroupsSizeX(int* deck, int deckSize){
    int tmpx[10000] ,tmpy[10000] = {0};
    int i,j,size;
    int x,a,b,ret[10000];
    size = 0;
    for(i=0;i<10000;i++)
        tmpx[i] = -1;
    for(i=0;i<deckSize;i++)
    {
        j = 0;
        while(1)
        {
            if(tmpx[j] == -1)
            {
                tmpx[j] = deck[i];
                size += 1;
                tmpy[j] += 1;
                break;
            }
            if(tmpx[j] == deck[i])
            {
                tmpy[j] += 1;
                break;
            }
            j++;
        }
    }
    x = 10000;
    j = 0;
    if(size == 1)
    {
        if(tmpy[0] > 1)
            return true;
        else
            return false;
    }
    for(i=0;i<size-1;i++)
    {
        a = tmpy[i];
        b = tmpy[i+1];
        while(a!=b)
        {
            if(a>b)
                a = a-b;
            else
                b = b-a;
        }
        if(x > a)
            x = a;
        ret[j] = a;
        j++;
    }
    if(x <= 1)
        return false;
    else{
        for(i=0;i<j;i++)
        {
            if(tmpy[i] % x != 0)
                return false;
        }
        return true;
    }
}
```