### 解题思路
同习题 [242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

[299. 猜数字游戏](https://leetcode-cn.com/problems/bulls-and-cows/solution/gelthin-ji-shu-shu-zu-by-gelthin/)

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        str_hash = dict()
        for x, y in zip(s1, s2):
            if x not in str_hash:
                str_hash[x] = 1
            else:
                str_hash[x] += 1
            if y not in str_hash:
                str_hash[y] = -1
            else:
                str_hash[y] -= 1
        for v in str_hash.values():
            if v != 0:
                return False
        return True

    
```