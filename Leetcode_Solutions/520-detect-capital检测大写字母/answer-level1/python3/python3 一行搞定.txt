![image.png](https://pic.leetcode-cn.com/91aa50eb93f94a22c0c19cc30da654bf2c350b8c6ec67dec65d39d161123dd24-image.png)
```
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.isupper() or word.islower() or word.istitle()
```

