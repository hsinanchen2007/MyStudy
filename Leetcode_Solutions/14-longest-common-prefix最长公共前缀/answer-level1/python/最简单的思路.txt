**直接看代码：**
```
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        get max prefix
        :type strs: List[str]
        :rtype: str
        """
        if not len(strs):
            return ''

        min_len_str = min([len(s) for s in strs])  # min len of str

        common_prefix = ''
        for i in range(min_len_str):
            # provide a num 0-min_len_str, for example: 0
            common = ''
            for st in strs:
                # compare every str[i]
                if not common:
                    common = st[i]
                else:
                    if not st[i] == common:
                        return common_prefix

            common_prefix += common
        return common_prefix
```

