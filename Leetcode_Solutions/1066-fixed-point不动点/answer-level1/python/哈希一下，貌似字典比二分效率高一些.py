class Solution(object):
    def fixedPoint(self, A):
        d= {}
        for k,v in enumerate(A):
            d[k] = v
            if v == k:
                return k
                break
        return -1