## 思路：

**思路 1：** 手动二分法!

这里提供两种方法，一种容易理解，一种万能公式！

版本1：是指在二分法进行时，就判读是否有等于 `target` 的，但是找到的 `target` 不知道是最左边的数还是最右边的数。所以，通过找到这个数再找出相应的边界值。(最差情况复杂度为 $O(n)$)

版本2：是指二分法执行完毕，返回 `target` 在最左边的位置，再用二分法求另一个边界！时间复杂度为：$O(logn)$

小技巧：

`left < right`, 执行完毕输出

`left <= right`, 执行中判断输出

**思路 2：** 库函数

Python 的 [bisect 库](https://docs.python.org/3/library/bisect.html) 

简要介绍一下，`bisect.bisect_left(a,x,lo=0,hi=len(a))` 在 `a` 中找 `x` 最左边数的索引，如果找不到就返回插入的索引。

`bisect.bisect(a, x, lo=0, hi=len(a))` 找最右边的！

**思路 3：** 分而治之

当然上面的时间复杂度都是：$O(logn)$

## 代码：

### 思路 1：

版本 1

```Python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        res = [-1, -1]
        left = 0
        n = len(nums)
        right = n - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                left = mid
                right = mid
                while left > 0 and nums[left-1] == nums[left]:
                    left -= 1
                while right < n - 1 and nums[right] == nums[right+1]:
                    right += 1
                res[0] = left
                res[1] = right
                break
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return res
```
```Java []
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1, -1};
        int n = nums.length;
        if (n == 0) return res;
        int left = 0;
        int right = n-1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid;
                right = mid;
                while (left > 0 && nums[left] == nums[left-1]) left--;
                while (right < n - 1 && nums[right] == nums[right+1]) right++;
                res[0] = left;
                res[1] = right;
                return res;
            }
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return res;
        
    }
}
```

### 思路 1：

版本 2

```Python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        res = [-1, -1]
        left = 0
        n = len(nums)
        right = n
        # 求上界
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        res[0] = left if left < n and nums[left] == target else -1
        if res[0] == -1:
            return res
        left = 0
        right = n
        # 求下界
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid 
        res[1] = left - 1
        return res
```

对库函数使用，大家自行操作的！很简单。