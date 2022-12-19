### 解题思路
一路推进

### 代码

```python
class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        target=k*threshold
        result=0
        total=sum(arr[:k])
        if total>=target:
            result+=1
        for i in range(1,len(arr)-k+1):
            # print i
            total=total-arr[i-1]+arr[i+k-1]
            if total>=target:
                result+=1
        return result
```