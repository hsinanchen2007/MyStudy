### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        c1=collections.Counter(magazine)
        c2=collections.Counter(ransomNote)
        return True if all(c1[i]>=c2[i] for i in c2) else False

本题中应该遍历c2而不是c1,因为如果遍历c1,c1（magazine）中会有不在c2中的字符,这时c2[i]会有KeyError.
```