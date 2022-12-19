### 解题思路
从数组的最右端开始扫描，找到从右向左递增的递增序列，158476531的数组序列，可以知道从右边往左边扫描的过程中发现13657是递增的序列，而到4的时候则不是递增的序列了，因为4大于了7，所以这个时候循环结束，循环变量记录了4这个位置，
在后面递增的序列中从右往左找到第一个比4大的位置可以知道是13657中的5对应的位置，这个时候需要将4的位置与5的位置进行互换，
因为调换元素之后那么剩下来的从左到右是递增的，所以需要进行翻转，应该是从4这个位置后面进行翻转，这样形成的数字序列才是下一个更大的排列


### 代码

```golang
func nextPermutation(nums []int)  {
// 第一步从右往左查找最大的升序队列
	i := len(nums)-2// 倒数第二个数
	for i >= 0&&nums[i]>=nums[i+1] {
		i--
	}
	if i==-1 {
		// 从右往左一直是升序
		sort.Ints(nums)
	}else {
		j := len(nums)-1
		// 从右往左找第一个比i索引值大的数字索引坐标
		for j>=0&&nums[j]<=nums[i]{
			j--
		}
		//交换他两位置
		nums[i], nums[j] = nums[j], nums[i]
		// 重新排序
		sort.Ints(nums[i+1:])

	}
	//fmt.Println(nums)
}
```
![image.png](https://pic.leetcode-cn.com/0d0e52dea2ee5312e2bb3e651b15b51fd6b9940b761eae33b9b580d9f53d97f5-image.png)
