### 解法一：自顶向下
- 定义状态数组
  dp[i]为自顶行到当前行的第i个结点的最小路径和。
- 初始化
  `dp[0] = triangle.get(0).get(0);`
- 状态转移方程
  `dp[j] = list.get(j) + (dp[j-1] < dp[j] ? dp[j-1] : dp[j]);`
  说明：list为当前行，dp[j]=当前行的第j个结点+上一行所产生的dp[j-1]和dp[j]中较小的一个。这里只能从后往前遍历当前行的结点，因为必须保证dp[j-1]和dp[j]为上一行所产生的，如果从前往后遍历，那么dp[j-1]就是当前行的了。
- 结果
  dp数组中最小的元素。
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int size = triangle.size();
        int len = triangle.get(size - 1).size();
        int[] dp = new int[len];
        dp[0] = triangle.get(0).get(0);
        for(int i = 1; i < size; i++){
            List<Integer> list = triangle.get(i);
            dp[i] = list.get(i) + dp[i-1];
            for(int j = i - 1; j > 0; j--){
                dp[j] = list.get(j) + (dp[j-1] < dp[j] ? dp[j-1] : dp[j]);
            }
            dp[0] += list.get(0);
        }
        int minSum = dp[0];
        for(int i = 1; i < size; i++){
            if(minSum > dp[i]){
                minSum = dp[i];
            }
        }
        return minSum;
    }
}
```
### 解法二：自底向上
- 定义状态数组
  dp[i]为自底行到当前行的第i个结点的最小路径和。
- 初始化
  `dp[0...n] = 0;`
- 状态转移方程
  `dp[j] = list.get(j) + (dp[j] < dp[j+1] ? dp[j] : dp[j+1]);`
  说明：list为当前行，dp[j]=当前行的第j个结点+下一行所产生的dp[j]和dp[j+1]中较小的一个。
- 结果
  dp[0]
```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int size = triangle.size();
        int len = triangle.get(size - 1).size();
        int[] dp = new int[len+1];
        for(int i = size - 1; i >= 0; i--){
            List<Integer> list = triangle.get(i);
            for(int j = 0; j <= i; j++){
                dp[j] = list.get(j) + (dp[j] < dp[j+1] ? dp[j] : dp[j+1]);
            }
        }
        return dp[0];
    }
}
```

