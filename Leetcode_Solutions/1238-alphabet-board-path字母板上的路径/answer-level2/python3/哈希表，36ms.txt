将每个字母坐标记录在字典，然后模拟路径，顺序是上，左，右下随意。

```
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        alphabet = 'abcdefghijklmnopqrstuvwxyz'
        hashMap = {}
        i, j = 0, 0
        for a in alphabet:
            hashMap[a] = [i, j]
            j += 1
            if j == 5:
                i += 1
                j = 0
        tmp = 'a'
        ans = ''
        for i in target:
            while hashMap[i][0] < hashMap[tmp][0]:
                tmp = chr(ord(tmp) - 5)
                ans += 'U'
            while hashMap[i][1] < hashMap[tmp][1]:
                tmp = chr(ord(tmp) - 1)
                ans += 'L'
            while hashMap[i][1] > hashMap[tmp][1]:
                tmp = chr(ord(tmp) + 1)
                ans += 'R'
            while hashMap[i][0] > hashMap[tmp][0]:
                tmp = chr(ord(tmp) + 5)
                ans += 'D'
            if hashMap[i] == hashMap[tmp]:
                ans += '!'
        return ans
```
