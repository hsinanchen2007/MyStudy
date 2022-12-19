![image.png](https://pic.leetcode-cn.com/35e3706be7b16d4f5066c270a7a49ba4003ff6ebfb97180d9f7ccd42c31f1ac1-image.png)


```
'''
同名交易放在一个列表中，然后按照时间戳进行排序，在排序列表中
查找矛盾
'''

from typing import List
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        m = {}
        for rec in transactions:
            name, time, value, city = rec.split(',')
            time = int(time)
            value = int(value)
            if name not in m:
                m[name] = []
            m[name].append((time, value, city))

        ans = []
        for name, l in m.items():
            l.sort(key = lambda x : x[0])
            n = len(l)

            flag = True
            for i in range(n):
                flag = True

                if l[i][1] > 1000:
                    ans.append(f'{name},{l[i][0]},{l[i][1]},{l[i][2]}')
                    continue

                j = i-1
                while j >= 0:
                    if l[i][0] - l[j][0] > 60:
                        break

                    if l[i][2] != l[j][2] and l[i][0] - l[j][0] <= 60:
                        flag = False
                    j -= 1

                if not flag:
                    ans.append(f'{name},{l[i][0]},{l[i][1]},{l[i][2]}')
                    continue

                j = i+1
                while j < n:
                    if l[j][0] - l[i][0] > 60:
                        break

                    if l[i][2] != l[j][2] and l[j][0] - l[i][0] <= 60:
                        flag = False
                    j += 1

                if not flag:
                    ans.append(f'{name},{l[i][0]},{l[i][1]},{l[i][2]}')

        return ans
```
