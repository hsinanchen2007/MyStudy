### 解题思路
请参考代码和注释
疑问：在本机只要十几毫秒就执行完的代码为毛在leetcode执行了100多毫秒

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] arr = this.dynamicPlan(n);
        return arr[n-1];
    }

    /**
     * 动态规划法
     * 任何一个丑数
     * 都是它之前的任意丑数 乘以 2 3 5
     * 的最小值
     * 比如 丑数5
     * 1 * 2 3 5 -> 2 3 5
     * 2 * 2 3 5 -> 4 6 10
     * 所以第i个丑数是前i-1个中乘以 2 3 5 比i大但是是最小的一个
     * <p>
     * 所以状态转移方程就是
     * dp[i] = min(dp[i-1]*2,3,5; dp[i-2]*2,3,5; ...do[0]*2,3,5)的最小值，且
     * > dp[i-1]
     *
     * @return
     */
    private int[] dynamicPlan(int n) {
        int[] rs = new int[n];
        rs[0] = 1;
        for (int i = 1; i < n; i++) {
            // 遍历之前每一个丑数
            // 之前每一个丑数都乘以 2  3  5
            // 只要比最后一个大就行
            // 注意处理溢出
            // 然后只保存一个最小值就行啦
            int min = Integer.MAX_VALUE;
            for (int j = i - 1; j >= 0; j--) {
                if(Integer.MAX_VALUE / 2 >= rs[j]){
                    int j2 = rs[j] * 2;
                    // 找到一个比前边的丑数大，但是在遍历中最小的数
                    if(j2 > rs[i-1]) {
                        if(j2 < min){
                            min = j2;
                        }
                    }
                }
                if(Integer.MAX_VALUE / 3 >= rs[j]) {
                    int j3 = rs[j] * 3;
                    if(j3 > rs[i-1]){
                        if(j3 < min){
                            min = j3;
                        }
                    }
                }
                if(Integer.MAX_VALUE / 5 >= rs[j]) {
                    int j5 = rs[j] * 5;
                    if (j5 > rs[i - 1]) {
                        if(j5 < min){
                            min = j5;
                        }
                    }
                }
            }
            rs[i] = min;
        }
        return rs;
    }
}
```