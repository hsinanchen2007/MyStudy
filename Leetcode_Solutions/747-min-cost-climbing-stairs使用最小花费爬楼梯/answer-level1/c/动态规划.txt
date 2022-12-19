### 解题思路
到达第0，1，2层不消耗体力；
到达第i层消耗的最小体力=min( 第i-2层的消耗+从第i-2层出发的体力消耗，
                            第i-1层的消耗+从第i-1层出发的体力消耗)；

### 代码

```c
#define min(a,b) a<b?a:b
int minCostClimbingStairs(int* cost, int costSize){
    if(costSize<=1)
        return 0;
    int* result=(int*)malloc((costSize+1)*sizeof(int));
    result[1]=result[0]=0;
    for(int i=2;i<costSize+1;i++){
        result[i]=min(result[i-2]+cost[i-2],result[i-1]+cost[i-1]);
    }
    return result[costSize];
}
```