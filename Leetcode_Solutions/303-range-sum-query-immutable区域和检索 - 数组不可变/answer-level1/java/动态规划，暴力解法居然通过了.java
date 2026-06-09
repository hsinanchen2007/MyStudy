一看这个题目 第一反应求和不就好了么，于是直接暴力解通过，心里还奇怪 这有啥意思，看下题解，我丢，我傻了
然后开始写dp方程
最开始想的是 dp[i][j] = dp[i]dp[j-1] + num[i]
涉及2个变量 用二维数组存储dp

但想起来 看题解好像只有一维dp
想了一下 假设 现有数组 1 2 3 4 

我们已知 sum【0，2】 = 1 + 2 + 3 = 6
求 sum[0,1] 直观观察 就直接用sum[0,2] - num[2] 就好 
但这有个问题 我们用一维dp 存储结果的时候 其实已经不知道num的值了

所以换个思路 我们dp[0] = 0;
dp[1] = dp[0] + num[i - 1] 及前缀值计算的时候 不加当前值 下一个值计算的时候 加上前一个index的值 这样2个之差就是num[i]

还是数组：
1 2 3 4 

dp
0 1 3 6 10 

求[1，3]的值
sum[1,3] = sum [1,4] - sum[1]

->
dp [j] = dp [j + 1] - dp [i]


```
    private NumArray(int[] nums) {
        sum = new int[nums.length + 1];
        sum[0] = 0;

        for (int i = 1; i <= nums.length; i++) {
            sum[i ] = sum[i - 1] + nums[i - 1];
        }
    }

    private int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
```








 

