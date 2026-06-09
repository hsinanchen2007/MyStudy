### 解题思路
花园里有 N 个花盆，每个花盆里都有一朵花。这 N 朵花会在 N 天内依次开放，每天有且仅有一朵花会开放并且会一直盛开下去。

给定一个数组 flowers 包含从 1 到 N 的数字，每个数字表示在那一天开放的花所在的花盆编号。

例如， flowers[i] = x 表示在第 i 天盛开的花在第 x 个花盆中，i 和 x 都在 1 到 N 的范围内。

给你一个整数 k，请你输出在哪一天恰好有两朵盛开的花，他们中间间隔了 k 朵花并且都没有开放。

如果不存在，输出 -1。

 

样例 1:

输入: 
flowers: [1,3,2]
k: 1
输出: 2
解释: 在第二天，第一朵和第三朵花都盛开了。



### 代码

```c
#define MIN(a,b) ((a)<(b) ? (a):(b))
#define MAX(a,b) ((a)>(b) ? (a):(b))

int kEmptySlots(int* bulbs, int bulbsSize, int K){
    int i,j;
    int min_day,day,min;
    int days[102400] = {0};   
    
    //按照花的顺序，存储每个编号的花绽开需要多少天
    //bulbs 里存的花的编号，注意
    for(i=0;i<bulbsSize;i++){
        days[bulbs[i]] = i+1;
    }

    //还有K==0 的真恶心， 要看下第i天的编号前后花，是否已经开了
    if(K==0){
        for(i=1;i<bulbsSize-1;i++){
            if(bulbs[i]==1){
                if(days[bulbs[i]+1] < i)
                    return i+1;
            }else if(days[bulbs[i]-1] < i || days[bulbs[i]+1] < i)
                return i+1;
        }
    }

    min_day = day = bulbsSize;
    //要两边花开，中间不开。则中间花开天数都大于两边
    for(i=2;i<=bulbsSize-K;i++){
        min = days[i];
        for(j=i;j<i+K;j++)
            min = MIN(min,days[j]);
        if(min>days[i-1] && min>days[i+K]){
            day = MAX(days[i-1],days[i+K]);
            min_day = MIN(day,min_day);
        }
    }

    if(min_day<bulbsSize)
        return min_day;
    else
        return -1;
}
```