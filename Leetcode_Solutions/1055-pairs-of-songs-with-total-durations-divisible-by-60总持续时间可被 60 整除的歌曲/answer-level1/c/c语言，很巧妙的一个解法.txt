### 解题思路
一开始想到的是暴力解法，是可行的，不过超出时间限制。
后面想到的这个解法非常巧妙，写出来很激动。

### 代码

```c
int numPairsDivisibleBy60(int* time, int timeSize){
    //很巧妙的思路
    int i;
    int *p;
    int temp;
    int count=0;
    p=(int *)malloc(sizeof(int)*60);
    for(i=0;i<60;i++){
        p[i]=0;
    }
    for(i=0;i<timeSize;i++){
        temp=time[i]%60;
        p[temp]++;
    }
    if(p[0]>=2){
        count+=p[0]*(p[0]-1)/2;
    }
    if(p[30]>=2){
        count+=p[30]*(p[30]-1)/2;
    }
    for(i=1;i<=29;i++){
        count+=p[i]*p[60-i];
    }
    return count;    
}
```