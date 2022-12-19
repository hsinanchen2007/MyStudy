class Solution:
    def compressString(self, S: str) -> str:
        from itertools import groupby
        fun = lambda x: ord(x)
        list1 = []
        for k, g in groupby(list(S), fun):
            list1.append(list(g))
        result = ''.join([x[0]+str(len(x)) for x in list1])
        return  result if len(result)<len(S) else S