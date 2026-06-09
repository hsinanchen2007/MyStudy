### 解题思路
DFS 搜索顺序为面值从大到小，同一面值数量由多到少，搜索过程中记录到此为止所花费的硬币数。

剪枝处理如下，具体位置见代码注释：
1. 当 $amount==0$ 时剪枝，因为大面值硬币需要更多小面值硬币替换，继续减少一枚或几枚大硬币搜索出来的答案【如果有】肯定不会更优。
2. 当 $amount!=0$，但已经使用的硬币数 $cnt$ 满足了 $cnt+1>=ans$ 时剪枝，因 $amount$ 不为 $0$，至少还要使用 $1$ 枚硬币，则继续搜索得到的答案不会更优。是 $break$ 不是 $continue$，因为少用几枚面值大的硬币搜索出的方案【如果有】肯定需要更多枚面值小的硬币来替换掉这枚大的硬币【同剪枝 $1$ 理由】，而使用这几枚大的硬币都搜索不到更好的解，故应该是 $break$。

### 疑惑
不知道是不是因为测试数据的问题，这题应该是一个标准的 DP 题，DFS 不应该比 DP 快才对。

### 代码

```java
class Solution {
    int ans=Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        dfs(coins,coins.length-1,amount,0);
        return ans==Integer.MAX_VALUE?-1:ans;
    }
    public void dfs(int[] coins,int index,int amount,int cnt){
        if(index<0){
            return;
        }
        for(int c=amount/coins[index];c>=0;c--){
            int na=amount-c*coins[index];
            int ncnt=cnt+c;
            if(na==0){
                ans=Math.min(ans,ncnt);
                break;//剪枝1
            }
            if(ncnt+1>=ans){
                break; //剪枝2
            }
            dfs(coins,index-1,na,ncnt);
        }
    }
}
```