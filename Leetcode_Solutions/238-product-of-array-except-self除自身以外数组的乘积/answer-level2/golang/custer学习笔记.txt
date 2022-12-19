除法解法

1. 有序列表求所有数的乘积
2. 对于有序列表每个数，结果为乘积除以当前数
3. 注意有序列表0的情况，标记0的位置，如果有两个0就都是0，如果只有一个0，除了0之外都是0。

```go
func productExceptSelf(nums []int) []int {
	var result []int // 输出数组
	tmp := 1         // 保存乘积的变量
	var mark []int   // 记录0的个数
	for i, v := range nums {
		if v == 0 { // 如果原始数组中有0
			mark = append(mark, i) // 记录0的位置
			tmp = tmp * 1          // 乘积不用乘以0
		} else {
			tmp = tmp * v // 乘积继续乘以值
		}
		if len(mark) > 1 { // 如果0的个数大于1个
			tmp = 0 // 乘积总是为0
		}
	}

	for i, v := range nums {
		if len(mark) == 1 { // 如果0的个数为1个
			if i == mark[0] {
				result = append(result, tmp) // 除了0的位置的乘积不是0
			} else {
				result = append(result, 0) // 其余位置都是0
			}
		} else if len(mark) > 1 { // 如果0的个数大于1个
			result = append(result, 0) // 所有位置都是0
		} else {
			result = append(result, tmp/v) // 如果没有0，正常输出
		}
	}
	return result
}
```

不用除法解法

1. 换一个角度，乘法满足结合律，a*b*(c)*d*e => [a*b]*[d*e]
2. (暴力解)对于每个数，算其左边和右边所有数乘积O(N^2)
3. 思考冗余
4. 维护两个乘积数组，O(N)


![1559884014644-bf2b6a66-a2f1-4bf2-9aa7-3d4dec64160d.png](https://pic.leetcode-cn.com/981871c2570719c373e584b01cda90db2161e9b9752326712d820a1f89dc933d-1559884014644-bf2b6a66-a2f1-4bf2-9aa7-3d4dec64160d.png)

```go
func productExceptSelf(nums []int) []int {
	left := 1
	right := 1
	output := make([]int, len(nums))
	// 左积
	for i := 0; i < len(nums); i++ {
		output[i] = left
		left *= nums[i]
	}
        // 右积
	for i := len(nums) - 1; i >= 0; i-- {
		output[i] *= right
		right *= nums[i]
	}
    return output
}
```