### 解题思路
zip函数

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ''
        if len(strs) == 1:
            return strs[0]
        sorted_strs = sorted(strs, key=lambda x: len(x))
        pre = ''
        index = 0
        max_index = len(sorted_strs[0])
        first_str = sorted_strs[0]
        is_break = False
        while index < max_index:
            pre = pre + first_str[index]
            is_pre = True
            for i in range(1, len(sorted_strs)):    
                if not sorted_strs[i].startswith(pre):
                    is_pre = False
                    break
            if is_pre:
                index += 1
            else:
                is_break = True
                break
        if pre == "" or (len(pre) == max_index and is_break == False):
            return pre
        return pre[ : -1]
```