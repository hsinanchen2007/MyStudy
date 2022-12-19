首先通过列表生成一个从0到n的列表
然后利用sum函数来获取列表值的和.
class Solution:
    def sumNums(self, n: int) -> int:
        list1=list(range(n+1))
        return sum(list1)
