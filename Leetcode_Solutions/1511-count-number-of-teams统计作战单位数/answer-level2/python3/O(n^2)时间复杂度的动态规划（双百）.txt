### 解题思路
![image.png](https://pic.leetcode-cn.com/6d632cca583e140e6ef92bd4b91fb4b17e8ccb49a479a8641607ee127c5e90f2-image.png)
1. 更新dp的同时，更新res；
2. dp[i]记录的是第i个数之前比其值小的数的个数；
3. 两层判断，如果`nums[i] > nums[idx]`, 更新`dp[i]`，其次，如果`dp[idx]>0`则再更新`res`。因为此时，`num[i]`已经大于`nums[idx]`，再算上一个比`nums[idx]`小的数，就构成了一个3个数的升序，这样的组合有`dp[idx]`；
4. 另外的一种情况，将数组逆序即可。

### 代码

```python3
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        
        def func(nums):
            dp = [0] * len_
            res = 0
            for i in range(1, len_):
                idx = i - 1
                while idx >= 0:
                    if nums[i] > nums[idx]:
                        dp[i] += 1
                        if dp[idx] > 0:
                            res += dp[idx]
                    idx -= 1
            return res
            
        len_ = len(rating)
        return func(rating[::-1]) + func(rating)          
```