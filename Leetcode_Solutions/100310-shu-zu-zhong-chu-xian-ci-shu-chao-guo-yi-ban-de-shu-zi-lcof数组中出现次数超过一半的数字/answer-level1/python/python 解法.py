### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a={}
        for item in nums:
            a[item]=a.get(item,0)+1
        for key,value in a.items():
            if value>(len(nums)/2):
                return key
```![屏幕快照 2020-03-19 20.50.12.png](https://pic.leetcode-cn.com/a911f69abdd331738e0d31eea7abd3ae717837caf402a8d6e3989c5fd778104d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-19%2020.50.12.png)
