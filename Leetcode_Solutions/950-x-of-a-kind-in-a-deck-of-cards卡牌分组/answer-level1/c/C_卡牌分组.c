### 解题思路
申请10001个int空间比较浪费，但是能提高速度。


### 代码

```c
int gongYueShu(int A,int B)
{
    return A%B==0?B:gongYueShu(B,A%B);
}

bool hasGroupsSizeX(int* deck, int deckSize){

    int count[10001]={0};
    for(int i=0;i<deckSize;++i)
        ++count[deck[i]];
    
    int num=-1;//公约数
    for(int i=0;i<10001;++i)
        if(count[i]!=0)
            if(num==-1)
                num=count[i];
            else
                {
                    num=gongYueShu(num,count[i]);
                    if(num<2)
                        return 0;  
                }
    return num>1;
}


```