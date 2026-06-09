### 解题思路
从前往后遍历，i 代表当前子串的起始点，j代表终点 + 1 的位置。
使用集合 st 存储当前字串中出现过的字母，如果 j 上的字母在集合中，直接从 i 开始迭代，找到第一个这个字母，从集合里删掉。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        st = set(s[0])
        max_len = 1
        cur_len = 1
        i = 0
        j = 1
        while j < len(s):
            #print(i, j, st, s[j])
            if s[j] not in st:
                #print('\tadd', s[j])
                st.add(s[j])
            else:
                while s[i] != s[j]:
                    #print('\t', 'remove', s[i])
                    st.remove(s[i])
                    i += 1
                    cur_len -= 1
                i += 1
                cur_len -= 1
            cur_len += 1
            max_len = max(max_len, cur_len)
            j += 1
        return max_len
```