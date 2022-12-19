### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if len(arr)==0:
            return 0
        arr.sort()
        list1=[]
        for i in range(k):
            list1.append(arr[i])
        return list1
            
```