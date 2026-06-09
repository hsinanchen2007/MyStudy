## 方法一：暴力法
#### 暴力法在本题中比哈希表快，可能跟测试的字符串有关
```Python
# 检查ransomNote的每个字符是否在magazine字符串中:
# 如果在则在maazine中移除该一个字符串；
# 如果不在，则无法构成，返回False
# 时间复杂度: O(N^2) - N（遍历ransomNote） * N（replace最糟糕的情况是遍历整个magazine）
# 空间复杂度: O(1)
class Solution(object):
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for c in ransomNote:
            if c in magazine:
                magazine = magazine.replace(c, '', 1)
            else:
                return False
        return True
```
## 方法二：哈希表
```Python
# 1. 用哈希表存储magazine字符及个数
# 2. 遍历ransomNote:
#   2.1. 如果哈希表中有该字符并且字符计数大于零，说明仍能由magzine构成，此时对应的字符计数减一
#   2.2. 否则，无法构成，返回False
# 时间复杂度: O(N) - N（遍历magazine） + 1（字典检索为O(1)）
# 空间复杂度: O(N)
class Solution2(object):
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_dict = {}
        # 哈希表存储magazine字符及个数
        for c in magazine:
            if c in magazine_dict:
                magazine_dict[c] += 1
            else:
                magazine_dict[c] = 1

        for c in ransomNote:
            if c in magazine_dict and magazine_dict[c] > 0:
                magazine_dict[c] -= 1
            else:
                return False

        return True

```
