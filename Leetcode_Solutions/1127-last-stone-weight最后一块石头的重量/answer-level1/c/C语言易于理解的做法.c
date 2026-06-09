用递归的方法即可解决。先将数组从大到小排列，排列后若stones[1]等于0，则完成。用stones[0]减去stones[1]，并让stones[1]等于0，递归。
```c
int lastStoneWeight(int* stones, int stonesSize){
    if(stonesSize==1) return stones[0];
    short i,j,tmp;
    for(i=0;i<stonesSize;i++)
        for(j=i+1;j<stonesSize;j++)
            if(stones[j]>stones[i]){
                tmp=stones[j];
                stones[j]=stones[i];
                stones[i]=tmp;
            }
    if(stones[1]==0) return 0;
    stones[0]=stones[0]-stones[1];
    stones[1]=0;
    lastStoneWeight(stones,stonesSize);
    return stones[0];
}
```
让我惊讶的是，递归的做法执行用时和内存消耗都较优。