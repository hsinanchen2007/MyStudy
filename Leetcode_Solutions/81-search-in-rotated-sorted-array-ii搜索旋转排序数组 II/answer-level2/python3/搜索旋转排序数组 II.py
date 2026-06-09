### 二分查找-题目汇总

索引 | 题目 | 有序 | 有重复元素| 旋转数组 | 目标任务 | 备注 
- | :-: | :-: | :-: | :-: | :-: |-:
0 |[704. 二分查找](https://leetcode-cn.com/problems/binary-search/) | √ | x | x | 查找 
1 | [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/) | √ | x | x | 查找和插入 | 0的进阶版
2 |[34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)| √ | √ | × | 查找区间 | 0的进阶版
3 |[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)|√ | × | √ | 找最小值
4 |[154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) | √ | √ | √ | 找最小值 | 3的进阶版
5 |[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) | √ | × | √ | 查找
6 |[81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)| √ | √ | √ | 查找 | 5的进阶版|
7 |[222. 完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/) | | | |节点个数
p.s. 若要加深对旋转数组的理解，请戳[189.旋转数组](https://leetcode-cn.com/problems/rotate-array/)。

### 解题思路
* 在`33. 搜索旋转排序数组`的[题解](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-coldme-2/)中，讲到我们使用的方法是两次二分：
    * step1. 第一次二分找`pivot`
    * step2. 将数组分成两段: `nums[:pivot-1]`和`nums[pivot:]`
    * step3. 在目标数组进行第二次二分来查找
* 这道题是在上题的基础上改变了数组的条件，变成有重复元素的数组。再来看我们的算法:
    * step2的分割肯定不用变，因为是否有重复元素不影响分割的条件，前提是确保`pivot`是正确的
    * step3也不用变，因为在有重复元素的数组里寻找`target`，相对于无重复元素的数组来说，相当于条件放松了，反而更容易找到。e.g.使用在`[1,2,3,4]`中寻找`3`的方法一定能在`[1,3,3,4]`中找到`3`
    * step1是唯一令人脑壳疼的。
        * `33. 搜索旋转排序数`找`pivot`的方法可以直接搬运`153. 寻找旋转排序数组中的最小值`，但是该题`81. 搜索旋转排序数组 II`却不能照搬`154. 寻找旋转排序数组中的最小值 II`了。因为该题的要求更严格，我们不仅要找最小值是谁，而且要找到中枢点（最小值的最开始的索引）。
        * `33. 搜索旋转排序数`step1的算法是将`nums[mid]`与`nums[right]`进行比较：
            * 如果`nums[mid]>nums[right]`，此时`pivot`在`(mid,right]`中
            * 如果`nums[mid]<nums[right]`，此时`pivot`在`[left, mid]`中
            * 如果`nums[mid]==nums[right]`，此时`pivot`在`[left, right-1)`中，`right`左移一下
            * `pivot = left`
        * 左移是一个很聪明的做法，可以解决重复元素的部分问题。以`[2,1,2,2]`为例，此时三个指针分别指向三个`2`，我们左移`right`，会使得区间向`1`靠拢。但是，左移不能解决所有的重复元素问题，以`[1,1,2,1]`为例，三个指针分别指向三个`1`，而`right`已经指向了中枢点，如果我们左移`right`，那么就把真正的中枢点（最后一个`1`）排除在外了，所以在`right`指向中枢点时，我们要慧眼识别出来，及时处理。
        * 因此，在这里我们只需对相等的情况做一个小小的改变。
            * 如果`nums[mid]==nums[right]`
                * 如果`right`前的元素比`right`大，那么`right`就是中枢点
                * 否则，`right`左移
* 至此我们解决了这道题。
* 时间复杂度: O(logN)，最差为O(N); 空间复杂度: O(1)

### 代码

```python []
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not len(nums):
            return False
        # step1: find pivot
        left, right = 0, len(nums)-1
        while(left <= right):
            mid = left + (right-left)//2
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                if (right>0 and nums[right-1]>nums[right]):
                    left = right
                    break
                else:
                    right -= 1
        pivot = left
        # step2: split
        if pivot == 0:
            left, right = 0, len(nums)-1
        elif target >= nums[0]:
            left, right = 0, pivot-1
        else:
            left, right = pivot, len(nums)-1
        # step3: find target
        while(left <= right):
            mid = left + (right-left)//2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid -1
            else:
                return True# mid
        return False
```