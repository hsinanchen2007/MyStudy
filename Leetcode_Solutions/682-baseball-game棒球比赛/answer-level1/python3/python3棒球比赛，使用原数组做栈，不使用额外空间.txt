用pre1指向当前位置，pre2指向栈顶。
```
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        pre1=0
        pre2=-1
        total=0
        len1=len(ops)
        while pre1<len1:
            if ops[pre1]=='C':
                total-=ops[pre2]
                pre2-=1
            elif ops[pre1]=='D':
                pre2+=1
                ops[pre2]=2*ops[pre2-1]
                total+=ops[pre2]
            elif ops[pre1]=='+':
                pre2+=1
                ops[pre2]=ops[pre2-1]+ops[pre2-2]
                total+=ops[pre2]
            else:
                pre2+=1
                ops[pre2]=int(ops[pre1])
                total+=ops[pre2]
            pre1+=1
        return total
```
![image.png](https://pic.leetcode-cn.com/5d7eb64c1b6fd37d364523e67442fe0865dae229a9c5f8a20180a78d8ad1ee25-image.png)
