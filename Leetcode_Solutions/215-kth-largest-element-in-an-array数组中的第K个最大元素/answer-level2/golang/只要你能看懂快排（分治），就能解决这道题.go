第一个直观的想法：每次找出最大的数，找K次，这个复杂度大概是k*n，看起来像是O(n)，实际如果k很接近n的话，复杂度是n*n
另外一个直观的想法是：倒序排序，然后找第k个
但是就算用快排，平均复杂度也是n*logn，
我们通过在快排的过程中判断是否已经得到了第k大的数，来节约一些时间，大概是O(n)

我们知道，快排的思想是：先分区，再按轴点，划分左中右三块，左 <= 中 <= 右 （或者 左 >= 中 >= 右）

梳理出一条解法如下：
示例 1:
输入: nums[3,2,1,5,6,4] 和 k = 2
输出: 5
##start
我们按逆序来进行快排（建议可以先把逆序快排写对了）
每次就选择区间的最后一位当作轴点(pivot)的值来比较，那也就是4，一次分区后，
得到 [5,6], 4, [3,2,1]
现在  [5,6] 拥有最大的两个数, 4 第三大， [3,2,1] 是最后三大个数 

如果 k == 3, 那么 nums[3] == 4，也就是说 4 正好是第三大，直接返回；
如果 k < 3, 也就是说第k大的数在[5, 6]里面, 反之同理, 如果 k > 3，那么第k大的数在 [3,2,1]里

因为 k==2, k > 3, 所以我们就去 [3,2,1]寻找我们要的第k大的数

一直分区，每次我们都缩小第k大数所在的区间范围，直到这个区间只剩下一个元素，就是我们要找的第k大。

附代码，快排中断，性能一般般吧，欢迎交流。
```
func findKthLargest(nums []int, k int) int {
	return findK(nums,0, len(nums)-1, k )
}

func findK(nums []int, s, e, k int) int {
	if s >= e {
		return nums[e]
	}
	p := partition(nums, s, e)

	if p + 1 == k {
		return nums[p]
	} else if p + 1 < k {
		return findK(nums, p+1, e, k)
	} else {
		return findK(nums, s, p-1, k)
	}
}


func partition(nums []int, s ,e int) (i int) {
	pivot := nums[e]
	i = s
	for j:=s;j<e;j++ {
		if nums[j] > pivot {
			if i != j {
				nums[i], nums[j] = nums[j], nums[i]
			}
			i++
		}
	}
	nums[i], nums[e] = nums[e], nums[i]
	return i
}
```
