初学小白一枚，用了简单的排序算法，不知道为啥用C的这么少了，。
```
int lastStoneWeight(int* stones, int stonesSize){
    if(stones==NULL)
        return 0;
    int i,j;
    int temp,max;
    
    while(stonesSize>1)
    {
        //两次选择排序
        for(j=1;j<=2;j++)
        {
            max=stones[stonesSize-j];
            //printf("%d,max:%d\n",j,max);
            for(i=stonesSize-j;i>=0;i--)
            {
                if(max<stones[i])
                {
                    max=stones[i];//关键语句：更新最大值
                    temp=stones[i];
                    stones[i]=stones[stonesSize-j];
                    stones[stonesSize-j]=temp;
                }
            }
        }
        stones[stonesSize-2]=stones[stonesSize-1]-stones[stonesSize-2];
        stonesSize--;
    }
    return stones[0];
}


```
