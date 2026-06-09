### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        return list(map(lambda x: x[0] ,sorted(sorted(map(lambda x:(x[0],x[1],x[1].count(1)),iter(enumerate(mat))),key=lambda x:x[0]),key=lambda x: x[2])[:k]))
```
![图片.png](https://pic.leetcode-cn.com/c9d8a9023d495dfd3908ac0d486b35e6f7e95c69d53fe3a6d40dc5414d9430f9-%E5%9B%BE%E7%89%87.png)
