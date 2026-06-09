我看了一些题解和代码，大概都与官方题解的思路相同。先计数，再根据奇偶或除二来处理。

其实无需计数，只需要记住一次曾出现的字母即可。

## 代码示例

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = 0
        repeats = set()
        for i in s:
            if i in repeats:
                repeats.remove(i)
                count += 2
            else:
                repeats.add(i)
        if repeats:
            count += 1
        return count
```

性能不够理想，可能是set的缘故。

> 执行用时 : `56 ms`, 在所有 Python3 提交中击败了`13.26%`的用户
>
> 内存消耗 : `13.6 MB`, 在所有 Python3 提交中击败了`5.32%`的用户

基于这个思路，可以进一步优化性能，比如`set`改成`list`、手工实现52个字母的hash。