主要通过使用python中set的与操作
class Solution:
    def twoSum(self, lst, target):
        tempSet = set() ##用集合存储list中每一个元素与target的差
        for item in lst:
            temp = target - item
            tempSet.add(temp)
        rslt = set(lst) & tempSet  ##通过与运算，将目标集合与差集合做与运算得到target的两个元素
        r = [i for i in range(len(lst)) if lst[i] in rslt]
        if len(r) == 2:
            return r
        else: ##排除list中存在目标target整除2后的元素
            i = lst.index(target//2)
            r.remove(i)
            return r
