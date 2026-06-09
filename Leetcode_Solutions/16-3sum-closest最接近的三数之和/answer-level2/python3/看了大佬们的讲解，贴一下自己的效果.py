**就是化用了三数求和的思想**
    在遍历过程中，固定最左侧一个元素，然后使用两个指针在右侧依次调整，根据三数求和与target目标值的大小关系（target>sum,target<sum,target=sum）决定调整哪个指针，同时将差值最小的求和值与差值
保留，

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums)<3 or nums ==None:
            return(0)
        nums.sort()
        size = len(nums)
        diff = float('inf')
        best_sum = 0                     #最终需要返回的结果
        for i in range(0,size-1):     
            j = i + 1
            k = size - 1
            while j<k and i<j:
                three_sum = nums[i] + nums[j] + nums[k]
                if three_sum<target:
                    t1 = target - three_sum
                    if t1<diff:
                        diff = t1
                        best_sum = three_sum
                    j += 1
                    while j<k and nums[j]==nums[j-1]:
                        j += 1
                if three_sum>target:
                    t2 = three_sum - target
                    if t2<diff:
                        diff = t2
                        best_sum = three_sum
                    k -= 1         
                    while j<k and nums[k]==nums[k+1]:
                        k -= 1
                if three_sum==target:
                    return(three_sum)
        return(best_sum)
        