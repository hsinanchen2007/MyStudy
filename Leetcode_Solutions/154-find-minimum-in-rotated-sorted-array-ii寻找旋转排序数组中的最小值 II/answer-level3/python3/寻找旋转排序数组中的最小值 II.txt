### 方法一

* 在[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)基础上进行改进，我们依旧使用二分搜索，比较`left right`和`mid`处值的大小。情况见下，前两种情况都不变，第三种情况我们需要拆成两种。
    * 1. `mid值`最小。当`left值>mid值`时，`right值一定>mid值`，此时`res`在`[left, mid]`中
    * 2. `mid值`最大。当`mid值>right值`时，`mid值一定>right值`，此时`res`在`(mid,right]`中
    * 3. `left值<=mid值<=right值`
        * 3.1. `left值<right值`时，最小的一定是`left值`
        * 3.2 `left值=mid值=right值`时，这时候二分解决不了问题了，使用线性搜索。e.g.旋转数组`[2,1,2,2,2]`，再转一转成为`[2,2,2,1,2]`，这两个数组都满足`left值=mid值=right值`，但`1`分别在左半边和右半边。
* 时间复杂度: hopefully是O(logN)，最差为O(N); 空间复杂度: O(1)

```python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums)-1
        while(left <= right):
            mid = left + (right - left)//2
            if nums[left] > nums[mid]: # mid最大
                right = mid
            elif nums[mid] > nums[right]: # mid最小
                left = mid + 1
            else: # nums[left] <= nums[mid] <= nums[right]
                if nums[left] < nums[right]:
                    return nums[left]
                else: # nums[left] = nums[mid] = nums[right]
                    res = nums[left]
                    for i in range(left, right+1):
                        res = nums[i] if nums[i]<res else res
                    return res

```

### 方法二

* 方法一的判断条件太复杂了。方法二只需要拿`mid`和`right`进行比较。
    * 如果`mid值>right值`，此时`res`在`(mid,right]`中
    * 如果`mid值<right值`，此时`res`在`[left, mid]`中
    * 如果`mid值==right值`，`right`左移一下
    * 返回`left值` 
* 时间复杂度: hopefully是O(logN)，最差为O(N); 空间复杂度: O(1)

```python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums)-1
        while(left <= right):
            mid = left + (right - left)//2
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]: 
                right = mid
            else: # nums[mid] == nums[right]
                right -= 1
        return nums[left]
```