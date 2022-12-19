1. 声明一个int数组，记录 每个字母的最后一次出现的所在索引
2. 第一个循环求出各个字母的最后一次出现的所在索引
3. 第二个循环从头比较各个字母第一次出现的索引是否为最后一次的索引，是则返回改索引值，不是则将 该字母最后一次出现的所在索引 设置为-1
4. 若第二个循环结束程序仍没有返回，则表示串不含有唯一字符，返回-1

- 时间复杂度：O(n)
- 空间复杂度：O(1）

```go []
func firstUniqChar(s string) int {
    var lf [26]int
    for i, ch := range s {
        lf[ch - 'a'] = i
    }
    for i, ch := range s {
        if i == lf[ch - 'a'] {
            return i
        } else {
            lf[ch - 'a'] = -1
        }
    }
    return -1
}
```
```python []
class Solution:
    def firstUniqChar(self, s: str) -> int:
        lf = dict()
        for i, ch in enumerate(s):
            lf[ch] = i
        for i, ch in enumerate(s):
            if i == lf[ch]:
                return i
            else:
                lf[ch] = -1
        return -1
```


- 执行用时 : 8 ms, 在First Unique Character in a String的Go提交中击败了99.65% 的用户
- 内存消耗 : 5.8 MB, 在First Unique Character in a String的Go提交中击败了42.10% 的用户