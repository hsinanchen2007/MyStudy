```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        def less_search(arr, low, high, key): #查找第一个小于key的位置
            while low <= high:
                mid = (low + high) // 2
                if arr[mid] < key:
                    low = mid + 1
                else:  
                    high = mid - 1
            return high
        def biger_search(arr, low, high, key): #查找第一个大于key的位置
            while low <= high:
                mid = (low + high) // 2
                if arr[mid] <= key:
                    low = mid + 1
                else:  
                    high = mid - 1
            return low 
        
        n = len(nums)
        if nums is None or n < 3:
            return []
        nums.sort()
        i = 0
        ans = []
        while i < n and nums[i] <= 0:
            L, R, t = i + 1, n - 1, -nums[i]
            while L < R:
                if nums[L] + nums[R] < t: #和太小,将左边界移动到第一个大于t-nums[R]的位置
                    L = biger_search(nums, L+1, R-1, t-nums[R])
                    if nums[L-1] + nums[R] == t: #若有解则存储解
                        ans.append([nums[i], nums[L-1], nums[R]])
                    R -= 1 
                elif nums[L] + nums[R] > t:#和太大,将右边界移动到第一个小于t-nums[L]的位置
                    R = less_search(nums, L+1, R-1, t-nums[L])
                    if nums[L] + nums[R+1] == t: #若有解则存储解
                        ans.append([nums[i], nums[L], nums[R+1]])
                    L += 1 
                else: 
                    ans.append([nums[i], nums[L], nums[R]])
                    while L < R and nums[L] == nums[L+1]:#跳过左侧相同元素
                        L += 1
                    while L < R and nums[R] == nums[R-1]:#跳过右侧相同元素
                        R -= 1
                    L, R = L + 1, R - 1 #更新左右边界
            i += 1
            while i < n and nums[i] == nums[i-1]:#跳过相同的nums[i]
                i += 1
        return ans
```
