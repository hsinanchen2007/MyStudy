### 解题思路
* 用Counter统计出现次数，most_common函数将出现次数从大到小排序。
* 循环遍历加入列表a中，用join函数组合

### 代码

```python
class Solution(object):
    def frequencySort(self, s):
        from collections import Counter
        m = Counter(s).most_common()
        a = []
        for i,j in m:
            a += i*j
        return "".join(a)
```