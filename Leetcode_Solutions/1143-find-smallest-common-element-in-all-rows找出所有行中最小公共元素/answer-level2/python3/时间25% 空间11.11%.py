### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        dic = collections.defaultdict(int)
        for row in mat:
            for n in row:
                dic[n]+=1
                if dic[n]==len(mat):
                    return n
        return -1
```