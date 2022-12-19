class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        from functools import reduce
        def num_add(x,y):
            return x*10 + y
        a = reduce(num_add, digits)
        a += 1
        a = str(a)
        b = []
        for i in a:
            b.append(i)
        return b

把list通过reduce组合为int，然后加一，再变成list就OK