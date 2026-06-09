### 解题思路
    在题目理解上需要花点时间，实际上每次多用几个测试例子就能明白它的意思
    我的思路是先寻找匹配的位置再判断连续出现匹配的最大长度。
    此思路是在直接判断是否与之前括号相连出现较为困难的情况下衍生出来的
### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        lenth = len(s)
        form1 = [0]*lenth
        form2 = []
        index1 = []
        index = 0
        for i in range(lenth):
            if s[i] == '(':
                form2.append(s[i])
                index1.append(i)
            else:
                if len(form2)==0:
                    pass
                else:
                    temp = form2.pop()
                    if temp =='(':
                        index = index1.pop()
                        form1[index]=1
                        form1[i] = 1
        #寻找最长字串
        #return form1
        temp = 0
        ret = 0
        for j in range(len(form1)):
            if form1[j]!=0:
                temp+=1
            else:
                ret = max(temp,ret)
                temp = 0
        ret = max(temp,ret)       
        return ret
```