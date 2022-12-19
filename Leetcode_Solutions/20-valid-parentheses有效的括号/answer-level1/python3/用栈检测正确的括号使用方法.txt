### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        # s ---> True or False
        # True ---> ([{}])
        # True ---> " "
        # False ---> {] 
        # False ---> ([)]
        # 检验过程和栈十分相似
        # 1. 栈初始化位A
        # 1. 左括号进栈，遇到右括号判断栈顶元素是否为其对应的左括号若为，栈顶弹出，若不为# # return False
        # python 中没有栈，使用list模拟
        # 伪代码应该写，确保每行实现没有问题
        if s == "":
            return True
        stack = []
        symbol = {')':'(', ']':'[', '}':'{'}
        for char_s in s:
            if char_s in ['(', '[', '{']:
                #左括号
                stack.insert(0, char_s)
                print(len(stack))
            if char_s in [')',']','}']: 
                if len(stack)==0:
                    print("12")
                    return False
                print("hh", symbol[char_s])
                if symbol[char_s] != stack[0]:

                    return False
                del stack[0]
        if len(stack)!=0:
            return False
        return True

                
```