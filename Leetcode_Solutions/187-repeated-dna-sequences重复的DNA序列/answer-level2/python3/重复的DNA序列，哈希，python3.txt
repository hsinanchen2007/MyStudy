### 解题思路
定义字典dic存储序列出现的次数
用集合res存储结果
遍历字符串s，每次取出连续10个字符的字符串
如果当前取出的字符串没在字典中出现过，则以该字符串为键，值设为1
如果当前取出的字符串在字典中出现过，则该字符串为键对应的值加1
往res里添加结果

最终dic里存的是每种10个字符连续的序列出现的次数（虽然题目没要这个结果）
返回list(res)

### 代码

```python3
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        dic = {}
        res = set()
        for i in range(len(s)-9):
            if s[i:i+10] not in dic:
                dic[s[i:i+10]] = 1
            else:
                dic[s[i:i+10]] += 1
                res.add(s[i:i+10])
        return list(res)
```