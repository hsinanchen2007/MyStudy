### 解题思路
转大佬思路https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
递归过程中，注意两个return的语句顺序。
以[1, 2, 5]和11为例，在最后一次递归时，输入参数amount=0，cnt=3,index=-1，所以先判断cnt，再判断index！！！

### 代码

```java
class Solution {
    int res = Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        dfs(coins, amount, 0, coins.length - 1);
        return res == Integer.MAX_VALUE ? -1 : res;
    }
    public void dfs(int[] coins, int amount, int cnt, int index){
        //顺序先
        if(amount == 0){
            res = Math.min(res, cnt);
            return;
        }
        //顺序后
        if(index < 0){
            return;
        }
        //k表示amount中至多能包含多少coins[index]，下一次递归时，先从amount中减去k*coins[index]，说明amount中不可能包含coins[index]，然后index向前移位（数组排序），k--即减多回溯的过程
        for(int k = amount / coins[index]; k >= 0 && k + cnt < res; k --){
            dfs(coins, amount - k * coins[index], cnt + k, index - 1); 
        }
    }
}
```