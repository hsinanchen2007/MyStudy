### 解题思路
遍历半个字符串，依次将首尾2个字符对换位置，直到字符串中间
第一步：考虑递归退出条件：
    1.当起始位置=结束位置时，即剩中间一个字符时
    2.当起始位置>结束位置时，即字符总数为偶数，中间2个字符对换位置之后
第二步：设计递归主过程：
    1.对换当前起始和结束位置的2个字符
    2.起始位置+1，结束位置-1
第三步：起始和结束位置初始化，并调用递归


### 代码

```python
class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        def helper(start_idx, end_idx, s):
            if start_idx >= end_idx:
                return s
            s[start_idx], s[end_idx] = s[end_idx], s[start_idx]
            s = helper(start_idx + 1, end_idx - 1, s)

        return helper(0, len(s) - 1, s)        
```