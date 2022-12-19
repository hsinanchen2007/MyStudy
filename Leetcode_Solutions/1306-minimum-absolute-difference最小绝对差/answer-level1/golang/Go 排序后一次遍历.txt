```
func minimumAbsDifference(arr []int) [][]int {
    res := make([][]int, 0)
    if len(arr) == 0 || len(arr) == 1 {return res}
	sort.Ints(arr)
	temp := arr[1] - arr[0]
	res = append(res, []int{arr[0], arr[1]})
	for i := 1; i < len(arr) - 1; i ++ {
		if arr[i + 1] - arr[i]  < temp {
			temp = arr[i + 1] - arr[i]
			res = make([][]int, 0)
		}

		if arr[i + 1] - arr[i]  == temp {
			res = append(res, []int{arr[i], arr[i + 1]})
		}
	}

	return res

}
```
