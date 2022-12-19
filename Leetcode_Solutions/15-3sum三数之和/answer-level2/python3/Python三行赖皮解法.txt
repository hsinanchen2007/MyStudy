Python 三行 嗯我就发出来搞个笑~~（用了内置的排列组合生成库）

先生成三个元素的全组合，再遍历筛选去重~~

~~~ Python
class Solution:
    def threeSum(self,nums):
        ts, bs = [i for i in set(list(itertools.combinations(nums, 3))) if sum(i) == 0], {}
        for i in ts: bs.update({frozenset(i): i}) if frozenset(i) not in list(bs.keys()) else 0         
        return list(bs.values())