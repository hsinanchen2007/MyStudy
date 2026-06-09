大致思想：若为1则往后走，若为0，则考虑使用K补救，若K已经用完，则告一段落，进行下一轮的计数
```
func longestOnes(A []int, K int) int {
	// left记录起始位置，right记录终点位置
	var result, left, right int
	for right < len(A) {
		// 起始若为1，则往下走
		if A[right] == 1 {
			right++
		} else {
			// 遇到0则使用K来补救
			if K>0 {
				right++
				K--
			} else {
				// K的次数用完，则告一段落，记录区间的最大的1的连续值
				if result < right-left {
					result = right-left
				}
				// left加1，缩小滑窗，若刚才指向的为0，相当于放弃上一个补救，此时K加1，用作后续的补救
				if A[left] == 0 {
					K++
				}
				left++
			}
		}
	}
	// 用来防止没有用完K的场景
	if result < right-left {
		result = right-left
	}
	return result
}
```