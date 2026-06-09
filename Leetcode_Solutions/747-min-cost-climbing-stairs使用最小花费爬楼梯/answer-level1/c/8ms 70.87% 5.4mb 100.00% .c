### 解题思路
为什么我这个代码用了malloc反而是在时间上比较慢，空间上省内存？

### 代码

```c
int minCostClimbingStairs(int* cost, int costSize){
    int *stages=(int*)malloc(costSize*sizeof(int));
    stages[0]=cost[0];
    stages[1]=cost[1];
    int i=2;
    while(i<costSize){
        stages[i]=(stages[i-2]<stages[i-1])?stages[i-2]+cost[i]:stages[i-1]+cost[i];
        i++;
    }
    int ans=stages[costSize-2]<stages[costSize-1]?stages[costSize-2]:stages[costSize-1];
    free(stages);
    return ans;
}
```