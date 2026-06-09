


## 解题前思考

```go
// 解题前思考：
// 1. 最傻： 从前向后遍历，遇0则将0其后所有元素前挪一位，末位补0.   时间O(n*n/2)， 空间O(1)
// 2. 进一步： 先使用一个循环，使用一个数组，记录所有0的位置，接着使用第二个循环，遍历这个数组，计算非零元素的最终迁移量，统一迁移。 时间O（n）,空间O(n/2)
// 3. 使用一个新数组，扫描原数组，非零插左，0插右。（不符题意）
// 4. 使用一个移动指针（数组下标，从0开始），每次扫到非零数，就赋到该位置。这种做法是使用数据赋值替换搬迁。  这样也是O(n)，
```

## 解法一 
```go
// 两次循环，双指针， 第一次把非零赋到前面，第二次后面补0. (空间最优，操作局部优化)
//21/21 cases passed (92 ms)
//Your runtime beats 59.62 % of golang submissions
//Your memory usage beats 94.61 % of golang submissions (7.7 MB)
func Sol_1_1(nums []int) {

	// 不检查数组长度为0的情况了
	var lastNonZeroAt int		// 处理到的、最后一个非零数字应该填到的位置
	for _, v := range nums {
		if v != 0 {
			nums[lastNonZeroAt] = v
			lastNonZeroAt++
		}
	}

	// 后边补0
	for i:=lastNonZeroAt; i<len(nums); i++ {
		nums[i] = 0
	}
}
```

## 解法二

```go
// 一次循环遍历，双指针。 一个指针记录一段连续0开始的位置，一个遍历指针用来找到连续0之后的第一个非0，两者交换。
// 当输入数组中连续0比较多时，这个方法比上一个操作更优
//21/21 cases passed (84 ms)
//Your runtime beats 98.45 % of golang submissions
//Your memory usage beats 85.29 % of golang submissions (7.9 MB)
func Sol_1_2(nums []int) {

	var lastNonZeroAt int
	for i:=0; i<len(nums)-1; i++ {
		if nums[i] != 0 {
			// 遇到0则和其后一位进行交换
			nums[i], nums[lastNonZeroAt] = nums[lastNonZeroAt], nums[i]
			lastNonZeroAt++		// lastNonZeroAt记录上一个不为0的数在交换之后的位置
			// 也就是当前非0数前面的连续0的第一个0的位置。
		}
	}
}
```

## 解法三

```go

// 优化Sol_1_2, 在判断i与lastNonZeroAt不相等（相等时也就是自己赋给自己）时再交换
//21/21 cases passed (80 ms)
//Your runtime beats 99.88 % of golang submissions
//Your memory usage beats 94.12 % of golang submissions (7.7 MB)
func Sol_1_3(nums []int) {

	var lastNonZeroAt int
	for i:=0; i<len(nums)-1; i++ {
		if nums[i] != 0 {
			if i != lastNonZeroAt {		// 相等说明是同一个数
				nums[i], nums[lastNonZeroAt] = nums[lastNonZeroAt], nums[i]
			}
			lastNonZeroAt++
		}
	}
}

```