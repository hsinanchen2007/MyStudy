### 解题思路

双指针枚举，sum = (l + r) * (r - l + 1) / 2求当前左右指针中间的数字之和，若sum==target则把当前两指针中间的序列加入res，若sum < target,右指针需要往右移动，若sum > target，左指针需要往右移动。

### 代码

```golang
func findContinuousSequence(target int) [][]int {
	l,r := 1,2
	tmp := []int{}
	res := [][]int{}
	for l < r {
		sum := (l + r) * (r - l + 1) / 2
		if sum == target {
			for i := l;i <= r;i++ {
				tmp = append(tmp,i)
			}
			res = append(res,tmp)
			tmp = []int{}
			l++
		}else if sum < target {
				r++
		}else {
				l++
		}
	}
	return res
}
```