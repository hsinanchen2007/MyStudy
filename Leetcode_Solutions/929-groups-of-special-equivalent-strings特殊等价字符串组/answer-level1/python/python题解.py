```
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        temp = set()
        for i in A:
            o = ''
            k = ''
            for j in range(len(i)):
                if j % 2 == 0:
                    o += i[j]
                else:
                    k += i[j]
            o = sorted(o)
            k = sorted(k)
            temp.add(''.join(o+k)) 
        return len(temp)
```
