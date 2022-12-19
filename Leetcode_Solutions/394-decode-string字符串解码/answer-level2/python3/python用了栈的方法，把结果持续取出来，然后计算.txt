### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for i in s:
            if i != "]":
                stack.append(i)
            else:
                list_temp = []               
                #找字母
                while stack  and stack[-1] !="[":                              
                    list_temp.append(stack.pop())
                #取出[
                stack.pop()
                list_temp = list_temp[::-1]
                temp = "".join(list_temp)
                # 找数字
                time = ""
                while stack and  stack[-1].isdigit() and stack[-1]!="[":
                    time += stack.pop()               
                time = int(time[::-1])
                stack.append(time * temp)
        return "".join(stack)


```