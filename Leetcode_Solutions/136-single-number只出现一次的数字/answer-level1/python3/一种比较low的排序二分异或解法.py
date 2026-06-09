```
class Solution:
    def singleNumber(self, nums):
        # numa = 0
        # for i in nums:
        #     #if nums.count(i)<2:
        #     #    return i   #执行超时
        #     numa ^= i
        # return numa
        #集合求解法
        #return 2*sum(set(nums)) - sum(nums)
        len_num = len(nums)
        if not nums:
            return nums
        elif len_num == 1:
            return nums[0]
        else:
            nums.sort()
            left = 0
            right = len_num
            print(nums)
            while left < right:
                mid = (left + right) // 2
                if (nums[mid] ^ nums[mid+1])!=0:
                    if (nums[mid] ^ nums[mid-1])!=0:
                        return nums[mid]
                    else:
                        if mid%2 == 0:
                            right = mid
                        elif (right-mid)>3:
                            left = mid
                        else:
                            return nums[mid+1]
                elif mid%2 == 0:
                    left = mid
                elif mid%2 !=0:
                    right = mid

```
思路：先排序；排序后二分法开始异或运算，根据异或结果对应处理；