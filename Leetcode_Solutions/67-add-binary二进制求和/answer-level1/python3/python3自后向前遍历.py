### 解题思路
自后向前遍历，长度为最长的字符串长度。
设置进位初始值为0，在遍历过程中根据计算结果不断改变进位值。
遍历完成后，若进位值为1，则在字符串结果的首位再插入字符‘1’。

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        length=max(len(a),len(b))
        res=''
        jinwei=0
        for i in range(-1,-length-1,-1):
            if i<-len(a):
                temp=int(b[i])+jinwei
            elif i<-len(b):
                temp=int(a[i])+jinwei
            else:
                temp=int(a[i])+int(b[i])+jinwei
            if temp>1:
                res=str(temp-2)+res
                jinwei=1
            else:
                res=str(temp)+res
                jinwei=0
        if jinwei==1:
            res='1'+res
        return res
```