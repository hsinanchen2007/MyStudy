from functools import reduce
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        strn = str(n)
        listn = list(strn)
        #使用map函数将字符串列表转换成整形列表
        b = map(eval, listn)
        c = list(b)
        #使用sum函数求列表中所有数字之和
        sumn = sum(c)
        #使用高级函数求列表中所有数字之积
        multi = reduce(lambda x,y:x*y,c)
        return multi - sumn

![捕获.PNG](https://pic.leetcode-cn.com/722146dee7f8c08a6da221010c510f8eacd530e9be16718acd5ab989454385c6-%E6%8D%95%E8%8E%B7.PNG)

