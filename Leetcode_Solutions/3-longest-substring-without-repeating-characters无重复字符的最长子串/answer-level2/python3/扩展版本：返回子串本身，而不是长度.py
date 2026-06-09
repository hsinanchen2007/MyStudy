前几天接到某厂电面，是这道题原题。但是面试官让返回的是无重复字符的最长子串。下面提供一下我的思路：

- 建立数组`arr[]`用于dp。`arr[i]`代表以`oriStr[i]`结尾的最长无重复子串的起始索引值，即从第几个字符起到第i个字符可以构成最长无重复子串。如，‘abcabcbb’的`arr[]`为[0, 0, 0, 1, 2, 3, 5, 7]，等价于最长子串分别为['a','ab','abc','bca','cab','abc','cb','b']。

- 下面我们要做的就是，已知前i-1位的`arr`，怎么求`arr[i]`。我们从i-1位向前遍历`arr`，如果第j位和第i位的字符相等，那么`arr[i]`就等于j+1，然后break。值得注意的是，这只考虑了第i位的字符，我们还要照顾到其它字符会不会重复，所以建立变量`start`，初始化为0，表示我们允许`arr[i]`的值最小可以是0，在遍历的过程中，实时令`start=max(start,arr[j])`，这样就把第j位的起始索引考虑进去了。当我们遍历到了`start`前面，也break。

- `i - arr[i] + 1`即为子串长度，比较一下就可以找出最长的那个。如果存在多个解，我返回的是第一个。

- 所以算法分为两步：1.动态规划，建立`arr`。2.根据`arr`找出最长的子串。

```python []
class Solution:
    def lengthOfLongestSubstring(self, oriStr: str) -> str:
        arr = [0 for i in range(len(oriStr))]
        # step 1 dp
        for i in range(1, len(oriStr)):
            start = 0
            for j in range(i-1, -1, -1):
                start = max(start, arr[j])
                if oriStr[i] == oriStr[j]:
                    arr[i] = j + 1
                    break
                if j == start:
                    arr[i] = start
                    break
        # step 2 find the longest one
        maxLen = 0
        maxIndex = 0
        for i in range(len(oriStr)):
            if i - arr[i] > maxLen:
                maxLen = i - arr[i]
                maxIndex = i
        return oriStr[maxIndex-maxLen:maxIndex+1]
```




    复杂度分析：
    时间复杂度: O(nk)，n为原字符串长度，k为最长子串长度。
    空间复杂度：O(n)。


回到leetcode原题，如果只是返回长度的话，滑窗法O(n)的时间复杂度即可解决。也贴一下代码。

```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == '':
            return 0
        window = set()
        left = 0 
        max_len = 0
        cur_len = 0
        
        for ch in s:
            cur_len += 1
            while ch in window:# 从前向后删除，直到删除了ch
                window.remove(s[left])
                left += 1
                cur_len -= 1
            if cur_len > max_len:
                max_len = cur_len
            window.add(ch)
        return max_len
            
```

如果大家有更好的解法，欢迎讨论分享~
