# 解法一

基本思路其实与双指针法一致。

流程可描述为：

1. 从前向后遍历；
2. index记录移值后的最新不重复前缀子数组最后一位下标（按字符串里边的前缀子串那么理解）；
3. 如果新扫到的值与前缀子数组最新值相等（默认给定数组从小到大），则继续遍历下一个；
4. 如果新扫到的值更大，将index加1，并其赋值到新的index位置。

```go
func removeDuplicates(nums []int) int {
    var index int
    for i:=0; i<len(nums); i++ {
        if nums[i] > nums[index] {
            if i > index + 1 {      // 这个数值比较可以优化
                index++
                nums[index] = nums[i]
                continue
            }
            index++
        }
    }
    return index + 1
}
```

个人认为可优化的点在`if i > index + 1`一句，因为按照这个思路，当第一次出现重复元素之后，即便是一直不重复，也要执行`if i > index + 1`判断，其实这是不必要的，因此考虑增加一个布尔值来标记是否出现了重复的情况，这样就形成了解法二。

# 解法二

```go
func removeDuplicates(nums []int) int {
    var index int
    var repeated bool
    for i:=0; i<len(nums); i++ {      
        if nums[i] > nums[index] {
        
            // 如果已经出现重复（这么做是用bool比较替代数值大小比较）
            if repeated {
                index++
                nums[index] = nums[i]
                continue    //不用继续下去了，省一个判断
            }
            // 第一次出现重复
            if i > index + 1 {
                repeated = true
                index++
                nums[index] = nums[i]
                continue
            }
            index++     // 当没有出现重复时
        }
        //相等则不动,继续向后遍历
    }
    return index + 1
}
```

能够看出，修改后的代码在遇到重复情况较多的情况下效率是会提高的，但如果是重复情况较少甚至没有，它反倒在每次遍历多了一道判断。

# 解法三

解法一、二都是双指针的思路。其实完全不需要双指针也可以做到.

只要当前元素大于前一个元素，那么就直接把它加到前缀不重复子数组的末尾就可以了，因为数组已经是排好序的啊！

```go
func removeDuplicates(nums []int) int {

    // 这里不检查排序数组为空的情况，为空还叫啥排序数组

	var index int
	for i:=1; i<len(nums); i++ {
		if nums[i] > nums[i-1] {
			index++
			nums[index] = nums[i]
		}
		// 若现在的数没有比前缀不重复子数组最大值大，那说明重复了，啥也不干
	}

	return index+1
}
```

# 解法四

贴上一道我觉得有意思的题解：

<https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-fen/>

```go
func removeDuplicates(nums []int) int {
	for i:=len(nums)-1; i>0; i-- {
		if nums[i] == nums[i-1] {
			nums = append(nums[:i], nums[i+1:]...)
		}
	}
	return len(nums)
}
```

这个思路是：
倒序遍历，遇到还没有遍历到的前面部分和已经遍历过的（除了当前这次比较）进行拼接成新数组。等于说，如果双指针法是进行了O(n)的指针移动和数组改值，那么这种思路则就是进行了O(n)的数组重新生成。

在go语言中这种切片的append只要容量够，就不会重分配数组空间，这题中数组长度没有增大，所以是可以的。

而且这里涉及了go语言的一个奇特的地方：

```go
nums := []int{0,1,2,3}
a := nums[4]    // panic: index out of range
nums = append([]int{1,2,3}, nums[4:]...)  // 编译通过
fmt.Println(nums)   // [1 2 3]
```

# 博客

不要脸地贴上个人博客，都是些学习笔记，努力提升ing

<https://eiger.me/post/algo/lt26/>