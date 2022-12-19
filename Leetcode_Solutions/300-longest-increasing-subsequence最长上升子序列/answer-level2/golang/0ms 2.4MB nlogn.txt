### 解题思路

参考 //https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
加提前判断

### 代码

```golang
/*
n*logn  dp【i】记录的是 长度为i+1的上升字串的最后一个数字，使用贪心算法，维护最后一个数字要最小的
*/
func lengthOfLIS(nums []int) int {

	count := len(nums)
	if count <= 1 {
		return count
	}

	dp := make([]int, count+1)
	dp[1] = nums[0] //看第一个字符 ，当前长度为1的字串的最后一个数字就是nums【0】
	maxLen := 1
	for i := 1; i < count; i++ {
        // fmt.Println(dp,maxLen)

		if nums[i] <= dp[1] { //如果比长度为一的尾号数字（其实也就是数组当前的最小值）还要小 或相等
			dp[1] = nums[i]
			continue
		}

		//等于当前最长子序列的最后一个数字
		if nums[i] == dp[maxLen] {
			continue
		}

		//大于当前最长子序列的最后一个数字
		if nums[i] > dp[maxLen] {
			maxLen++
			dp[maxLen] = nums[i]
			continue
		}

		dp[biFind(dp[1:], maxLen, nums[i])+1] = nums[i]
	}
    // fmt.Println(dp)
	return maxLen

}

// 要查找大于等于value的 最小数
func biFind(dp []int, num int, value int) int {

	beg := 0
	end := num - 1

	for beg < end {

		mid := (beg + end) / 2
        // fmt.Println(beg,end,mid)

		if dp[mid] < value { // 如果要求非严格递增，将此行 '<' 改为 '<=' 即可。
			beg = mid + 1
		} else {
			end = mid
		}
	}

	return beg

}

```