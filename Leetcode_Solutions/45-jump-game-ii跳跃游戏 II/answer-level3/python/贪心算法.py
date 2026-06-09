## 思路:

**思路一:** 动态规划

刚开始,我想用动态规划,用`dp[i]`表示到`i`位置的最少步数

动态方程为:`dp[i] = min(dp[i], dp[j] + 1)`,`j`位置可以到达`i` 的位置,代码如下:

```python [1]
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [float("inf")] * n
        dp[0] = 0
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] >= i - j:
                    dp[i] = min(dp[i], dp[j] + 1)
        #print(dp)
        return dp[-1]
```

```java [1]
public class JumpGameII {
    public int jump(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = 0;
        for (int i = 1; i < nums.length; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= i - j) {
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[nums.length - 1];
    }
}
```

但是, 这是$O(n^2)$算法,如果数据超过$10^4$就过不了,没想到真的过不了,哈哈!

**思路2: 贪心算法**

类似与BFS

一句话解释: 从一个位置跳到它能跳到的最远位置之间的都只需要一步!

所以,如果一开始都能跳到,后面再跳到的肯定步数要变多!








## 代码:


```python [1]
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1 : return 0
        dp = [0] * n
        for i in range(n):
            for j in range(nums[i], 0, -1):
                if i + j >= n - 1 : return dp[i] + 1
                elif dp[i + j] == 0:
                    dp[i + j] = dp[i] + 1
                else:
                    break
        return "到不了最后"
```


```java [1]
class Solution {
    public int jump(int[] nums) {
        if (nums.length == 1) return 0;
        int[] dp = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            for (int j = nums[i]; j > 0; j--) {
                if (i + j >= nums.length - 1) {
                    return dp[i] + 1;
                } else if (dp[i + j] == 0) {
                    dp[i + j] = dp[i] + 1;
                } else {
                    break;
                }
            }
        }
        return 0;
    }
}
```

