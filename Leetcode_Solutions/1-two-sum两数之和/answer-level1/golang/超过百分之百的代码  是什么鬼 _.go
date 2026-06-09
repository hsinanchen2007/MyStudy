```
func twoSum(nums []int, target int) []int {
	maps := make(map[int][]int, len(nums))
	for k, value := range nums {
		num1, ok := maps[value]
		if ok {
			maps[value] = append(num1, k)
		} else {
			maps[value] = []int{k}
		}
		k1 := value
		v := maps[value]
		if target == k1+k1 {
			//fmt.Println("到达?", k, target)
			if len(v) > 1 {
				return []int{v[0], v[1]}
			}
		} else {
			num1 := target - k1
			//fmt.Println(k, num1, "-----")
			Arr, ok := maps[num1]
			if ok {
				return []int{v[0], Arr[0]}
			}
		}
	}

	return []int{0, 0}
}

```
![超过百分之百.png](https://pic.leetcode-cn.com/aa74d742725badc829448dc58362a64e79b23cc2e817faa67f67a04776fa7fc4-%E8%B6%85%E8%BF%87%E7%99%BE%E5%88%86%E4%B9%8B%E7%99%BE.png)
