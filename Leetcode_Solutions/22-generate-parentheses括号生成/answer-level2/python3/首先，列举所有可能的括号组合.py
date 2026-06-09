### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        source = ['(',')']
#判断输出的序列是否满足要求
        def isAvilable(s:str): 
            n = len(s)
            cnt = 0
            for i in range(n):
                if(cnt<0):
                    return False
                if s[i]=='(' : cnt+=1
                elif s[i]==')' : cnt-=1
            if cnt!=0 : return False
            else :return True
 #回溯法输出所有序列
        def trackBack(conbination,length):
            if length == 0 and isAvilable(conbination):
                res.append(conbination)
            elif length>0:
                 for letter in source:
                     trackBack(conbination+letter,length-1)
                
        res = []
        trackBack('',2*n)
        return res
```