思路：

暴力解法，两层循环依次比较，对每一组进行判定是否满足题意的要求，最终返回符合要求的结果集即可

代码实现：

```
class Solution(object):
    def invalidTransactions(self, transactions):
        """
        :type transactions: List[str]
        :rtype: List[str]
        """
        ret = []
        t = [x.split(',') for x in transactions]
        for idx1, tran1 in enumerate(transactions):
            for idx2, tran2 in enumerate(transactions):
                if idx1 == idx2:
                    continue
                if int(t[idx1][2]) > 1000:
                    ret.append(tran1)
                    break
                if t[idx1][0] == t[idx2][0] and t[idx1][3] != t[idx2][3] and \
                        abs(int(t[idx1][1]) - int(t[idx2][1])) <= 60:
                    ret.append(tran1)
                    break
        return ret
```

更多题解欢迎关注 [Do Leetcode For Fun](https://zhuanlan.zhihu.com/c_1145647496591298560) 专栏~
