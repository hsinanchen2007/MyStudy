### 解题思路
1. 首先找到任意一个target所在索引（helper函数部分）
2. 然后通过该索引可以将数组nums分为两部分
3. 依次重复步骤2，分别向左右收敛，直到找不到target为止（find_side的递归）

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def helper(left, right):
            if left > right:
                return -1
            
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                return helper(mid + 1, right)
            else:
                return helper(left, mid - 1)

        def find_side(left, right, is_left, last_idx):
            # print(left, right, is_left, last_idx)
            if left > right:
                return last_idx

            mid = left + (right - left) // 2
            if nums[mid] == target:
                if is_left:
                    return find_side(left, mid - 1, is_left, mid)
                else:
                    return find_side(mid + 1, right, is_left, mid)

            elif nums[mid] < target:
                return find_side(mid + 1, right, is_left, last_idx)
            else:
                return find_side(left, mid - 1, is_left, last_idx)
            

        loc = helper(0, len(nums) - 1)
        if loc == -1:
            return [-1, -1]
        
        l = find_side(0, loc, True, loc)
        r = find_side(loc, len(nums) - 1, False, loc)
        return [l, r]
```