```
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        res = []
        dict1 = {}
        for transaction in transactions:
            tmp = transaction.split(',')
            flag = False
            if tmp[0] not in dict1:
                dict1[tmp[0]] = [[tmp[1], tmp[2], tmp[3], False]]
            else:
                tmp_list = dict1[tmp[0]]
                for l in tmp_list:
                    if abs(int(l[0]) - int(tmp[1])) <= 60 and l[2] != tmp[-1]:
                        if not l[3]:
                            res.append(','.join([tmp[0], l[0], l[1], l[2]]))
                            l[3] = True
                        flag = True
                dict1[tmp[0]].append([tmp[1], tmp[2], tmp[3], flag])
            if int(tmp[2]) > 1000 or flag:
                dict1[tmp[0]][-1][3] = True
                res.append(transaction)
        return res
```
