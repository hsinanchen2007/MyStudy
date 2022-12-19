### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/3b5661c70c3219ecebbe4fb444fd2cfec83ba7d96432da1e17d54fe2e87482fe-%E6%8D%95%E8%8E%B7.PNG)
双指针遍历，注意结尾！

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ""

        res=""
        i, j = 0, 0
        while j<=len(S):
            if j==len(S) or S[i]!=S[j]:
                res+=S[i]+str(j-i)
                i=j
            j+=1
        return res if len(res)<len(S) else S
```