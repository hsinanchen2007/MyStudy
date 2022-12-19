### 解题思路
要求第n个s字符串只需分析第n-1个字符串：

创建一个栈（用其他结构可能更好）
遍历字符串：
1.当字符与栈内字符相同或者栈为空时入栈
2.当字符与栈内字符不相同时，取栈的长度+栈内字符，清空栈并将新的元素入栈
（注意：最后栈不为空所以在循环结束后需要在进行一次取栈的长度+栈内字符的操作）

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        num = []
        num.append("")
        num.append("1")
        if n==1: return num[1]
        for i in range(2,n+1):
            p = []
            s = ""
            for x in num[i-1]:
                if p==[] or x==p[0]:
                    p.append(x)
                else:
                    s += str(len(p))
                    s += p[0]
                    p = []
                    p.append(x)
            s += str(len(p))
            s += p[0]
            num.append(s)
        
        return num[n]

            
            
```