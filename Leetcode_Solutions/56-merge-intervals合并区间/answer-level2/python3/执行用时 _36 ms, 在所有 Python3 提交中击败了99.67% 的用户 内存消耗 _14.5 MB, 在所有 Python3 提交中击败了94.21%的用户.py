### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals)==0:
            return intervals
        else:
            intervals=sorted(intervals,key= lambda t:t[0])
            result=[]
            result.append(intervals[0])
            for lis in intervals[1:]:
                if lis[0]>result[-1][1]:
                    result.append(lis)

                elif lis[1]>result[-1][1]:
                    result[-1][1]=lis[1]   
            return result

                
    
```