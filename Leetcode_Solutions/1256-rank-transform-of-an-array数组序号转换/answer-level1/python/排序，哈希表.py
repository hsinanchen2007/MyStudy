### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr_sort=sorted(list(set(arr)))

        hashmap={}

        for ind,i in enumerate(arr_sort):
            hashmap[i]=ind+1
        
        ans=[]
        for i in arr:
            ans.append(hashmap[i])
        
        return ans
```