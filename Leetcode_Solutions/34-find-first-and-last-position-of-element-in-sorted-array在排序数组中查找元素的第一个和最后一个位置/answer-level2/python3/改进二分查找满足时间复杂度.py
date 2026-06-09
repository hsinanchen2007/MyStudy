### 解题思路
改进的二分查找思路：
    第一次找到左边界
    第二次找到右边界
见如下代码：注意左右边界的结束条件（难点）ps:我是根据测试样例慢慢完善结束条件的，智商不足
整体时间复杂度为O(logn)

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # 改进的二分查找（O(logn)）
        # 查找边界
        def find(l, r, flag):
            if l > r:
                return -1
            mid = (l + r) // 2
            if nums[mid] < target:   # 常规的二分查找条件
                return find(mid+1, r, flag)
            elif nums[mid] > target:
                return find(l, mid-1, flag)
            else:  # 当二分查找中间那个数正好等于查找的数时，分情况讨论
                if flag == 0:
                    if mid == l:  # 左边界结束条件
                        return mid
                    else:
                        return find(l, mid, flag)
                else:
                    if r - mid <= 1:  # 右边界结束条件
	                    return r  if nums[r] == target else mid
                    else:
                        return find(mid, r, flag)
        
        left = find(0, len(nums)-1, 0)  # 找到左边界
        if left == -1:  # 给定数组根本不存在这个目标数
            return [-1, -1]
        right = find(left, len(nums)-1, 1)  # 找到右边界
        return [left, right]
```