
1. 时间复杂度o(nlgn)
2. 每次调用函数helper(nums,l,r),将nums[l:r+1]分成两部分
3. 每个部分分别调用helper计算自身的重要翻转对数，两部分在调用函数的时候排序了两部分的数组
4. 分治归并的时候要做两件事情：计算跨两部分的重要翻转对数；对两部分进行归并排序。
```
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def helper(nums,l,r):
            if r == l:
                return 0
            m = l + 1 + (r-l)//2
            L = helper(nums,l,m-1) #此时nums[l:m]已排序
            R = helper(nums,m,r) #此时nums[m:r+1]已排序
            #计算i~[l,m-1]和j~[m,r]的重要翻转对，来进行归并
            i = l
            j = m
            ans = L + R
            while i < m and j <= r:
                if nums[i] > 2*nums[j]:  
                    ans += m - i
                    j += 1
                else:
                    i += 1
            #通过两路归并排序nums[l:r+1]
            temp = []
            i = l
            j = m
            while i < m and j <= r:
                if nums[i] < nums[j]:
                    temp.append(nums[i])
                    i += 1
                else:
                    temp.append(nums[j])
                    j += 1
            if i == m:
                while j <= r:
                    temp.append(nums[j])
                    j += 1
            else:
                while i < m:
                    temp.append(nums[i])
                    i += 1
            nums[l:r+1] = temp
            return ans
        if not nums:
            return 0
        else:
            return helper(nums,0,len(nums)-1)
```
超时原因是每次归并排序要开新数组空间，而且append用了太多，用原生sorted反而有时候可以通过。有时候的意思是提交了四次通过了两次。。。
```
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def helper(nums,l,r):
            if r == l:
                return 0
            m = l + 1 + (r-l)//2
            L = helper(nums,l,m-1) #此时nums[l,m-1]已排序
            R = helper(nums,m,r) #此时nums[m,r]已排序
            #计算i~[l,m-1]和j~[m,r]的重要翻转对，来进行归并
            i = l
            j = m
            ans = L + R
            nums[l:m] = sorted(nums[l:m])
            nums[m:r+1] = sorted(nums[m:r+1])
            while i < m and j <= r:
                if nums[i] > 2*nums[j]:  
                    ans += m - i
                    j += 1
                else:
                    i += 1
            return ans
        if not nums:
            return 0
        else:
            return helper(nums,0,len(nums)-1)
```
