## 思路:

没什么好说的！

一行代码！

使用 `Counter`，

其中`most_common`([*n*])返回一个列表，其中包含 *n* 个最常见的元素及出现次数，按常见程度由高到低排序。

## 代码:

```python
class Solution:
    def frequencySort(self, s: str) -> str:
        return "".join(k * v for k, v in collections.Counter(s).most_common())
```

