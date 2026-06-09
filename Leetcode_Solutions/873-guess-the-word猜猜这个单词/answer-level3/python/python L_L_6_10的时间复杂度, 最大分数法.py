### 解题思路
假定wordlist长度位L， 我们猜测为i， sercret为j
那么这个猜测会有一个命中结果c，表示命中了多少位，
然后我们希望这个除了这个c以外其他的猜测被排除的越多越好(排除的越多，剩下的越少，通过的可能性越大)。

假定猜测i时，并且结果是c的情况下，j的取值一共有K个
分数我们可以约定是 K * (N - K)
然后假定j完全随机，那么每个猜测i所对应的排除期望就是 对于每个i求Sum, Sum(K * (N - K))
通过上面的方式我们计算出排除期望最大的i，然后进行猜测。


### 代码

```python
class Solution(object):
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        for times in range(10):
            L = len(wordlist)
            dic = {}
            # choose the highest point
            for i in range(L):
                dic[i] = [[] for tt in range(6 + 1)]
                for j in range(L):
                    if i == j:
                        dic[i][6].append(j)
                    else:
                        c = 0
                        for t in range(6):
                            if wordlist[i][t] == wordlist[j][t]:
                                c += 1
                        dic[i][c].append(j)

            max_point = -100
            max_i = -1000
            for i in range(L):
                point = 0
                for values in dic[i]:
                    l2 = len(values)
                    point += l2 * (L - l2)
                if point > max_point:
                    max_point = point
                    max_i = i
            res = master.guess(wordlist[max_i])
            if res < 6:
                wordlist = [wordlist[j] for j in dic[max_i][res]]
            else:
                break
```