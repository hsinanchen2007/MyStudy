### 解题思路
就一个关键点，-1在list中对应最后一位，-2对应倒数第二位。。。只要遍历到长度除以2减一就行了，不用双指针。

### 代码

```python
class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        for i in range(len(s)//2):
            temp = s[i]
            s[i] = s[-1-i]
            s[-1-i] = temp
        # 也可以写成：
        #   s[i], s[-1-i] = s[-1-i], s[i]

```