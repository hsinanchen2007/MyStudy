*本篇题解介绍了个人从尝试到暴力解决再到满足题意的解法的过程。如果要直接看正确答案，请直接查看* **解法六、七**。

## 解法一 (失败的尝试)

```go
//	nums=[1,2,3,4,5,6,7], l=7, k=3, k1=3
// 首先需要明确的是，k1 = k % len(nums) 才是真正需要右移的位数，或者叫旋转的次数
	// 直接把数字进行k1位的循环右移
	// nums[0]->nums[3]; ...; nums[4]->nums[7]=nums[0]

// 计算k1，循环右移k1位
func Sol_1_1(nums []int, k int) {

	l := len(nums)
	if l==0 {
		return		// 此时不用做任何动作
	}
	k1 := k % l
	if k1 == 0 {
		return
	}

	var newIndex int
	for i:=0; i<k1; i++ {	//真实有意义的移动只有k1次
		newIndex = (i+k1) % l
		nums[newIndex], nums[i] = nums[i], nums[newIndex]   // 问题出在这一步，各个位置上原来的数据信息丢失了。导致后面的交换就全错了。解决见解法 四、七
	}
	return
}
```

## 解法二 暴力旋转

尝试解题失败后，从暴力解题出发。

```go
// 纯暴力解法，每一次k就旋转1次，旋转一次意味着整体的数据后移
// 不符合题意，时间复杂度O(n*n),空间复杂度O(1)
func Sol_1_2(nums []int, k int) {

	// 边界条件
	l := len(nums)
	if l==0 || k==0 {
		return		// 此时不用做任何动作
	}

	// 旋转k次
	var tmp int
	for i:=0; i<k; i++ {
		// 每次旋转的操作
		tmp = nums[l-1]
		// 前l-1个数据后移一位
		for j:=l-1; j>0; j-- {
			nums[j] = nums[j-1]
		}
		nums[0] = tmp
	}
}
```

## 解法三 暴力旋转优化k

```go
// 纯暴力解法还可以优化k项
// 虽然仍然不符合题目要求
func Sol_1_3(nums []int, k int) {

	// 边界条件
	l := len(nums)
	if l==0 {
		return		// 此时不用做任何动作
	}
	k1 := k % l		// 优化k大于l的情况
	if k1 == 0 {
		return
	}

	// 旋转k次
	var tmp int
	for i:=0; i<k1; i++ {
		// 每次旋转的操作
		tmp = nums[l-1]
		// 前l-1个数据后移一位
		for j:=l-1; j>0; j-- {
			nums[j] = nums[j-1]
		}
		nums[0] = tmp
	}
}
```

## 解法四 辅助数组记录原始状态

```go
// 利用辅助数组记录数组的原始信息，解决一开始Sol_1_1结果错误的问题（原来位置的值丢失）
// 不符合题解要求，时间复杂度和空间复杂度O(n)
func Sol_1_4(nums []int, k int) {

	// 边界条件
	// 边界条件
	l := len(nums)
	if l==0 {
		return		// 此时不用做任何动作
	}
	k1 := k % l		// 优化k大于l的情况
	if k1 == 0 {
		return
	}

	// 辅助数组 nums1保留nums内容
	nums1 := append([]int{}, nums...)

	var newIndex int
	for i:=0; i<l; i++ {	//真实有意义的移动只有k1次
		newIndex = (i+k1) % l
		nums[newIndex] = nums1[i]
	}
	return
}
```

## 解法五 数组拼接

```go
// 数组拼接，把切片前部挪到后部后面，实现最终旋转
// 不符合题意，不是原地修改，时间复杂度O(k),O(k) x  O(n)O(n)
// 由于go语言切片的copy方法特性，这种做法尽管不合题意，但leetcode执行效率非常高
//34/34 cases passed (72 ms)
//Your runtime beats 97.85 % of golang submissions
//Your memory usage beats 95.26 % of golang submissions (7.5 MB)
// 如果不是本题测试所限，可以不使用辅助数组，尽管用到额外空间，如果内存充沛应该是比较高效的选择
func Sol_1_5(nums []int, k int) {

	// 边界条件
	l := len(nums)
	if l==0 {
		return		// 此时不用做任何动作
	}
	k1 := k % l		// 优化k大于l的情况
	if k1 == 0 {
		return
	}

	// 数组拼接，尽管占用的内存一样，但用的不是原来那块，需要内存分配
	//fmt.Println(nums[l-k1:])
	//fmt.Println(nums[:l-k1])
	// !!!!! 需要警惕的是：在go中函数传值是值类型，而切片是引用类型，在该函数内，nums在这一步重新分配了内存，其指针改变，
	// 对于测试样例来说，测试样例时指针是不变的，所以直接下面这样写，无论如何都通不过测试
	//nums = append(nums[l-k1:], nums[:l-k1]...)
	// 所以需要一个辅助数组存新的数组内容，再把辅助数组内容复制到原来的nums，只是这样一来，时空复杂度还是O(n)O(n)
	nums1 := append(nums[l-k1:], nums[:l-k1]...)
	copy(nums, nums1)
	//fmt.Println(nums)
}
```

## 解法六 三次反转

![image.png](https://pic.leetcode-cn.com/0e29d4f2abe05133b800540a7e2a61e7f3f3812071e6e1f74852eb806878723b-image.png)

```go
// 三重翻转。先全部翻转一次，再翻转前k个，再翻转后边的
// 这种解法满足题意，O(n)时间，O(1)空间。并且由于没有分配数组空间等操作，总执行时间并不落后解法五
//34/34 cases passed (68 ms)
//Your runtime beats 99.28 % of golang submissions
//Your memory usage beats 90 % of golang submissions (7.6 MB)
func Sol_1_6(nums []int, k int) {

	// 边界条件
	l := len(nums)
	if l==0 {return}
	k1 := k % l		// 优化k大于l的情况
	if k1 == 0 {return}

	// 连续三次翻转
	reverse(nums)
	reverse(nums[:k1])
	reverse(nums[k1:])
}

// 数组的原地反转
func reverse(a []int) {
	// go语言有多重赋值，不需要我们再提供中间变量
	l := len(a)
	for i:=0; i<l/2; i++ {
		a[i], a[l-i-1] = a[l-i-1], a[i]
	}
}
```

## 解法七 环状替换

参考：<https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode/>

![image.png](https://pic.leetcode-cn.com/35b5b327f297a7f50a00dd716e0d840eeefd56939e8c1c61f045d1309197101f-image.png)

```go
// 环状替换
// 在解答Sol_1_1中因为直接对k次旋转后的位置进行处理，原始数据丢失，所以失败了。
// Sol_1_4将原数组拷贝了一份用来保留原始信息，解决了这个问题，但它不是一个O(1)空间复杂度的方法

// 看到的一个非常好的理解思路：
// 把元素看做同学，把下标看做座位，大家换座位。
// 第一个同学离开座位去第k+1个座位，第k+1个座位的同学被挤出去了，他就去坐他后k个座位，如此反复。
// 但是会出现一种情况，就是其中一个同学被挤开之后，坐到了第一个同学的位置（空位置，没人被挤出来），但是此时还有人没有调换位置，这样就顺着让第二个同学换位置。
// 那么什么时候就可以保证每个同学都换完了呢？n个同学，换n次，所以用一个count来计数即可。

//34/34 cases passed (72 ms)
//Your runtime beats 97.85 % of golang submissions
//Your memory usage beats 89.47 % of golang submissions (7.6 MB)
func Sol_1_7(nums []int, k int) {

	// 边界条件
	l := len(nums)
	if l==0 {return}
	k1 := k % l		// 优化k大于l的情况
	if k1 == 0 {return}

	var count int
	for start:=0; count < l; start++ {	// n个同学就需要换n次, 用count来控制终止
		// start标记每一个环的起始出发位置

		// current标记当前数据的数组下标，prev则用来标记当前数据
		current := start
		prev := nums[start]

		for {
			next := (current + k1) % l		// 当前数据的最终位置
			temp := nums[next]				// 将原next位置的数据备份
			nums[next] = prev				// 将当前数据(prev)赋给next位置

			prev = temp						// 再更新prev为原next位置的数据
			current = next					// 更新当前下标为next

			count++

			// 避免start -> next -> start的死循环，出现这种情况，start++
			// 或者说，当成环后，则将环的起始出发点向后移一位
			if start == current {	// 成环，跑到了start位置，则跳出内层循环
				break
			}
		}
	}
}

// 将循环内变量声明在循环外，避免多次分配回收内存空间
func Sol_1_8(nums []int, k int) {

	// 边界条件
	l := len(nums)
	if l==0 {return}
	k = k % l		// 优化k大于l的情况
	if k == 0 {return}

	// 避免在循环中多次分配内存及回收
	var count int
	var current int
	var prev int
	var next int
	var temp int
	for start:=0; count < l; start++ {	// n个同学就需要换n次, 用count来控制终止
		// start标记每一个环的起始出发位置

		// current标记当前数据的数组下标，prev则用来标记当前数据
		current = start
		prev = nums[start]

		for {
			next = (current + k) % l		// 当前数据的最终位置
			temp = nums[next]				// 将原next位置的数据备份
			nums[next] = prev				// 将当前数据(prev)赋给next位置

			prev = temp						// 再更新prev为原next位置的数据
			current = next					// 更新当前下标为next

			count++

			// 避免start -> next -> start的死循环，出现这种情况，start++
			// 或者说，当成环后，则将环的起始出发点向后移一位
			if start == current {	// 成环，跑到了start位置，则跳出内层循环
				break
			}
		}
	}
}
```

## 个人博客

<https://eiger.me/post/algo/lt189/>