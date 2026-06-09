先用普通的O(n)时间以及O(n)空间的算法，然后想减少空间，就想到了快排每一次的比较过程，于是又用双指针尝试了一次，在原地操作
```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        # opp = []
        # even = []
        # for num in nums:
        #     if num%2==1:
        #         opp.append(num)
        #     else:
        #         even.append(num)
        # return opp+even
        
        #结合快排算法的双指针方法解决
        i,j=0,len(nums)-1
        while i<j:
            if nums[i]%2==0: #左边指向了偶数
                if nums[j]%2==0: #右边指向了偶数
                    j-=1 #右移
                else: #右边指向了奇数
                    nums[i],nums[j] = nums[j],nums[i]
                    i+=1
                    j-=1
            else: #左边指向了奇数
                if nums[j]%2==0: #右边指向了偶数
                    i+=1
                    j-=1
                else: #右边指向了奇数
                    i+=1 #左移
        return nums
```