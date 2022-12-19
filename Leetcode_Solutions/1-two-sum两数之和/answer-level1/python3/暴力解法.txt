#暴力解法
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result=[]
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target  : 
                    result.append(i) 
                    result.append(j)
                    return result

if __name__ == "__main__":
    A=[2, 7, 11, 15]
    target=9
    sum=[]
    a=Solution()
    sum=a.twoSum(nums=A,target=target)
    print(sum)