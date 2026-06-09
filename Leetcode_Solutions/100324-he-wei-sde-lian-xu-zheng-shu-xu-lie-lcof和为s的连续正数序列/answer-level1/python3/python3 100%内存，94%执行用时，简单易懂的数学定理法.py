### 解题思路
题目要求是要找连续数据
因此（left+right）/2*（right-left+1）=target 的时候符合题目要求
因此得到下面的规律~~

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        n=2
        result=[]
        while (n*n//2)<=target:
            if target%n==0:     
                left=target//n-n//2
            else:
                left=target//n-n//2+1
            
            right=left+n-1
            if (left+right)*n==target*2:
                result.insert(0,list(range(left,right+1)))
            n+=1
        return result 
          
```