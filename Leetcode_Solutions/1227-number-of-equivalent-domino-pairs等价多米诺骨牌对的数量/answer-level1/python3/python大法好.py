### 解题思路
转换相同，其实就是排序后相同。
将数组哈希一下，超过两次出现的，排列组合统计值就行

### 代码

```python3
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        a = []
        for i, j in dominoes:
            a.append(str(sorted([i,j])))
        ans = 0
        for k, v in dict(collections.Counter(a)).items():
            if v > 1:
                ans += v*(v-1)/2
        return int(ans)

```