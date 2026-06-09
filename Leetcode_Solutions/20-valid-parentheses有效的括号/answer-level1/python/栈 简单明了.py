### 解题思路
采用栈的形式

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        #首先判断字符串为空的特殊情况
        if len(s)==0:
            return True
        #创建字典与空的列表
        zidian={'(':')','[':']','{':'}'}    
        l=[]
        for i in s:
            #当为键值时，弹入
            if i in zidian.keys():
                l.append(i)
            #当不为键值且与字典对应时，弹出最后元素
            elif len(l)!=0 and i==zidian[l[-1]]:
                l.pop() 
            else:
                return False
        return len(l)==0
```