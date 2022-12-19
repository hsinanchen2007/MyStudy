正序遍历，倒序遍历可能会快点
```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = 0
        result = []
        count = 0  # 计数单词长度
        if len(s) == 0:  # 空字符串
            return 0
        while i < len(s):
            if s[i] != ' ':
                count += 1  # 字符不为空即是单词，计数单词长度
                i += 1
            else:
                result.append(count)  # 将已知的单词长度记录
                count = 0  # 准备下一个单词长度计数
                i += 1
        result.append(count)  # 避免单字符的字符串无法被记录单词长度
        for i in range(len(result)-1, -1, -1):  # 找最后一个单词的长度
            if result[i] != 0:
                return result[i]
        if result[0] == 0:  # 长度全为0的情况
            return 0     
```
