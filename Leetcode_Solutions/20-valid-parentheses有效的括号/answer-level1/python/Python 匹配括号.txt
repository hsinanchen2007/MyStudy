### 解题思路
此处撰写解题思路
可以创建一个栈，遍历字符串。
将第一个元素入栈，
从第二个元素开始，与前一个元素进行配对：
    如果配对成功：
        将前一个元素出栈
    如果配对不成功：
        将这个元素加入到栈中

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        a = []
        for i in s:
            if len(a) == 0:
                a.append(i)
                continue
            
            if (a[len(a)-1]=="(" and i == ")") or(a[len(a)-1]=="[" and i == "]") or(a[len(a)-1]=="{" and i == "}") :
                a.pop()
                continue

            a.append(i)
        
        if len(a) == 0:
            return True
        else:
            return False

```