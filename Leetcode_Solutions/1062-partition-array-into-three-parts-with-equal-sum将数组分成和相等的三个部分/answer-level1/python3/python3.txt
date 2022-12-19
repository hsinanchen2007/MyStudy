### 解题思路
1，首先要判断整个数组的和是否能够整除3，不能的话则返回false
2，然后为了方便计算数组中某一段的和，这里引用了一个dp数组，专门用来记录和，
dp[0] = A[0]
dp[1] = A[0] + A[1]
dp[2] = A[0] + A[1] + A[2]
dp[n] = A[0] + A[1] + ... + A[n]
3，然后引入双指针： i 和 j，需要满足
dp[i] == dp[j] - dp[i] == dp[-1] - dp[j],
你也可以这么理解，这个i和j就相当于把数组分割为三等分里面的分割线

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        dp = [0] * len(A)
        s = 0
        for i in range(0 , len(A)):
            if i >= 1:
                dp[i] = dp[i - 1] + A[i]
            else:
                dp[i] = A[i]
            s += A[i]

        if s % 3 != 0 :
            return False

        target = s // 3
        for i in range(0 , len(dp)):
            if dp[i] == target:
                for j in range( i + 1 , len(dp) - 1):
                    if dp[j] - dp[i] == target and dp[-1] - dp[j] == target:
                        return True
        
        return False

```