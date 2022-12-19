```
class Solution:

    def numSmallerByFrequency(self, queries, words):
        from collections import Counter
        res = []
        all_count = []
        for j in words:
            min_alpha1 = sorted(list(j))[0]
            d1 = dict(Counter(j))
            t1 = d1[min_alpha1]
            all_count.append(t1)
        for i in queries:
            min_alpha = sorted(list(i))[0]
            count = 0
            d = dict(Counter(i))
            t = d[min_alpha]
            for j in range(len(words)):
                t1 = all_count[j]
                if t < t1:
                    count += 1
            res.append(count)
        return res

```
