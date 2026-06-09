### 解题思路
容易证明在数组首项后加左括号、末项后加右括号除数最小。特殊情况单独讨论一下即可
![image.png](https://pic.leetcode-cn.com/3ec8dc7aec787a37179634b28d7aa3903048315d785a38ee10d5b6f2b5c87be8-image.png)


### 代码

```python
class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums:
            return ""
        n = len(nums)
        s = str(nums[0])
        if n == 1:
            return s
        if n == 2:
            return s + "/" + str(nums[1])
        s += "/("
        for i in range(1, n - 1):
            s += str(nums[i]) + "/"
        s += str(nums[-1]) + ")"
        
        return s


```