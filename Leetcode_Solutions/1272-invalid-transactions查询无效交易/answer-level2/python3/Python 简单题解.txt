```Python []
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        trans = [x.split(',') for x in transactions]
        res = []
        for i in range(len(trans)):
            name, time, money, city = trans[i]
            time = int(time)
            if int(money) > 1000:
                res.append(transactions[i])
                continue
            for j in range(len(trans)):
                if i == j:
                    continue;
                name1, time1, money1, city1 = trans[j]
                if name1 == name and city1 != city and abs(int(time1) - time) <= 60:
                    res.append(transactions[i])
                    break;
        return res
```

![image.png](https://pic.leetcode-cn.com/0ca7e2bab3e3ca16446616d66fa08af51ea98971b51995ed6d2e6e398553f2d6-image.png)
