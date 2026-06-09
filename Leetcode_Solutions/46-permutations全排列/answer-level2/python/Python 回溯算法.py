### 解题思路
回溯算法也就是递归算法，需要写好出口和递推式。

### 代码

```python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def get_res(candidate, temp):
            if candidate == []:
                res.append(temp)
                return 
            for i in range(len(candidate)):
                get_res(candidate[:i] + candidate[i + 1:], temp + [candidate[i]])

        res = []
        get_res(nums, [])
        return res
```