### 解题思路
1. 使用一个stack, 将字符串中的元素依次入栈。
2. 每次弹出栈顶元素b，与准备入栈的字符a，作比较；能配对，则进入下一循环；否则，b,a 依次入栈。
3. 检查栈中元素长度，等于0，返回True; 大于1，则返回False。

### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        k = []
        a = b = ''

        for a in s:
            #print(a, b, k)
            if len(k) == 0:
                k.append(a)
            else:
                b = k.pop()
                if a == ')' and b == '(':
                    pass
                elif a == ']' and b == '[':
                    pass
                elif a == '}' and b == '{':
                    pass
                else:
                    k.append(b)
                    k.append(a)
           
        #print(a,b,k)
        if len(k) == 0:
            return True
        else:
            return False

```