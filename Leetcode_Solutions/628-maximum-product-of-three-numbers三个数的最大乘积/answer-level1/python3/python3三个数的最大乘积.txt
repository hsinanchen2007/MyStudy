### 解题思路
先排序，再求积。需要考虑含有负数的情况，若最大乘积有负数，则至少有两个，因此两种情形的最大乘积比较即可得到最大乘积。

### 代码

```python3
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        max1=nums[-1]*nums[-2]*nums[-3]
        max2=nums[0]*nums[1]*nums[-1]
        return max(max1,max2)
```

![image.png](https://pic.leetcode-cn.com/77eb1824d53ed949902776da6f795c57234aed89cad7dc07486f477dea5936ef-image.png)
