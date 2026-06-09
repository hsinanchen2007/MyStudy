golang解法，双指针之滑动窗口法

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 双指针之滑动窗口法
// 时间复杂度：O(target)  空间复杂度：O(1)

func findContinuousSequence(target int) [][]int {
	var res [][]int

	t := (target+1)/2
	i := 1  // 左边界
	j := 1  // 右边界

	for j<=t && i<=j {
		sum := (i+j)*(j-i+1)/2  // 区间 [i,j] 的和，即: i+(i+1)+(i+2)+...+j
		if sum<target {
			j++  // 右移右边界，扩大区间和
		} else if sum>target {
			i++  // 右移左边界，缩小区间和
		}else {  
			temp := []int{}
			for k:=i; k<=j; k++ {
				temp = append(temp, k)
			}
			res = append(res, temp)
			i++  // 记录本次区间后，尝试获取下一个区间
		}
	}

	return res
}
```
