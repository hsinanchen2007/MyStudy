from functools import reduce
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        strn = str(n)
        listn = list(strn)
        b = map(eval, listn)
        c = list(b)
        sumn = sum(c)
        multi = reduce(lambda x,y:x*y,c)
        return multi - sumn