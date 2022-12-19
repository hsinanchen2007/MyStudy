### 解题思路
此处撰写解题思路
遇到c就让在前的ab出栈，如果最终栈为空，则true，其他为false。
因为第一个出现的c前面必须是ab，构成完整的abc。
总感觉哪里不大严谨，可是通过了QAQ
### 代码

```python3
class Solution:
    def isValid(self, S: str) -> bool:
        s=['']
        if S[0]=='c' or S[1]=='c' or len(S)%3!=0 or len(S)<3:
            return False
        for i in S:
            s+=[i]
            if s[-1]=='c':
                if s[-2]=='b' and s[-3]=='a':
                    s=s[:-3]
                else:
                    return False
        return s==['']

```