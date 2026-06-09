# **指定左(left)右(right)两个指针：**
    1. 起始左指针left为0，右指针right为len(nums)-1
    2. 如果满足 nums(right) - nums(left) == right - left, 即左右指针的差值等于左右指针对应在nums的值的差
    值，也就是说nums[left:right+1]为相邻值相差为1的整数数组--->[1,2,3,4]，有以下三种情况：
        1. left == right，即为数组中同一个数，[0, 2, 3]中的0，此时取值为0
        2. right != n - 1，即right不在数组末尾，此时取值为 nums[left:right+1],同时需要重置两指针为如下：
            left, right = right+1, n-1
        3. right == n - 1，即right在数组末尾，此时数组被完全循环，所有连续都被找到，直接返回res即可
    3. 如果nums[right] - nums[left] != right - left，即左右指针的差值不等于左右指针对应在nums的值的差值，这时将right
    左移一格重新判断 nums(right) - nums(left) == right - left 是否成立，不满足则循环操作本过程，直到left == right
    4. 在3.条件执行完毕后，将left加一后循环执行2.3.判断即可


```
    class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        # 排除数组为空或单元素数组
        if n == 0:
            return []
        elif n == 1:
            return ["%d" % nums[0]]
        left = 0
        right = n - 1
        res = []
        while left <= n - 2:
            while right >= left:
                # print('left:%d, right:%d.' % (left, right))
                if nums[right] - nums[left] == right - left:
                    if left == right:
                        res.append("%d" % nums[left])
                        left = copy.deepcopy(right) + 1
                        right = n - 1
                    elif right != n - 1:
                        res.append("%d->%d" % (nums[left], nums[right]))
                        left = copy.deepcopy(right) + 1
                        right = n - 1
                    else:
                        res.append("%d->%d" % (nums[left], nums[right]))
                        return res
                else:
                    right -= 1
            left += 1
        return res
```
