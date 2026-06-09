1、数组nums,if max(nums)<=0,maxsumarr=max(nums)
2、将数组依次相加，sumarr+=nums[i],每加一次，判断sumarr是否小于0，如果小于0，则将sumarr赋值为0,相当于抛弃前面的负值贡献，每加一次，都和前面一次sumarr比较，取最大的sumarr保留，最后取最大值
class Solution:
    def maxSubArray(self, nums: 'List[int]') -> 'int':
        maxsumarr=0
        sumarr=0
        n=len(nums)
        for i in range(n):
            sumarr=sumarr+nums[i]
            maxsumarr=max(maxsumarr,sumarr)
            if sumarr<0:
                sumarr=0
        if maxsumarr==0:
            maxsumarr=max(nums)
        return maxsumarr