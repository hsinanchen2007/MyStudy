### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans=[]
        intervals.sort(key=lambda x:x[0])
        for i in intervals:
            if ans==[]:
                ans.append(i)
                continue
            if i[0]>ans[-1][1]:
                ans.append(i)
                continue
            if i[0]<=ans[-1][1]:
                ans[-1][1]=max(i[1],ans[-1][1])
                continue
        return ans

```