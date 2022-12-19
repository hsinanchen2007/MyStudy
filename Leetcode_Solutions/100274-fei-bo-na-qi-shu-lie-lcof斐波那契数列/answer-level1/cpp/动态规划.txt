### 运行结果

![image.png](https://pic.leetcode-cn.com/46f11f9ebad0d371a1db36620d152b90f3644ad2f7f145e9392dfc99a09c1c92-image.png)

![image.png](https://pic.leetcode-cn.com/9fbefabc9d89cf6027e99cd665f20bdd7712258e151ef69926291d1d06b8665d-image.png)

![image.png](https://pic.leetcode-cn.com/aa8101b2a37dd49337ad90b2f3f438acf29400028db7082389330e4ce9391085-image.png)


### 解题思路

动态规划

### 代码

```cpp []
class Solution
{
public:
    int fib(int n)
    {
        vector<int> dp = {0, 1};
        for (size_t i = 2; i <= n; i++)
        {
            dp.push_back((dp[i - 1] + dp[i - 2]) % 1000000007);
        }
        return dp[n];
    }
};
```
```rust []
impl Solution {
    pub fn fib(n: i32) -> i32 {
        let mut dp = vec![0i32, 1];
        let len = 1 + n as usize;
        for i in 2..len {
            dp.push((dp[i - 1] + dp[i - 2]) % 1000000007);
        }
        return dp[len - 1];
    }
}
```
```go []
func fib(n int) int {
	var dp []int= []int{0, 1}
	for i := 2; i <= n; i++ {
		dp = append(dp, (dp[i - 1] + dp[i - 2]) % 1000000007)
	}
	return dp[n]
}
```