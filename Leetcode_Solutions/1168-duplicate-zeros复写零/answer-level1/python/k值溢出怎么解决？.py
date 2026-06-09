
```
class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        try:
            t = len(arr)
            k = 0
            for i in xrange(t-2):
                if arr[k] == 0:
                    arr.insert(k+1,0)
                    del arr[t]
                    k=k+1
                k=k+1
        except Exception,e:
            pass
```