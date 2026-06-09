小白一枚，找了一个方法给出结果：
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        uu=[]
        for i,num1 in enumerate(nums):
            for j ,num2 in enumerate(nums):
                try:
                    if i<j:
                        k=0-num1-num2 
                        res=nums.index(k)
                        if k in nums and res>j:
                            t=[num1,num2,k]
                            if t not in uu:
                                uu.append(t)
                except(ValueError):
                    continue
    
        return uu