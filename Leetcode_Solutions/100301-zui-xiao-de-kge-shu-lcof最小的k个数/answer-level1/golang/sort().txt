### 解题思路
使用sort()函数，对数组进行从小到大排序，再输出arr[0:k]的切片

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
    if k > len(arr){
		fmt.Println("请重新输入")
	}else if k == 0{
		return []int{}
	}else if len(arr)>10000{
		fmt.Println("请重新输入")
	}else if k == len(arr){
		return arr
	}
	sort.Ints(arr[:])
	return arr[0:k]
}

```