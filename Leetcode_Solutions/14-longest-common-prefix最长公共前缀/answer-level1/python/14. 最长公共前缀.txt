### 解题思路
纵向扫描即可，每一次都比较同一列的元素，如果都相同就加入到res中；若最短元素全部被扫描完，或遇到一个不相同的字符，就返回res。时间负责度为O(N*min_length)，N为元素个数，min_length为最短的元素长度，空间复杂度为O(1)。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        res = ""
        # flag = 
        for j in range(len(strs[0])):
            for i in range(1,len(strs)):
                if j>=len(strs[i]) or strs[i][j]!=strs[i-1][j]: #不存在元素或不相同
                    return res
            res+=strs[0][j]
        return res

```