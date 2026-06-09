广度优先遍历，遍历每一个字符，如果是数字就往里放，如果是字母，就把结果集里的每一个中间结果加上当前字母和当前字母的大写字母
```
class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        length = len(S)
        if length == 0:
            return ['']
        res = []
        for i in range(0, length):
            if S[i].isdigit():
                if res:
                    for j in range(0, len(res)):
                        res[j] = res[j] + S[i]
                else:
                    res.append(S[i])
            if S[i].isupper():
                if res:
                    for j in range(0, len(res)):
                        cur = res[j]
                        res[j] = cur + S[i]
                        res.append(cur + S[i].lower())
                else:
                    res.append(S[i])
                    res.append(S[i].lower())
            if S[i].islower():
                if res:
                    for j in range(0, len(res)):
                        cur = res[j]
                        res[j] = cur + S[i]
                        res.append(cur + S[i].upper())
                else:
                    res.append(S[i])
                    res.append(S[i].upper())
        return res
```

