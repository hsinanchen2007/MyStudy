### 解题思路
1. 遍历每个字符的最长不重复字符串。
2. 滑动窗口，遇到有重复时更新窗口起点和字典。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 6: 52ms, 13.8MB
        max_len_ideal = len(set(s))
        max_len_real = 0
        lstr = {}
        start = 0
        # curr_len = 0

        for i in range(len(s)):

            if (s[i] in lstr) and (lstr[s[i]] >= start):
                curr_len = i - start
                start = lstr[s[i]] + 1
            else:
                curr_len = i - start + 1

            lstr[s[i]] = i

            if curr_len == max_len_ideal:
                return max_len_ideal
            elif curr_len > max_len_real:
                max_len_real = curr_len

        return max_len_real
        # -------------------------------------------------
        # 5: 40ms, 13.8MB
        # max_len_ideal = len(set(s))
        # max_len_real = 0
        # lstr = {}
        # start = 0
        # # curr_len = 0

        # for i in range(len(s)):

        #     if (s[i] not in lstr) or (lstr[s[i]] < start):
        #         curr_len = i - start + 1
        #     else:
        #         curr_len = i - start
        #         start = lstr[s[i]] + 1

        #     lstr[s[i]] = i

        #     if curr_len == max_len_ideal:
        #         return max_len_ideal
        #     elif curr_len > max_len_real:
        #         max_len_real = curr_len

        # return max_len_real
        # -------------------------------------------------
        # 4: 80ms, 13.7MB
        # max_len_ideal = len(set(s))
        # max_len_real = 0

        # for i in range(len(s)):
        #     lstr = {s[i]: 0}
        #     for letter in s[i+1:]:
        #         if letter not in lstr:
        #             lstr[letter] = 0
        #         else:
        #             break
                    
        #     if len(lstr) == max_len_ideal:
        #         return max_len_ideal
        #     elif len(lstr) > max_len_real:
        #         max_len_real = len(lstr)

        # return max_len_real
        # -------------------------------------------------
        # 3: 124ms, 13.7MB
        # max_len_ideal = len(set(s))
        # max_len_real = 0

        # for i in range(len(s)):
        #     lstr = s[i]
        #     for letter in s[i+1:]:
        #         if letter not in lstr:
        #             lstr = lstr + letter
        #         else:
        #             break
                    
        #     if len(lstr) == max_len_ideal:
        #         return max_len_ideal
        #     elif len(lstr) > max_len_real:
        #         max_len_real = len(lstr)

        # return max_len_real
        # -------------------------------------------------
        # 2: 348ms, 13.6MB
        # max_len = 0
        # for i in range(len(s)):
        #     lstr = s[i]
        #     for letter in s[i+1:]:
        #         if letter not in lstr:
        #             lstr = lstr + letter
        #         else:
        #             break
        #     if len(lstr) > max_len:
        #         max_len = len(lstr)
        # return max_len
        # -------------------------------------------------
        # 1: 336ms, 13.8MB
        # candidate = [0]
        # for i in range(len(s)):
        #     lstr = s[i]
        #     for letter in s[i+1:]:
        #         if letter not in lstr:
        #             lstr = lstr + letter
        #         else:
        #             break
        #     candidate.append(len(lstr))
        # return max(candidate)
```