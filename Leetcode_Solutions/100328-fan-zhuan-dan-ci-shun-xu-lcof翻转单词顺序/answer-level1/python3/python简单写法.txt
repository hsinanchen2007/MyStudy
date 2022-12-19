### 解题思路
1.字符串切片保存到嵌套表，在此步骤删除所有空格
2.入栈出栈，添加空格
3.尾部多出一个空格，直接返回字符串的前l-1个

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        x=s.split(" ")
        res=""
        que=[]
        for word in x:
            if word:
                que.append([word])
        for i in range(len(que)):
            temp=que.pop()
            res=res+temp[0]
            res=res+" "
        return res[:-1]
```