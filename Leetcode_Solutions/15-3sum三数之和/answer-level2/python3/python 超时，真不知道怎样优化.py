class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res_list = []
        len_nums = len(nums)
        #nums.sort()
        for i in range(len_nums):
            sess = []
            for j in range(i+1,len_nums):
                if -nums[i]-nums[j] in sess:
                    a = [nums[i],-nums[i]-nums[j],nums[j]]
                    a.sort()
                    #a = [nums[i],-nums[i]-nums[j],nums[j]].sort()
                    if a not in res_list:
                        res_list.append(a)
                else:
                    sess.append(nums[j])
        #res_list = list(set(res_list)).sort()
        res_list.sort()
        return res_list