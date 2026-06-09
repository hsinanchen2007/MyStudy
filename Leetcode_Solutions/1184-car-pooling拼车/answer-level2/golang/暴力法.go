### 解题思路
用数组来存储车上人数，以上车点和下车点的值为数组下标保存人数，上车点保存为正数，下车点保存为负数，最后遍历数组，如果车上总人数超过座位数则返回false，如果数组遍历完成则返回true

### 代码

```golang
func carPooling(trips [][]int, capacity int) bool {
var arr [1001]int
	fmt.Println(len(trips))
	for i:=0; i<len(trips); i++ {
		a := trips[i][1]
		b := trips[i][2]
		arr[a] = arr[a] + trips[i][0]
		arr[b] = arr[b] - trips[i][0]


	}

	var total int

	for j:=0; j<len(arr); j++ {
		total += arr[j]
		if total > capacity {
			return false
		}
	}
	return true
}
```