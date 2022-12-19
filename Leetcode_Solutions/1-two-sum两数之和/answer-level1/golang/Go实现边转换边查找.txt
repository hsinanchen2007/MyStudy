func main() {
	res := TwoSum([]int{2, 17, 11, 15, 7}, 9)
	fmt.Println(res)
}

func TwoSum(nums []int, target int) []int {
	numsMap := map[int]int{}
	for i, v := range nums {
		if j,ok := numsMap[target-v]; ok!=false {
			return []int{i, j}
		}
		numsMap[v] = i
	}
	return []int{}
}