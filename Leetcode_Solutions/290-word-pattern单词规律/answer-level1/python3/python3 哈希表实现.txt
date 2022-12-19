### 解题思路
建立哈希表，储存pattern中每个字母和str中每个单词的一一对应关系
遍历一次即可

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        strs = str.split(' ')
        if len(strs) != len(pattern):
            return False
        hashmap={}
        for i in range(len(strs)):
            if strs[i] not in hashmap and pattern[i] not in hashmap.values():
                hashmap[strs[i]] = pattern[i]
            elif strs[i] not in hashmap or pattern[i] not in hashmap.values() or hashmap[strs[i]] != pattern[i]:
                return False
        return True

```