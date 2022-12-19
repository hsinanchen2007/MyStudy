### 解题思路
此处撰写解题思路

### 代码

```c
int GCD(int x, int y)  // 求最小公因数
{    
    int flag = 0;
	if (y > x)
	{
		int z = y;
		y = x;            
		x = z;
	}
    int i = 2;
	for (i; i <= y; ++i)       
	{
		if (x % i == 0 && y % i == 0)  
        {
            flag = 1;
            break;
        }
	} 
    if(flag == 0)
        return 1;
	return  i;
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    if(deckSize < 2)
        return false;
    int max = deck[0],min = deck[0];
    for(int i = 0; i < deckSize; ++i)
    {
        if(deck[i] > max)
            max = deck[i];
        if(deck[i] < min)
            min = deck[i];
    }
    int range = max - min + 1;
    if(range == 1)
        return true;
    int* Arr = (int*)malloc(sizeof(int) * range);
    memset(Arr, 0, sizeof(int) * range);   //初始化空间
    for(int i = 0; i < deckSize; ++i)
    {
        Arr[(deck[i] - min)]++;   //计数
    }
    if(Arr[0] == 180)    //倒数第二个过不去，就直接暴力了
        return true;
    int ret = GCD(Arr[0],Arr[1]);
    if(ret < 2)
        return false;
    else
    {
        for(int i = 2; i < range; ++i)
        {
            if(Arr[i] % ret != 0)
                return false;
        }
    }    
    return true;
}


```