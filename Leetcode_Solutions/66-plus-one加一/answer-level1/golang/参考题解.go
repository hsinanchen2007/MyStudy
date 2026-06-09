![image.png](https://pic.leetcode-cn.com/cadd2f9103ce3765f32138c708673b5d70d5ef71066e81823f0f8d34f57a499b-image.png)

```
func plusOne(digits []int) []int {
    end := len(digits) - 1
	for i := end; i >= 0; i-- {
		digits[i] = digits[i] + 1
		digits[i] = digits[i] % 10
		if digits[i] != 0 {
			return digits
		}
	}
	tmp := end + 2
	ret := make([]int, tmp)
	ret[0] = 1

	return ret
}
```
参考题解 ： https://leetcode-cn.com/problems/plus-one/solution/hua-jie-suan-fa-66-jia-yi-by-guanpengchn/