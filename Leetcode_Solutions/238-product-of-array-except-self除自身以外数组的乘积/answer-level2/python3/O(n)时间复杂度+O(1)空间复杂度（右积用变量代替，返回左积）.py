class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        #形成左积数组
        left_product = [nums[0]]
        for i in range(1,len(nums)):
            left_product.append(left_product[i-1] * nums[i])
        
        #用单个变量代替右积数组
        last_num = nums[-1]
        
        #向左积数组中反向添加结果
        left_product[-1] = left_product[-2]
        for j in range(len(nums)-2,0,-1):
            left_product[j] = left_product[j-1] * last_num
            last_num *= nums[j]
        left_product[0] = last_num
        
        return left_product