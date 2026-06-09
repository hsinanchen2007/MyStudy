### 解题思路
此处撰写解题思路

### 代码

1. 先求数组长度。
2. 再求数组中每个元素出现的次数。
3. 对次数排序
4. 从大到小遍历，依次累加，直到超过长度的一半
5. 返回累加了几个数

```python
import collections
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = collections.Counter(arr)
        l = len(arr)
        x = list(cnt.values())
        x.sort(reverse=True)
        ans = 0
        c = 0
        while c < l / 2:
            c += x[ans]
            ans += 1
        return ans
```