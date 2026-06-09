![image.png](https://pic.leetcode-cn.com/bda93a0e879e09cc31b659a455ee55699deabfa7fd9091efd98c1f8147ba7f11-image.png)

主要方法是把同名交易放进字典，判断城市和时间差。

```python []
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        transactions = [x.split(',') for x in transactions]
        d = collections.defaultdict(list)
        for x in transactions:
            d[x[0]] += [x]
        ans = []
        for name in d:
            n = len(d[name])
            for i in range(n):
                flag = False
                for j in range(i + 1, n):
                    if abs(int(d[name][i][1]) - int(d[name][j][1])) <= 60 and d[name][i][3] != d[name][j][3]:
                        ans += [d[name][j]]
                        flag = True
                if flag or int(d[name][i][2]) > 1000:
                    ans += [d[name][i]]
        return [*{','.join(x) for x in ans}]
```
