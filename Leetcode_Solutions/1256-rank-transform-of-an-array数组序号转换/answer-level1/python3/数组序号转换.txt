### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        sortedArr = sorted(list(set(arr)))   # 先去重，再排序
        hashmap = {}
        for i,ele in enumerate(sortedArr):
            hashmap[ele]  = i + 1
        return [hashmap[i] for i in arr]
            



            
            


```