#### 解题思路:

与力扣第「33.搜索旋转排序数组题」相似，但 `nums` 可能包含重复元素，关于这道题还是一样。

思路一: 库函数

思路二: 二分法，判断二分点，几种可能性

1. 直接 `nums[mid] == target`

2. 当数组为 `[1,2,1,1,1]`,`nums[mid] == nums[left] == nums[right]`，需要 `left++, right --`;

3. 当 `nums[left]<= nums[mid]`，说明是在左半边的递增区域

   ​	a. `nums[left] <=target < nums[mid]`，说明 `target` 在 `left` 和 `mid` 之间。我们令 `right = mid - 1`;

   ​	b. 不在之间，我们令 `left = mid + 1`;

4. 当 `nums[mid] < nums[right]`，说明是在右半边的递增区域

   ​	a. `nums[mid] < target <= nums[right]`，说明 `target` 在 `mid` 和 `right` 之间，我们令 `left = mid + 1`

   ​	b. 不在之间，我们令 `right = mid - 1`;

   时间复杂度：$O(logn)$。

#### 代码:

思路二: 

```python [1]
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        
        left = 0
        right = len(nums) - 1
        while left <= right:
            #print(left, right)
            mid = left + (right - left) // 2
            # 等于目标值
            if nums[mid] == target:return True
            
            if nums[mid] == nums[left] == nums[right]:
                left += 1
                right -= 1
            # 在前部分
            elif nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return False
```



```java [1]
class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;  
    }
}
```

