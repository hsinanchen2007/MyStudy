分析: 若元全非0, 则只需全部乘起来, 再遍历n个元, 除以每轮的元. 
  若有且只有1个0, 则除此之外, 其他都是0.
  若多于1个0, 则全为0.
时间复杂度: 只有1层遍历, O(n)
空间复杂度: 存n维列表解及几个1维变量, O(n)
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        count=nums.count(0)
        n=len(nums)
        if count>1:
            return [0]*n
        elif count==1:
            product=1
            for i in range(n):
                if nums[i]!=0:
                    product*=nums[i]
                else:
                    j=i
            arrayProductExceptSelf=[0]*(n-1)
            arrayProductExceptSelf.insert(j,product)
            return arrayProductExceptSelf
        else:
            product=1
            arrayProductExceptSelf=[0]*n
            for i in range(n):
                product*=nums[i]
            for i in range(n):
                arrayProductExceptSelf[i]=product/nums[i]
            return arrayProductExceptSelf