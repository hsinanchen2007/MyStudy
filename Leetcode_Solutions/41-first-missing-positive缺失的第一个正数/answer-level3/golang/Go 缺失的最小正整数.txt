### 解题思路
首先考虑最佳情况一定是n长数组,下标0~(n-1)上的数分别为1~n，我们可以认为一个不缺。所以有效值也是在（1,n）。
遍历一遍数组，如果下标对应的值是有效值且不等于index+1，就将它交换到满足index+1的位置，再看换来的值是不是有效值或者等于index+1。
最后遍历一遍找到nums[index]!=index+1的点，则index+1就是缺失的最小正整数。

本思路参考了：[https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/]

### 代码

```golang
func firstMissingPositive(nums []int) int {
    if len(nums)==0{
		return 1
	}
	for i:=0;i<len(nums);i++{
		for nums[i]>0 && nums[i]<=len(nums) && nums[nums[i]-1]!=nums[i]{
			nums[nums[i]-1],nums[i]=nums[i],nums[nums[i]-1]
		}
	}
	for i:=0;i<len(nums);i++{
		if nums[i]!=i+1{
			return i+1
		}
	}
	return len(nums)+1
}
```