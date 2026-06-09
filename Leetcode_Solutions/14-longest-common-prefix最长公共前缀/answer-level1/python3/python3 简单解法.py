![image.png](https://pic.leetcode-cn.com/8ba39e113366d4c8d3a1f07e4f37027d67df14c58803add18f5b0ddb01a82aa5-image.png)

```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:     
        s = ""
        for i in zip(*strs):
            if len(set(i)) == 1:
                s += i[0]
            else:
                break           
        return s    
```




