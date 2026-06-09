### 解题思路
此处撰写解题思路
1. 找出最短的那个字符串，以它为准平行查找；
2. 躲坑：把strs为空的情况，以及最短字符串为空的情况先设为空；
3. 平行查找：以最短字符串首字母开始找，每个字符串首字母组成列表lst，并用set去重，每次比较如果去重之后剩一个元素，则记录在另一个列表final_lst中，并清空lst列表。
4. 最后生成的若干字母用join拼接即可
### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        from functools import reduce
        if strs:
            shortS = reduce(lambda x, y: x if len(x) < len(y) else y, strs)
            if len(strs) < 1:
                return ''
            elif len(strs) == 1:
                return shortS
            else:
                if len(shortS)<1:
                    return ''
                else:
                    final_lst = []
                    lst = []
                    for i in range(len(shortS)):
                        for j in range(len(strs)):
                            lst.append(strs[j][i])
                        if len(set(lst)) <= 1:
                            final_lst.append(shortS[i])
                            lst.clear()
                        else:
                            break
                    return ''.join(final_lst)
        else:
            return ''
```