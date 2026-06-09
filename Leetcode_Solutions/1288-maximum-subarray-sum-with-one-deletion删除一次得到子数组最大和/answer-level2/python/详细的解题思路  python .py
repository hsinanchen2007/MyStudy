### 解题思路

1. cursum -> 不删除元素的和   delsum -> 删除元素的和   
2. delsum的值应该是下列三种情况的最大值 a. 删除当前元素的值，即上一轮的cursum  b. 不删除当前元素的值, 即cursum + num c. 从头开始   
3. cursum的值应该是下列两种情况的最大值 a. 重头开始, 即0 b. cursum + num    
4. 当前元素的最大值即delsum和cursum的最大值     
 
### 代码

```python
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        ans = max(arr)
        cursum = delsum = 0
        for idx, num in enumerate(arr):
            delsum = max(0, delsum+num, cursum)
            cursum = max(0, cursum + num)
            ans = max(cursum or ans, ans, delsum or ans)

        return ans
```