### 解题思路
用两个栈就可以轻松的实现了，为啥周赛的时候脑袋和短路了一样啊啊啊

### 代码

```python
class Solution(object):
    def sortString(self, s):
        """
        :type s: str
        :rtype: str
        """
        li = list(s)
        li.sort(reverse=True)
        stack1, stack2 = li, []
        res = []
        while stack1 or stack2:
            while stack1:
                if len(stack1) == 1 or stack1[-1] != stack1[-2]:
                    res.append(stack1.pop())
                else:
                    stack2.append(stack1.pop())

            while stack2:
                if len(stack2) == 1 or stack2[-1] != stack2[-2]:
                    res.append(stack2.pop())
                else:
                    stack1.append(stack2.pop())
        
        return ''.join(res)
                    


```