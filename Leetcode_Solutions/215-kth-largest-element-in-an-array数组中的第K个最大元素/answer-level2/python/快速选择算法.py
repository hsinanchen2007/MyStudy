### 解题思路
快速选择算法，一般分为select函数，和一个内部的partition函数
partition是一个用于找主元位置的函数
select用二分的思想并进行剪枝，只需要一半的计算量
在主元的选择上多了一步随机选择
下标的转换会比较绕

### 代码

```python3
class Solution:
    def findKthLargest(self, nums, k):
        def partition(left, right, pivot_index):
            pivot = nums[pivot_index]
            # 1. 移动到最右边
            nums[pivot_index], nums[right] = nums[right], nums[pivot_index]  
            # 2. move all smaller elements to the left
            # 跟踪pivot的位置
            # 类似于快排，但是它不需要排序
            store_index = left
        
            for i in range(left, right):
                if nums[i] < pivot:
                    nums[store_index], nums[i] = nums[i], nums[store_index]
                    store_index += 1
            # 3. move pivot to its final place
            nums[right], nums[store_index] = nums[store_index], nums[right]  
            
            return store_index
        
        def select(left, right, k_smallest):
            """
            返回第k小的数
            """
            if left == right:      
                return nums[left]   
            
            # 随机选一个主元
            pivot_index = random.randint(left, right)     
                            
            # 划分  
            pivot_index = partition(left, right, pivot_index)
            
            # the pivot is in its final sorted position
            if k_smallest == pivot_index:
                 return nums[k_smallest]
            # go left
            elif k_smallest < pivot_index:
                return select(left, pivot_index - 1, k_smallest)
            # go right
            else:
                return select(pivot_index + 1, right, k_smallest)

        
        # 这里比较绕
        # 这里函数的区间是双头闭的，第k个最大，在从小到大排列的数组中的就是第len(num)+1-k小
        # index从0开始，所以实际的k_smallest还要减去1
        return select(0, len(nums) - 1, len(nums)- k)
```