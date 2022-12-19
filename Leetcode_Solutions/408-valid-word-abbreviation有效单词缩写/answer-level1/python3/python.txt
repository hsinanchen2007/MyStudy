比较对应位置的字母位置是否相同。
index = 比较到的上一个index+ 数字 +1（index从1开始）
另外需要判断一些特殊情况
1. 数字从0开始，通过判断count的startswith
2. abbr以数字结尾，在abbr循环的最后再判断一次count是否为原始值，若不是则以数字结尾，看最后的index是否等于word数组最后索引+1（即数组长）
```
class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        index = -1
        count = ""
        for i in range(len(abbr)):
            if abbr[i].isalpha():
                if count.startswith('0'):
                    return False
                count = 0 if count == "" else int(count)
                index = index + count + 1
                if index >= len(word):
                    return False
                count = ""
                if abbr[i] == word[index]:
                    continue
                else:
                    return False
            else:
                count += abbr[i]
        if count != "":
            if count.startswith('0'):
                return False
            if index + int(count) + 1 == len(word):
                return True
            else:
                return False
        return True
```
