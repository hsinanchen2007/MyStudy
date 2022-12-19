### 解题思路
1. 哈希表，统计所有的出现的字母。可以就使用一个哈希表，计算是否等于零就可以了
2. 排序，排序后判断是否相等

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # count_word_s = dict()
        # count_word_t = dict()
        # for i in s:
        #     if i in count_word_s:
        #         count_word_s[i] += 1
        #     else:
        #         count_word_s[i] = 1
        # for j in t:
        #     if j in count_word_t:
        #         count_word_t[j] += 1
        #     else:
        #         count_word_t[j] = 1
        # return count_word_s == count_word_t
        return sorted(s) == sorted(t)
```