执行用时 : 4 ms , 在所有 golang 提交中击败了 100.00% 的用户 内存消耗 : 3.4 MB , 在所有 golang 提交中击败了 100.00% 的用户
func duplicateZeros(arr []int)  {
	res := make([]int, len(arr))
	copy(res, arr)
	temp := 0
	for _, v := range res{
		if temp >= len(arr) {
			break
		}
		if v == 0 {
			arr[temp] = 0
			if temp + 1 < len(arr) {
				arr[temp + 1] = 0
			}
			temp ++
		} else {
			arr[temp] = v
		}
		if temp + 1 == len(arr) {
			break
		}
		temp ++
	}
}