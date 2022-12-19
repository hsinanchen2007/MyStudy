### 解题思路
核心是使用不满足个数的字符串对字符串进行切分，然后再对各个分割后的字符串进行判断，是否满足条件。

### 代码

```python3
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        len_list = []
        def helper(st):
            char_dict = {}
            if len(st) < k:
                return
            for c in st:
                if c in char_dict:
                    char_dict[c] += 1
                else:
                    char_dict[c] = 1
            #print char_dict
            for c in char_dict:
                #print c, char_dict[c] 
                if char_dict[c] < k:
                    st = st.replace(c, '_')
                    #print st

            if '_' not in st:
                len_list.append(len(st))
                return
            seg = st.split('_')
            for item in seg:
                helper(item)
        helper(s)
        max_len = 0
        if len(len_list) == 0:
            return 0
        else:
            max_len
            for x in len_list:
                if x > max_len:
                    max_len = x

        return max_len
```