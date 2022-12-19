### 解题思路
此处撰写解题思路
有点像斐波那契数列，知道上一刻状态才能知道这一刻状态。z可以从最后一刻开始想起：要到达终点
(cost[costSize]),就必须知道costSize-1和costSize-2这两个地方谁大，对于任意一层阶梯皆是如此。端点处特殊讨论即可
### 代码

```c
int minCostClimbingStairs(int* cost, int costSize){
    int stage0=cost[0];
    int stage1=cost[1];
    int i=2;
    while(i<costSize){
        int temp=(stage0<stage1)?stage0+cost[i]:stage1+cost[i];
        stage0=stage1;
        stage1=temp;
        i++;
    }
    return stage0<stage1?stage0:stage1;
}
```