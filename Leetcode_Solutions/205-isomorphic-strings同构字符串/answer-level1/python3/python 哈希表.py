### 解题思路
创建哈希表作为映射

### 代码

```python3
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hashmap={}
        for i,j in zip(s,t):
            if i in hashmap and hashmap[i]!=j:
                return False
            elif i not in hashmap and j in hashmap.values():
                return False
            hashmap[i]=j
        return True


       
```