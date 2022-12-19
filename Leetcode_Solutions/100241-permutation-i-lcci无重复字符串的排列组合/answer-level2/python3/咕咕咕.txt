### 解题思路

只会写数字排列组合不会写字母排列组合的我

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:

        i = 0
        perms = [S[i]]   
        for n in S[1:]:
            new_perms = []
            for perm in perms:
                for i in range(len(perm)+1):   
                    new_perms.append(perm[:i] + n + perm[i:])   
            perms = new_perms
        
        return perms
```