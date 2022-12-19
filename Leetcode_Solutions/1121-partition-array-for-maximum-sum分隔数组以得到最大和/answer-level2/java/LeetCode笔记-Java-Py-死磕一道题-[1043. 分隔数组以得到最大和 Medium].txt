##### 方法1：DP

![e7c5ca8d4c19bed3e8652951c6f37c6.jpg](https://pic.leetcode-cn.com/ddf9ff236598ff79b00e7365354cdaf961463cc78dfed7505334ad2628a60d73-e7c5ca8d4c19bed3e8652951c6f37c6.jpg)


![image.png](https://pic.leetcode-cn.com/a49b3279d3d2e9b9d9617da384d72dbcfe395dc3a0f0d1fe6fc4e4587f2c6d12-image.png)


```java []
public int maxSumAfterPartitioning(int[] A, int K) {
    if (A == null || A.length == 0) return 0;
    int len = A.length;
    int[] dp = new int[len + 1];
    for (int i = 0; i <= len; i++) {
        int j = i-1;
        int max = dp[i];
        while ((i - j) <= K && j >= 0) {
            max = Math.max(max, A[j]);
            dp[i] = Math.max(dp[i], dp[j] + max * (i - j));
            j--;
        }
    }
    return dp[len];
}
```
```python []
print('Hello world!')
```


- 注意点
    - 边界的退出条件
    - 初始化`dp`,`j`的值   
