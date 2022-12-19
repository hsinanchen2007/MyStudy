### 解题思路
1. 首先递归的思想是遍历所有的平方数，找到最小的组合数，加上备忘录减少重复计算。
2. 改写成动态规划的形式思想相同。
3. 还可用BFS来做：类似层次遍历的思想，首先找到使a为0的step为最小step。使用visited来保存已访问的值。因为已访问的step肯定小于后访问的step，所以可以这么做。

### 代码

```java
class Solution {
    int[] memo;
    public int numSquares(int n) {
        memo = new int[n+1];
        return dp(n);
    }

    private int dp(int n){
        if(memo[n] != 0) return memo[n];
        int val = (int)Math.sqrt(n);
        if(val * val == n) return memo[n] = 1;
        int res = Integer.MAX_VALUE;
        for(int i = 1; i * i < n; i++)
            res = Math.min(res, dp(n-i*i) + 1);
        return memo[n] = res;
    }
}

class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        for(int i = 1; i <= n; i++){
            dp[i] = i;
            for(int j = 1; j * j <= i; j++)
                dp[i] = Math.min(dp[i], dp[i - j * j] + 1);    
        }
        return dp[n];
    }
}

class Solution {
    public int numSquares(int n) {
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        boolean[] visited = new boolean[n+1];
        queue.offer(new Pair(n, 0));

        while(!queue.isEmpty()){
            int num = queue.peek().getKey();
            int step = queue.peek().getValue();
            queue.poll();

            for(int i = 1; i * i <= num; i++){
                int a = num - i * i;
                if(a == 0) return step + 1;
                if(!visited[a]){
                    queue.offer(new Pair(a, step+1));
                    visited[a] = true;
                }
            }
        }
        return -1;
    }
}
```