### 解题思路
利用哈希表计数，键为索引值，键值为1的个数

### 代码

```python
class Solution(object):
    def kWeakestRows(self, mat, k):
        dic = {}
        ans = []
        for i,c in enumerate(mat):
            dic[i] = c.count(1)
        d_sort = sorted(dic.items(),key = lambda x:x[1])#按照键值进行排序
        for c in d_sort:
            if k != 0:
                ans += [c[0]]
                k -= 1
        return ans
```