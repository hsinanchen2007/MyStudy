### 解题思路
递归
这种题击中了我的死穴，想的头疼
最简单的方法解决，肯定有非常简单的，想不出来

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return '1'
        if n==2:
            return '11'    
        preNum=self.countAndSay(n-1)
        curNum=''
        count=1
        for i in range(1,len(preNum)):
            if preNum[i]!=preNum[i-1]:
                curNum+=str(count)+preNum[i-1]
                count=1
            else:
                count+=1
        curNum+=str(count)+preNum[-1]
        return curNum
```