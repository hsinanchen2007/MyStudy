# 解题思路：
根据题意，数组是在已排序的情况下在某个点进行了旋转，因此被分为了两个已排序的部分，并且都是升序。
 要达到O(logn)的级别，我们首先考虑`二分搜索`。
## 二分搜索的核心如下：
1. 确定搜索范围
2. 判断相等条件
3. 下一步往哪搜索（左or右）

在这题中，难点在于，第3个核心要点。观察数组可以发现，左部分已排序的数均大于右部分已排序的数。
也就是说，左部分的第1个元素，即`nums[low]`是比右部分已排序的数大的。
我们用`nums[middle]`表示当前查找到的数，那么只需要判断`nums[middle]`是否大于`nums[low]`即可。
+ 如果`nums[middle] > nums[low]`，表示middle处于左部分，那么[0, middle]之间的数都是已排序的。
我们便可先判断target是否在这个区间里：
如果在，则对这个区间使用普通二分搜索即可。
若不在这个区间，则一定是在middle的右边，那么再对右边进行搜索
+ 如果`nums[middle] < nums[low]`，表示middle处于右部分，那么[middle, high]之间的数都是已排序的，接下来的操作同上

![1.png](https://pic.leetcode-cn.com/2298a3beb5910c6ee002fadb4142dfe34dbf858aedc6ed55af11391132ea2fa9-1.png)

```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binarysearch(low, high):
            # 失败情况
            if low > high:
                return -1
            # 获取中位数
            middle = low + int((high - low) / 2)

            # 判断是否找到目标
            if nums[middle] == target:
                return middle

            # 下一步搜索的方向
            # 如果比头元素小，则表示其右部分已排序
            # 则先判断target是否在右部分
            if nums[middle] < nums[low]:
                if target > nums[middle] and target <= nums[high]:  # (middle, high] 左开右闭区间
               		return binarysearch(middle+1, high)  # 在右部分，则向右搜索
                else:
                    return binarysearch(low, middle-1)  # 否则，target一定在左边，则向左搜索
            else:
            	#  当前元素 >= 头元素，则表示其左部分是已排序的
				#  则先判断是否在左边
                if target >= nums[low] and target < nums[middle]:  # [low, middle) 左闭右开区间
                    return binarysearch(low, middle-1)  # target在左边，则向左搜索
                else:
                    return binarysearch(middle+1, high)  # 否则，target一定在右边，则向右搜索
		
        return binarysearch(0, len(nums)-1)
```
