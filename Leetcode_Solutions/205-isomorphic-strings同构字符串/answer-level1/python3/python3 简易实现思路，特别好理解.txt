```
class Solutiona:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hashmaps = {}
        hashmapt = {}
        for i in range(len(s)):
            if s[i] not in hashmaps and t[i] not in hashmapt:
                hashmaps[s[i]] = i
                hashmapt[t[i]] = i
            else:
                if hashmaps.get(s[i]) == None or hashmapt.get(t[i]) == None:
                    return False
                else:
                    if (hashmaps.get(s[i]) != hashmapt.get(t[i])):
                        return False
        return True
```
解题思路使用2个哈希表，s与t同时推进记录，当其中一个字符出现回环 另外一个没有出现的时候比对，此时如果只有一个出现回环了返回false. 如果同时出现，但是对应的下标不一样也返回false.