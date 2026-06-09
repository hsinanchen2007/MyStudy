```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Solution 1: 
        # 执行用时: 92 ms, 在所有 Python3 提交中击败了80.25%的用户
        # 内存消耗: 14.7 MB, 在所有 Python3 提交中击败了19.21%的用户
        #return heapq.nlargest(k, nums)[-1]
        
        # Solution 2:
        # 和1没什么区别
        #return sorted(nums)[-k]
        
        # Solution 3: 快速选择
        # 执行用时: 108 ms, 在所有 Python3 提交中击败了55.53%的用户
        # 内存消耗: 14.8 MB, 在所有 Python3 提交中击败了19.21%的用户

        # 分割:
        # pivot > k-1: 分割左边
        # pivot > k-1: 分割右边
        # pivot = k-1: 返回nums[k-1]
        lo, hi = 0, len(nums)
        k -= 1
        while True:
            pivot = partition(nums, lo, hi)
            if pivot > k:
                hi = pivot
            elif pivot < k:
                lo = pivot+1
            else:
                return nums[k]
            
def partition(nums: List[int], lo: int, hi: int) -> int:
    # Partition:
    # 随机抽取一个放在第一位: 性能优化
    # top = lo, pivot = nums[lo]
    # 对每个元素：
    #   若比pivot大, 交换它与nums[top+1], top++
    # 交换pivot与top的值  
    # 返回top    
    
    rand_index = random.randint(lo, hi-1)
    nums[lo], nums[rand_index] = nums[rand_index], nums[lo]
    top, pivot = lo, nums[lo]
    for i in range(lo, hi):
        if nums[i] > pivot:
            top += 1
            nums[i], nums[top] = nums[top], nums[i]
            
    nums[lo], nums[top] = nums[top], nums[lo]
    return top
```
