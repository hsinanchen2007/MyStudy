### 解题思路
1. 拿出第一个str，然后遍历每一个是否相等
2. 通过zip进行操作，将字符串的每个序列组成list，通过set看是否是同一个字母

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # if not strs: 
        #     return ""
        # for i in range(len(strs[0])):
        #     for j in range(1, len(strs)):
        #         if len(strs[j]) <= i or strs[j][i] != strs[0][i]:
        #             return strs[0][:i]
        # return strs[0]

        res = ""
        for i in zip(*strs):
            if len(set(i)) == 1:
                res += i[0]
            else:
                break
        return res
```