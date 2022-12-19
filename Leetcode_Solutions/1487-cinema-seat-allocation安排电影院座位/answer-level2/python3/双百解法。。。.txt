
注意这两条提示：

提示：

1 <= n <= 10^9
1 <= reservedSeats.length <= min(10*n, 10^4)


所以有人站住的位子远小于n。这样的话，只要只loop有人站住的行，没人站住的行*2 在求和就行了。。。


```
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        reservedSet = set((i[0],i[1]) for i in reservedSeats if i[1] not in {1,10})
        reserveddict = {}
        for i in reservedSeats:
            if i[0] not in reserveddict:
                reserveddict[i[0]] = {i[1]}
            else:
                reserveddict[i[0]].add(i[1])
        re = 0
        for i in reserveddict.keys():                
            count1 =1
            count2 =1
            count3 =1
            for j in range(2,6):
                if j in  reserveddict[i]:
                    count1 = 0
            for j in range(6,10):
                if j in reserveddict[i]:
                    count2 = 0
            for j in range(4,8):
                if j in reserveddict[i]:
                    count3 = 0
            add = count1+count2
            re+= add if add>=1 else count3

        re += (n - len(reserveddict.keys()))*2
        return re
```
