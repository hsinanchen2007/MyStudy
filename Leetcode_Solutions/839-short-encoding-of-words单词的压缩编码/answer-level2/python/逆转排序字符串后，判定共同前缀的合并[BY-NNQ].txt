### 解题思路
> 因为要求最终的编码后字符串加上索引能够还原原来的单词列表，而且索引中只记录了单词的起始位置，所以隐藏的含义就是输出的最短字符串可以将尾部字符完全相同的字符串合并起来，公用一个单词；
- 1. 为了方便计算比较，将字符串逆转，然后排序；
- 2. 排序后的字符串只需要将有共同前缀的合并即可，且排序后短的在前面，只有发生变化时就记录原来最长的单词即可；
- 3. 别忘了处理最后一个字符串；

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        if not words:
            return 0
        rev_words = [s[::-1] for s in words]
        rev_words.sort()
        ans = 0
        for i in range(1, len(rev_words)):
            if not rev_words[i].startswith(rev_words[i - 1]):
                ans += len(rev_words[i - 1]) + 1

        ans += len(rev_words[-1]) + 1
        return ans
```

### 运行情况
```
执行用时 :124 ms, 在所有 Python3 提交中击败了90.76%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了8.33%的用户
```