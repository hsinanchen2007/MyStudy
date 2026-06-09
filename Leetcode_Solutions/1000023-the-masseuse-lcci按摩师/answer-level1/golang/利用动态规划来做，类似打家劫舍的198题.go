### 解题思路
类似198题  基本上就是换个描述而已

### 代码

```golang
func massage(nums []int) int {
	l := len(nums)
	switch l {
	case 0:
		return 0
	case 1:
		return nums[0]
	default:
		var makeArr func(l1,l2 int) [][]int
		makeArr = func(l1, l2 int) [][]int {
			arr := make([][]int,l1)
			for i:=0;i<l1;i++{
				arr[i] = make([]int,l2)
			}
			return arr
		}
		var maxFunc func(a,b int) int
		maxFunc = func(a, b int) int {
			if a>b{
				return a
			}
			return b
		}

		// 构造一个dp二维数组 0表示不抢 1表示前面一个不抢加自身
		dp := makeArr(l,2)
		dp[0][0],dp[0][1] = 0,nums[0]
		for i:=1;i<l;i++{
			dp[i][0] = maxFunc(dp[i-1][0],dp[i-1][1])
			dp[i][1] = dp[i-1][0]+nums[i]
		}
		return maxFunc(dp[l-1][0],dp[l-1][1])
	}
}

```