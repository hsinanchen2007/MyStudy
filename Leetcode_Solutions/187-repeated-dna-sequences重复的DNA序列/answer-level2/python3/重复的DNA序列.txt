### 解题思路
1. 遍历整个字符串`s`，将长度为10的子串保存在字典中，键为相应的子串，键值为键出现的次数；
2. 将出现次数超过1次的子串保存在集合res中，最后转换成列表返回即可；

### 代码

```python3
class Solution:
    """
    利用哈希表保存子串；
    """
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) < 11:
            return []
        
        # 遍历字符串s，将长度为10的连续子串保存在hash_table中；
        # 将出现次数超过一次的保存到res中最后返回即可；
        res, hash_table = set(), dict()
        for i in range(len(s)-9):
            try:
                hash_table[s[i:i+10]] += 1
                res.add(s[i:i+10])
            except:
                hash_table[s[i:i+10]] = 1
        return list(res)
            
```