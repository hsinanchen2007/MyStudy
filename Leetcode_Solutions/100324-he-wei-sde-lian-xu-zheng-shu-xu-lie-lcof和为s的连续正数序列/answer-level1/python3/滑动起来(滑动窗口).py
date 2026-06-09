### 解题思路
使用滑动窗口，控制左右边界和sum与target的关系

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:

        i=1
        j=1
        tmp=0
        res=[]

        while i<=target//2:
            if tmp<target:
                tmp+=j
                j+=1
            elif tmp>target:
                tmp-=i
                i+=1
            else:
                arr=list(range(i,j))
                res.append(arr)
                tmp-=i 
                i+=1

        return res
```