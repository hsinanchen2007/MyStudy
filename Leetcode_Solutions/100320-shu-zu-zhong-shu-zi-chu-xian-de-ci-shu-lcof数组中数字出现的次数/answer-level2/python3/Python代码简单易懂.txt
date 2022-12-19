### 解题思路
利用了字典和集合去重的特性

### 代码

```python
class Solution(object):
    def singleNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s = set()
        for i in nums:
            if i not in s:
                s.add(i)
            else:
                s.remove(i)
        return list(s)
```
![image.png](https://pic.leetcode-cn.com/e7e5749195c1deb4a910f15221dbb1deefa56117097399dc2c95f4b8a9957036-image.png)
