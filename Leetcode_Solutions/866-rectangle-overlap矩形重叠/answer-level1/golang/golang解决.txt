golang解决

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 时间复杂度：O(1)  空间复杂度：O(1)

func isRectangleOverlap(rec1 []int, rec2 []int) bool {

	if rec2[0]>=rec1[2] || rec2[2]<=rec1[0] || 
	rec2[1]>=rec1[3] || rec2[3]<=rec1[1] {
		return false
	}

	return true
}
```
