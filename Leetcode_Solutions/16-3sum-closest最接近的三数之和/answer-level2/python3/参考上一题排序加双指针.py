三个数的和小于target，往大的方向才有可能找到更接近的值。L+=1
否则R+=1

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        best=100000000
        ans=0
        nums.sort()
        for i in range(len(nums)):
            if nums[i]-target>best:
                break
            if i>0 and nums[i]==nums[i-1]:
                continue
            L=i+1
            R=len(nums)-1
            while L<R:
                sum3=nums[i]+nums[L]+nums[R]
                if sum3==target:
                    return sum3
                if sum3<target:
                    if 0-best<sum3-target:
                        best=target-sum3
                        ans=sum3
                    L+=1
                else:
                    if sum3-target<best:
                        best=sum3-target
                        ans=sum3
                       
                    R-=1

        return ans