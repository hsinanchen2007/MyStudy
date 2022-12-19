```
# -- coding: utf-8 --
import  collections
class Solution():
    def minIncrementForUnique(self, A):
        if len(A)==0:
            return 0
        min_dat = min(A)

        d = dict(collections.Counter(A))
        index = min_dat
        move_count = 0
        n = len(A)
        count = 0

        while count<n:
            if  index in d and d[index] > 1:
                if index+1 not in d:
                    d[index+1] = 0
                d[index + 1] += (d[index] - 1)
                move_count += d[index] - 1
                d[index] = 1
                count += 1

            elif index in d and d[index]==1:
                count += 1
            index += 1

        return move_count
```
