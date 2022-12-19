### 解题思路
1. 暴力搜索，针对每个在赎金信中的字符，在杂志中进行查找比对，找到就消去杂志中的对应字符，直到全部匹配返回True。时间复杂度o(n^2)，空间复杂度o(1)
2. 先用字典存储杂志中的字符，然后赎金信的字符进行匹配。时间复杂度o(n)，空间复杂度o(n)

以下代码即第二种方法：
### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict1 = {}
        result = 1
        for x in magazine:
            if x not in dict1:
                dict1[x] = 1
            else:
                dict1[x] += 1
        
        for x in ransomNote:
            if x in dict1:
                dict1[x] -= 1
                if dict1[x] == 0:
                    del dict1[x]
            else:
                result = 0
        return result
```