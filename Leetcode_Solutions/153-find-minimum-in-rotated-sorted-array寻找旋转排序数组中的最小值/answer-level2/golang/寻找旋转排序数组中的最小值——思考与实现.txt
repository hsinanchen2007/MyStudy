

```go
package lt153

// 寻找旋转排序数组中的最小值
// 按升序排列的数组在某个点进行了旋转操作，找出其中最小值
// 例如 [0,1,2,4,5,6,7] 旋转为 [4,5,6,7,0,1,2] 其中最小值为 0
// 假设元素不重复

// 思考:
// 1. 最直接的想法便是从前向后遍历当发现当前数比下一个数大，则下一个数就是最小值。 时间O(n)
// 2. 当数据量非常大时，O(n)可能比较耗时， 有序数组中最快的查找是二分查找 （关于二分、三分、...查找，还是二分好用，分更多不一定变快）
// 		尽管旋转过一次，但可以利用二分查找来追踪旋转点。

// 1. 暴力解（一次遍历）
//146/146 cases passed (4 ms)
//Your runtime beats 70.29 % of golang submissions
//Your memory usage beats 68.18 % of golang submissions (2.5 MB)
func findMin(nums []int) int {

	// 特殊情况
	if len(nums)==0 {return 0}

	// 一般情况
	for i:=0; i<len(nums)-1; i++ {
		if nums[i]>nums[i+1] {return nums[i+1]}
	}
	return nums[0]	// 找不到转折点，说明没有进行旋转，或者说旋转点在nums[0]
}

// 2. 二分查找
// 146/146 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 68.18 % of golang submissions (2.5 MB)
func findMin2(nums []int) int {

	// 特殊情况
	length := len(nums)
	if length==0 {return -1}
	if length==1 {return nums[0]}

	// nums无重复元素
	// 判断数组是否被旋转: nums[0] > nums[l-1]	小于说明没旋转， 大于说明旋转过
	// 例如 [1,2,3,4,5] => [4,5,1,2,3]
	if nums[0] < nums[length-1] {return nums[0]}

	// 注意旋转规律，以前面的例子为例， 称3与4中间为旋转点，之后的部分被旋转至数组前面。
	// 旋转后称5和1中间为影响点k，以k为界， 左边元素都比nums[0]大，右边元素都比nums[0]小
	// 找到这个影响点k就找到 min 了， k右邻元素就是

	// 找中间元素方法：
	// mid > nums[0] => 影响点 k 在mid右边
	// mid < nums[0] => 影响点 k 在mid左边
	// 何时停止？
	// mid > mid+1 => mid+1是最小值
	// mid-1 > mid => mid是最小值

	l, r, mid := 0, len(nums)-1, 0	// 都是下标
	for r>=l {
		mid = l + (r-l)/2	// 这样写不容易整型溢出

		// 停止条件
		if nums[mid] > nums[mid+1] {return nums[mid+1]}
		if nums[mid-1] > nums[mid] {return nums[mid]}

		// 更新边界
		if nums[mid] > nums[0] {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	return -1
}

// 3. 二分查找
// 上面的解法利用了 影响点与nums[0]的大小关系来找
// 当然也可直接利用 影响点两边数据的大小关系 nums[i]>nums[i+1] 来结合二分查找来找
// 参考 题解区 windliang 做法
//
func findMin3(nums []int) int {

	// 特殊情况
	length := len(nums)
	if length==0 {return -1}
	if length==1 {return nums[0]}
	if nums[0] < nums[length-1] {return nums[0]}

	l, r, mid := 0, len(nums)-1, 0	// 都是下标
	for l<r { // 当 l,r相邻时， mid=l

		// 不管边界如何变化，只要包含影响点，则 nums[r] < nums[l]
		if nums[l] < nums[r] {
			return nums[l]
		}

		mid = l + (r-l)/2 // 这样写不容易整型溢出

		if nums[mid] >= nums[l] {
			l = mid + 1 // 右半区间可能包含影响点
		} else {
			r = mid // 左半区间可能包含影响点
		}
	}
	// 迭代完成后l就是影响点

	return nums[l]
}

// 4. 递归分治
// 直接将区间不断斩半，影响点所在的区间一定是无序区间，而另一半则是有序区间
//146/146 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 68.18 % of golang submissions (2.5 MB)
func findMin4(nums []int) int {
	return searchMin(nums, 0, len(nums)-1)
}

func searchMin(nums []int, l, r int) int {
	if nums[l] <= nums[r] {	// 有序状态直接返回有序区间中最小值(最左)
		return nums[l]
	} else {	// 对无序区间做处理
		mid := l + (r-l)/2
		return min(searchMin(nums, l, mid), searchMin(nums, mid+1, r))
	}

}

func min(a, b int) int {
	if a>=b {return b}
	return a
}


// 递归分治 优化
// 在上面的解法中当发现有序的区间之后，这有序的区间中是没必要继续递归下去的
// 而优化的解法其实就是前面二分查找的过程

```