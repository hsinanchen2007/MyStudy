### 解题思路
将官方的解法稍微修改了一下
因为没有看懂 top_element = stack.pop() if stack else '#'
所以就改成 if char in key and stack:
整体思想还是一样的

执行用时 :12 ms, 在所有 Python 提交中击败了98.69%的用户
内存消耗 :11.8 MB, 在所有 Python 提交中击败了59.60%的用户

### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack=[]
        key={")":"(" , "]":"[" , "}":"{"}#设置字典，用读到的后括号匹配栈中的前括号

        for char in s:
            if char in key and stack:#如果char在key的索引中，且此时stack不为空
                top=stack.pop()#将栈首的元素pop出来
                if(top != key[char]):
                    return False
            else:
                stack.append(char)
        return not stack
```