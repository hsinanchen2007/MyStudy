### 解题思路
虽然时空复杂度很高。。但是作为小白还是写一遍过过脑子。。。先建立一个栈stack，再建一个已经含有'(':')','[':']','{':'}'的字典mapping。
用i遍历s，判断i属于前括号还是后括号，如果属于前括号就向栈中添加i，如果属于后括号，就需要判断栈是否为空，如果是空的，说明前方没有与之对应的前括号，返回False。如果栈不为空，则把栈顶元素取出返回给value，接着判断取出的value是否为i所对应的前括号。
循环结束后，需要判断栈中是否有剩余元素，因为s中最后一个如果是前括号的话、就成了剩余元素

### 代码

```python3
class Solution:  
    def isValid(self, s: str) -> bool:
        jieguo = True
        stack = []
        mapping = {'(':')','[':']','{':'}'}
        for i in s:
            if i=='(' or i=='[' or i=='{':
                stack.insert(0,i)
            elif i==')' or i==']' or i=='}':
                if stack:
                    value = stack.pop(0)
                    if i != mapping[value]:
                        jieguo = False
                        return(jieguo)
                else:
                    jieguo = False
                    return(jieguo)
        if stack:
            jieguo = False
            return(jieguo)
        return(jieguo)

                




```