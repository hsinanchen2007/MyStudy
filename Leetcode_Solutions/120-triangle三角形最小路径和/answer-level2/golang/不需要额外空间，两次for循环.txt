### 解题思路
从低至上找出最小值，使用三角形最后一行保存最小值

### 代码

```golang
func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	minList := triangle[len(triangle)-1]
	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j < len(triangle[i]); j++ {
			if minList[j]+triangle[i][j] < minList[j+1]+triangle[i][j] {
				minList[j] = minList[j] + triangle[i][j]
			} else {
				minList[j] = minList[j+1] + triangle[i][j]
			}
		}
	}
	return minList[0]
}
```