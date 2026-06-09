![image.png](https://pic.leetcode-cn.com/2575a945360c2a55227c10abb302791dc546da89134b33da6759f06f29fe7e27-image.png)
```
func twoSum(numbers []int, target int) []int {
	for i, j := 0, len(numbers)-1; i < j; {
		if numbers[i]+numbers[j] > target {
			j--
		} else if numbers[i]+numbers[j] < target {
			i++
		} else {
			return []int{i+1, j+1}
		}
	}
	return []int{}
}
```
