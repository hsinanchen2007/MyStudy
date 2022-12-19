### 解题思路
第i个台阶是第i-1个台阶的“楼顶”

只有一个台阶的时候，一次走两步，就不需要花费体力
有两个台阶的时候，没办法一下走两步就到达第2个台阶的“楼顶”（也就是没办法一下走两步就到第3个台阶上）

到达第i个台阶的“楼顶”，要么就是从第i个台阶走一步上去，要么就是从第i-1个台阶走两步上去。
从第i个台阶上去：   首先要走到第i个台阶上       等价于   到达第i-1个台阶的“楼顶”，再花费第i个台阶需要的力气
从第i-1个台阶上去： 首先要走到到第i-1个台阶上   等价于   到达第i-2个台阶的“楼顶”，再花费第i-1个台阶需要的力气

更详细参考链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs/solution/yi-bu-yi-bu-tui-dao-dong-tai-gui-hua-de-duo-chong-/

### 代码

```c
int minCostClimbingStairs(int* cost, int costSize){
    int* result=(int*)malloc(sizeof(int)*costSize);
    result[0]=0;
    result[1]=cost[0]<cost[1]?cost[0]:cost[1];
    for(int i=2;i<costSize;++i)
        result[i]=  result[i-1]+cost[i] < result[i-2]+cost[i-1] ?
                    result[i-1]+cost[i] : result[i-2]+cost[i-1];
    int n=result[costSize-1];
    free(result);
    return n;
}




```