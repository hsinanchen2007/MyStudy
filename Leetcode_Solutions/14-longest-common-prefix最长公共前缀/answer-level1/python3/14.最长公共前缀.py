先找到最短的字符串去遍历list中每个字符的相同位置字符是否一致。同时动态修改相同字符边界
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        if len(strs)==0:
            return ''

        # 寻找最短字符
        len_list = []
        for i in strs:
            len_list.append(len(i))
        base_str = strs[len_list.index(min(len_list))]

        break_loc = min(len_list)
        for each in strs:
            for i in range(break_loc):
                if each[i] != base_str[i]:
                    if i == 0:
                        return ''
                    else:
                        # 动态修改匹配边界
                        break_loc = i
                        break

        return base_str[:break_loc]
```
