### 解题思路


#### 在知道了异或可以抵消两个数后，此题不难想到异或。 异或的想法来自习题 [136.只出现一次的数字](https://leetcode-cn.com/problems/single-number/)
[评论区陈牧远也提出了异或(https://leetcode-cn.com/problems/missing-number/comments/7005)

#### 但看了官方题解，居然还有可以使用 数学-求和相减的方法，甚是巧妙。

#### 不过求和，虽然高斯公式快，最好还是，要控制避免溢出的风险。


### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0
        for n in nums:
            res = res ^ n 
        n = len(nums)
        for i in range(n+1):
            res ^= i
        return res
```
#### 求和法
``` python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = len(nums)
        for i, n in enumerate(nums):
            res += i
            res -= n
        return res
```