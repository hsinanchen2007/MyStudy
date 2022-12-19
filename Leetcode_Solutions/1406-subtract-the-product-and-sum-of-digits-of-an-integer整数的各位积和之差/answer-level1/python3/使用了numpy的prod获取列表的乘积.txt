class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        # 使用了numpy的prod获取列表的乘积
        import numpy 
        item_list = [int(item) for item in list(str(n))]
        multiply_res = numpy.prod(item_list)
        sum_res = sum(item_list)
        return multiply_res - sum_res