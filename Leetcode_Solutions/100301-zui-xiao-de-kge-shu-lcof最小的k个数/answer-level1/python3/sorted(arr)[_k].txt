### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not arr or not k:
            return []
        sorted_lis=sorted(arr)
        res=[]
        for val in sorted_lis:
            res.append(val)
            k-=1
            if k==0:
                break
        return res

```