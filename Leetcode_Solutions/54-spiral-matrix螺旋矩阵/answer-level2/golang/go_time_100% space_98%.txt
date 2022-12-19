### 解题思路

思想
/\------->
|		|
|		|
|		|
<-------\/

1. 判断空输入
2. 循环判定，结束条件
### 代码

```golang
func spiralOrder(matrix [][]int) []int {
	var result []int
    if len(matrix) == 0{
        return result
    }
	var left,right = 0,len(matrix[0])-1
	var top, bottom = 0,len(matrix)-1

	var row,col int
	for left<=right && top<=bottom{
		for col = left;col<=right && top<=bottom && left<=right;col++  {
			result = append(result, matrix[row][col])
		}
		col--
		top++
		for row = top;row<=bottom && top<=bottom && left<=right;row++  {
			result = append(result, matrix[row][col])
		}
		row--
		right--
		for col = right;col>=left && top<=bottom && left<=right;col--  {
			result = append(result, matrix[row][col])
		}
		col++
		bottom--
		for row=bottom;row>=top && top<=bottom && left<=right;row-- {
			result = append(result, matrix[row][col])
		}
		row++
		left++
	}
	return result
}
```