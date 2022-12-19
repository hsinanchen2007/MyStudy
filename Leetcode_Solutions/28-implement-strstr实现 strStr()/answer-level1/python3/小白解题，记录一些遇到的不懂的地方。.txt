### 解题思路
此处撰写解题思路
数组取特定个数的元素，后一个下标是开区间的，例如a[0:1]其实只取里下标为0的元素。
另外，下标的范围要超出数组长度才能取到最后一个元素，也就是要写成for i in range(len(haystack)-le+1)。
### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle or haystack==needle:
            return 0
        le=len(needle)
        if len(haystack)<le:
            return -1
        for i in range(len(haystack)-le+1):
            if haystack[i:i+le]==needle:
                return i
        return -1
```