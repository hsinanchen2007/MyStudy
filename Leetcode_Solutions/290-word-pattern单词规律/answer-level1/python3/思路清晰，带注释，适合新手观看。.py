```
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        words = str.split(" ")
        if len(words) != len(pattern):
            return False
        hashMap = {}
        mapVal = {}
        for i in range(len(pattern)):
            if pattern[i] in hashMap:
                # 如果pattern[i]存在于hashMap中了，判断pattern[i] 和 word[i]是否存在对应关系
                if hashMap[pattern[i]] != words[i]:
                    return False
            else:
                # 如果pattern[i]没有在hashMap中，但word[i]之前已经出现过了，则直接返回False
                if words[i] in mapVal:
                    return False
                # 建立对应关系，同时将word[i]添加到mapVal中
                hashMap[pattern[i]] = words[i]
                mapVal[words[i]] = True
        return True
        
```
