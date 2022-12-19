![image.png](https://pic.leetcode-cn.com/2e0d66c1450c14c93a75a58bb35e3fdb074dbe03b67f732a5d8e99bbe0716c41-image.png)


```
'''
hash 表保存后缀，枚举每个字符串进行拼接即可
'''


from typing import List
class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        m = {}
        for i, s in enumerate(phrases):
            idx = s.find(' ')
            if idx != -1:
                if s[:idx] not in m:
                    m[s[:idx]] = []

                m[s[:idx]].append((i, s[idx+1:]))
            else:
                if s not in m:
                    m[s] = []
                m[s].append((i, ''))

        ans = set()
        for i, s in enumerate(phrases):
            idx = s.rfind(' ')
            key = s[idx+1:]

            if key in m:
                for idx, suffix in m[key]:
                    if idx == i:
                        continue

                    if suffix == '':
                        ans.add(s)
                    else:
                        ans.add(f'{s} {suffix}')

        return sorted(list(ans))
```
