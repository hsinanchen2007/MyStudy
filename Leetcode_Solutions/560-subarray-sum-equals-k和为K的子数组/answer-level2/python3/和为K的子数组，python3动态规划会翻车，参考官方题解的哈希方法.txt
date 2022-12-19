### 解题思路
*sum*用来记录从第0位到第i位的累加和， 即*summ[i] = nums[0]+nums[1]+...+nums[i]*
在遍历nums的过程中*res*用来存储summ在之前的遍历中共出现了多少次
如果遍历到当前位，*summ-k*在之前的遍历中出现了*n*次，这说明有*n*个以当前位为最后元素的*nums*子数组累加和为*k*
然后更新*res*


### 代码

```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = {0:1}
        count = 0
        summ = 0
        for i in nums:
            summ += i
            if summ-k in res:
                count += res[summ-k]
            if summ not in res: res[summ]=1
            else: res[summ] += 1
        return count
```