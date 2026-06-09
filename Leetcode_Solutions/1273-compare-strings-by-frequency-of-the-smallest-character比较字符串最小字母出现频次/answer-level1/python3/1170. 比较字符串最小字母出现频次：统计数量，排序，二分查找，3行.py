![image.png](https://pic.leetcode-cn.com/3c7882136a1ec1cbbe7f69ad272dc37fcd9fa64634b956795e5421ca2b58dc1b-image.png)

时间复杂度$O(2\sum_{i=0}^{W}words[i].length + WlogW + 2\sum_{i=0}^{Q}queries[i].length + QlogW)$，其中W是words的长度，Q是queries的长度。

```python []
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        f = lambda x: x.count(min(x))               #统计函数f
        n, ws = len(words), sorted(map(f, words))   #对words的f生成结果进行排序
        return [n - bisect.bisect(ws, i) for i in map(f, queries)] #根据二分查找的坐标确定每个queries值符合条件的数量
```
