### 解题思路

对于每一层中的数据i，有： i = 上一层的i + 上一层的i-1

### 代码

```golang
func getRow(rowIndex int) []int {
	result := []int{1,1}
	var plus,rows int
	temp := make([]int,0)
    if (rowIndex == 0 ){
        return []int{1}
    }
	if (rowIndex == 1){
		return result
	}
	rows = 1
	for {
		for i := 0; i <= rows + 1; i++ {
			if i == 0 || i == rows + 1{		//	 边界判断
				plus = 1
			}else{
				plus = result[i] + result[i-1]
			}
			temp = append(temp,plus)
		}
		result = temp
        temp = []int{}
		rows++
		if (rowIndex == rows ){
			break
		}
	}
	return result
}
```