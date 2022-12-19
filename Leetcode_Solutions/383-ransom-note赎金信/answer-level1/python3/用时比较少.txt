### 解题思路
![WX20200226-134430@2x.png](https://pic.leetcode-cn.com/5127acdc9da4ec22ad275c409d180d8a11d0bacf4b837413046d5b1c04bc4203-WX20200226-134430@2x.png)
此处撰写解题思路

### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if ransomNote is None:
            return True
        for i in ransomNote:
            if i in magazine:
                magazine = magazine.replace(i, '', 1)
            else:
                return False
        return True
```