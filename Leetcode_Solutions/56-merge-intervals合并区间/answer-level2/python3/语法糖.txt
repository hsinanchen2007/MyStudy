### 解题思路
排序,然后遍历

### 代码

```python3
class Solution:
    def merge(self, lst: List[List[int]]) -> List[List[int]]:
        lst.sort(key=lambda x:x[0])
        print(lst)
        n=len(lst)
        ans=[]
        if n==0:
            return ans
        templst=lst[0]
        j=1
        while j<n:
            if lst[j][0]>templst[1]:
                ans.append(templst)
                templst=lst[j]

            else:
                if templst[1]<=lst[j][1]:
                    
                    templst=[templst[0]]+[lst[j][1]]
                else:
                    templst=[templst[0]]+[templst[1]]
              
            j+=1
        ans.append(templst)
        return ans
```