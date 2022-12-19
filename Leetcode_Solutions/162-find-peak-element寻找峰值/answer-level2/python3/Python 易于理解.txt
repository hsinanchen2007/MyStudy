### 解题思路
此处撰写解题思路
修改nums数组, 头尾插入float('-inf'), ['-inf', 1, 3, 2, '-inf']

1. 如果 nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1], mid为峰值
2. 如果nums[mid] < nums[mid+1], 那么此时处于递增阶段, 如果递增到有一个nums[mid+k] > nums[mid+k+1], 那么nums[mid+k]就是峰值。就算一直递增到结束, 而nums[n]为负无穷, 那么nums[n-1]就是峰值, 所以右侧一定会有峰值, left = mid+1
3. 同理, 如果nums[mid] < nums[mid-1], 那么mid-1到mid处于递减关系, 就算从0到mid一直都是递减, 而nums[-1]为负无穷, 那么nums[0]就是峰值。而如果0到mid当中有一个nums[k] > nums[k+1], 那么nums[k]就是峰值所以左侧一定会有峰值, right = mid-1

### 代码

```python3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        nums = [float('-inf')] + nums + [float('-inf')]
        # l, r指向原数组的第一个元素和最后一个元素
        l, r = 1, len(nums)-2
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]:
                # 返回在原nums数组中的索引 mid-1
                return mid - 1
            elif nums[mid] < nums[mid+1]:
                l = mid + 1
            elif nums[mid] < nums[mid-1]:
                r = mid - 1
```