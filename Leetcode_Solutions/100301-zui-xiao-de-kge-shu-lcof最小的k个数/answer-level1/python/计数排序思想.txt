### 解题思路
计数排序即可

### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        nums,res=[0]*10000,[]
        if not k:
            return []
        for i in arr:
            nums[i]+=1
        for i in range(len(nums)):
            while nums[i]>0:
                if len(res)==k:
                    return res
                res.append(i)
                nums[i]-=1
            if len(res)==k:
                return res    
        return res
        
```