算是暴力解了
空间O(1),时间O(n)
```
class Solution(object):
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if not A or len(A)==1:
            return 0
        l,r=0,0
        up,down=0,0
        maxl=0
        while r<len(A)-1:
            if A[r]<A[r+1]:
                if down and up:
                    maxl=max(maxl,r-l+1)
                    down=0
                    l=r
                elif down and not up:
                    down=0
                    up=1
                    l=r
                elif not down and not up:
                    up=1
                    l=r
            elif A[r]>A[r+1]:
                if not down:
                    down=1
            else:
                if down and up:
                    maxl=max(maxl,r-l+1)
                down,up=0,0
                l=r
            r+=1
        if up and down:
            maxl=max(maxl,r-l+1)
        return maxl
                
```
