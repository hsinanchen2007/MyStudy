### 解题思路
就是判断B是否为A+A的子串，主要是因为A中两部分元素交换顺序，这两部分元素间的顺序没有改变。
双指针，对A+A中前l1 - l2 + 1个元素去遍历，判断B是否为从当前元素开始的子串

### 代码

```python
class Solution(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B): 
            return False
        haystack=A+A
        needle=B
        if len(haystack) < len(needle): 
            return False
        l1 = len(haystack)
        l2 = len(needle)
        for i in range(l1 - l2 + 1):
            count = 0
            while count < l2 and haystack[i + count] == needle[count]:
                count += 1
            if count == l2:
                return True
        return False
        
```