### 解题思路
按官方提供算法实现

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mode=""
        cnt = 0
        for e in nums:
            if cnt == 0:
                mode = e
            if mode ==e:
                cnt+=1
            else:
                cnt-=1
        return mode
```