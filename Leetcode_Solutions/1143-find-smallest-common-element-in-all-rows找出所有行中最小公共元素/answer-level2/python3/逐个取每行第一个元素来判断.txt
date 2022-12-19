```
class Solution(object):
    def smallestCommonElement(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
                            
        rows = len(mat)
        cols = len(mat[0])
        hd = [mat[i][0] for i in range(rows)]
        hdidx = [0 for i in range(rows)]

        while True:
            mi = min(hd)
            mx = max(hd)
            if mi == mx:
                return mi
            idx = hd.index(mi)
            if hdidx[idx] >= cols-1:
                return -1
            hdidx[idx] += 1
            hd[idx] = mat[idx][hdidx[idx]]

```
