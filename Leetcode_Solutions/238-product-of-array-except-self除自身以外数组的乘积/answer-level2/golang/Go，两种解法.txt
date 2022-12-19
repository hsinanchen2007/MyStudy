解法一：
除自身以外所有数的乘积，可分为两部分
即自身左边所有数的乘积，与自身右边所有数的乘积，再将左右两部分的乘积乘起来，即为除自身以外所有数的乘积
所以根据以上思路，可用两个slice L和R，L[i]表示第i个数左侧所有数的乘积，R[i]表示第i个数右侧所有数的乘积
最后第i个数除自身以外所有数的乘积即为L[i] * R[i]
时间复杂度: O(n)
空间复杂度: O(n)
```
func productExceptSelf(nums []int) []int {
	length := len(nums)
	L := make([]int, length)
	R := make([]int, length)
	ans := make([]int, length)
	// 计算第i个数左侧所有数的乘积
	for i := 0; i < length; i++ {
		if i == 0 {
			L[i] = 1
		} else {
			L[i] = nums[i-1] * L[i-1]
		}
	}
	// 计算第i个数右侧所有数的乘积
	for i := length - 1; i >= 0; i-- {
		if i == length-1 {
			R[i] = 1
		} else {
			R[i] = nums[i+1] * R[i+1]
		}
	}
	// 第i个数除自身以外所有数的乘积即为L[i] * R[i]
	for i := 0; i < length; i++ {
		ans[i] = L[i] * R[i]
	}
	return ans
}
```

解法二：
题目进一步要求在常数空间复杂度内完成，而解法一的空间复杂度为O(n)，因为输出数组不被计算在时间复杂度内，所以我们要看有没有办法不用解法一种的L和R
时间复杂度: O(n)
空间复杂度: O(1)
```
func productExceptSelf(nums []int) []int {
    // 数组中某数除自身以外各元素的乘积=该数左侧所有数的乘积*该数右侧所有数的乘积
    length := len(nums)
    out := make([]int, length)
    k := 1
    // 求每个数左侧所有数的乘积
    for i := 0; i < length; i++ {
        out[i] = k
        k *= nums[i]
    }
    // 求每个数右侧所有数的乘积，并与其左侧所有数乘积相乘
    k = 1
    for i := length - 1; i >= 0; i-- {
        out[i] = out[i] * k
        k *= nums[i]
    }
    return out
}
```
