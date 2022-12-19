### 解题思路
逐个遍历

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        if len(strs) == 0:
            return ""
        comm_str = ""
        pre_has_comm = True
        for pos in range(len(strs[0])):
            has_comm = True
            for i in range(1, len(strs)):
                if len(strs[i]) <= pos or len(strs[i]) > pos and strs[0][pos] != strs[i][pos]:
                    has_comm = False
                    pre_has_comm = False

            if has_comm and pre_has_comm:
                comm_str += strs[0][pos]
        return comm_str
```