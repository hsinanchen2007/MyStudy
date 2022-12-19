超时了~但是自己测代码应该是没问题的。发出来搞个笑~

~~~python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        return min([[abs(sum(i)-target),sum(i)] for i in set(itertools.combinations(nums, 3))])[1]