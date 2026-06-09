### 解题思路


### 代码

```c
bool hasGroupsSizeX(int* deck, int deckSize){
    int a[10001]={0};
    int len=0,max=0;
    for(int i=0;i<deckSize;i++)
    {
        a[deck[i]]++;
        if(len<deck[i])
            len=deck[i];
        if(max<a[deck[i]])
            max=a[deck[i]];
    }
    int num=2;
    while(num<=max)
    {
        for(int i=0;i<len+1;i++)
        {
            if(a[i]%num!=0)
                break;
            if(a[i]%num==0&&i==len)
                return true;
        }
        num++;
    }
    return false;
}
```