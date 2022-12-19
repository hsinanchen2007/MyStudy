**思路：**

本题与[3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)采用算法相似，都是滑动窗口。先判断字符串长度是否小于`K`，如果小于`K`则直接返回`0`。如果不小于`K`，则维护一个长度为`K`的滑动窗口，用哈希字典来存储窗口中每个字符在字符串中出现的位置。每次读进一个字符：如果已经在字典中出现，那么从字典中取出这个字符的索引，将滑动窗口内的索引前字符全部从字典中删除；如果字符未在字典中出现，那么把字符加入字典，同时窗口向右滑动。

**代码：**

```python
class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        n = len(S)
        ans = 0
        if n < K:
            return 0
        d = dict()
        length = 0
        for i in range(n):
            if S[i] in d:
                last = d[S[i]]
                for j in range(i - length, last + 1):
                    del d[S[j]]
                length = i - last
            else:
                length += 1
            d[S[i]] = i
            if length > K:
                length -= 1
                del d[S[i - length]]
            if length == K:
                ans += 1
        return ans
```