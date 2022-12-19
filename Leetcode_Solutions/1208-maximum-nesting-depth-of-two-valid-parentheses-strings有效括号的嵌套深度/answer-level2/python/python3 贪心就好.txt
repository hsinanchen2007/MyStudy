如果当前是左括号，就把左括号给AB中左括号最少的部分，如果当前是右括号，就把右括号与给AB中含有左括号最多的部分抵消。

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        #A,B没有左括号的个数
        A,B = 0,0  
        res = [0]*len(seq)
        for i,c in enumerate(seq):
            if c=='(':
                #左括号给A
                if A<=B:
                    res[i]=0
                    A +=1
                else:
                    res[i]=1
                    B+=1
            elif c==')':
                if A>=B:
                    res[i]=0
                    A-=1
                else:
                    res[i]=1
                    B-=1
        return res
        
        
        
        
```