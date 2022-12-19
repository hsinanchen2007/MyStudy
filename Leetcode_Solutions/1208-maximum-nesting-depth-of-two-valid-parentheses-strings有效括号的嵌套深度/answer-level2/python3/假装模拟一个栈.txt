### 解题思路
模拟一个栈,i表示栈长度,如果为'('就向栈中添加,并i+1 如果为')'就向栈中减少,并i-1,像'()(())()'用栈长i表示就是'10121010'
如果'('对应的i为奇数,就将其分给A,为偶数就分给B,如果')'对应i为偶数就分给A,为奇数就分给B

### 代码
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) :
        ret=[]
        i=0
        for k in seq:
            if k=='(':
                i+=1
                if i % 2 == 0:
                    ret.append(1)
                else:
                    ret.append(0)  #可以直接写成ret.append(1-i%2)
            if k==')':
                i-=1
                if i%2==0:
                    ret.append(0)
                else:
                    ret.append(1)  #可以直接写成ret.append(i%2)
        return ret
```

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) :
        ret=[]
        i=0
        for k in seq:
            if k=='(':
                i+=1
                ret.append(1-i%2)      
            if k==')':
                i-=1
                ret.append(i%2)
        return ret
```