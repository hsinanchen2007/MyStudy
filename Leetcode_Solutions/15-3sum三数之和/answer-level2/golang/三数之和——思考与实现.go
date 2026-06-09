


```go
package lt15

import "sort"

// 三数之和
// nums中找 a+b+c=0，要找出所有符合条件但 [不重复](也就是相同元素不可复用，但没有要求重复元素取哪一个) 的三元组

// a+b+c=0 <=> a+b=-c
// 相当于变形的两数之和问题

// 外层循环遍历一次，将 -c 作target
// 内层循环中像2sum问题一般一次遍历即可
// 如果只是像2sum一般找一个可行解，这样即可
// 这里不同的是，要找出所有可行且不重复的解，而且解是值列表，而不是下标列表
// 需要用二维数组记录，此外由于不能使用重复解，但重复的元素是可以在同一个解中使用
// 总时间复杂度O(n^2)， 空间O(n^2)

// 1. 错误答案
// 直接根据2sum衍生出来，得到的答案没有去除重复解
func threeSum1(nums []int) [][]int {

	// 1. 特殊情况
	l := len(nums)
	if l < 3 {return [][]int{}}

	// 2. 一般情况下
	var res [][]int
	var target int	// 为便于理解，使用了target。直接使用-c完全可以
	m := make(map[int]bool)		// 哈希集合

	for i:=0; i<l; i++ {
		target = -nums[i]
		for j:=i+1; j<l; j++ {		// 注意仍有可能有重复解
			if m[target-nums[j]] {	// 找到解
				// 注意，这里nums[j]可能等于target-nums[j]，但不是同一个
				res = append(res, []int{nums[i], nums[j], target-nums[j]})
			} else {
				m[nums[j]] = true
			}
		}
	}
	return res
}

// 2. 在 1 的基础上使用额外map去重
// 时空都是O(n^2)
// 313/313 cases passed (716 ms)
//Your runtime beats 72.17 % of golang submissions
//Your memory usage beats 100 % of golang submissions (22.7 MB)
func threeSum(nums []int) [][]int {

	// 1. 特殊情况
	l := len(nums)
	if l < 3 {return [][]int{}}

	// 2. 一般情况下
	var res [][]int
	var target int	// 为便于理解，使用了target。直接使用-c完全可以
	var m map[int]bool		// 哈希集合
	m1 := make(map[[3]int]bool)

	sort.Ints(nums)		// 对nums升序重排
	//fmt.Println(nums)

	for i:=0; i<l-2; i++ {
		target = -nums[i]
		m = make(map[int]bool)
		for j:=i+1; j<l; j++ {		// 注意仍有可能有重复解
			if m[target-nums[j]] {	// 找到解

				//fmt.Println(nums[i], target-nums[j], nums[j])

				// 注意，这里nums[j]可能等于target-nums[j]，但不是同一个

				// 怎么去除相同的解呢？没有想出不借助额外空间的办法
				// 提出使用一个哈希集合存储解的出现情况，需要将解映射为一个比较方便比较的结构
				// 最直接的想法是将解切片先排好序，再拷贝为解数组，再用数组作哈希集合的键
				// 为了保证得到的解是有序的，最好的做法是在一开始就对nums原地排好序。
				resi := [3]int{nums[i], target-nums[j], nums[j]}		// 已经是升序排列的
				if !m1[resi] {		// 只有当解不重复时才留下
					//fmt.Println("a1")
					res = append(res, resi[:])		// 这里有个特别要注意的点是： resi[:]用的是原来的数组空间，所以每一次
													// 获得resi必须重新分配内存(见前面resi := [3]int{})
					m1[resi] = true
				}

			} else {
				m[nums[j]] = true
			}
		}
	}

	//fmt.Println(m1)

	return res
}

// 现在来思考下解法2.在查找abc之前先将nums排好序，但我们只利用了有序数组的一点点性质
// 以 [-4, -1, -1, -1, 0, 1, 2]为例， 利用排好序的特性
// 可以采用三指针法，左右指针（a/b）指向nums两端， 中间指针c在中部滑移
// 同时进一步的，若nums[a]+nums[b]>0，则c只需在负数中寻找。
// （这里有两种： 1. 哈希表预先存好所有值，方便查找，但是这种做法也是要刷新很多次map或者使用多个map;
// 2. 使用数组的顺序查找（进一步使用二分查找））
// 在这里，使用数组的顺序查找(二分查找适合nums数组长度比较大的情况，这里不折腾)
//
// 参考题解区 Krahets 题解，其实是将左指针先固定，再移动右指针和中指针
// 313/313 cases passed (32 ms)
//Your runtime beats 98.37 % of golang submissions
//Your memory usage beats 100 % of golang submissions (6.9 MB)
func threeSum2(nums []int) [][]int {

	// 1. 特殊情况
	l := len(nums)
	if l < 3 {return [][]int{}}

	// 2. 一般情况下
	var res [][]int
	var sum int

	sort.Ints(nums)		// 对nums升序重排

	for a:=0; a<l-2; a++ {
		if nums[a] > 0 {
			return res
		} // a+b+c a>0 => a+b+c > 0
		if a > 0 && nums[a] == nums[a-1] {
			continue
		} // 跳过重复项，不跳过的话遍历只可能得到之前找到过的组合

		b, c := l-1, a+1 // a为左指针，b为右指针，c在左指针后一位到右指针前一位中间移动
		for c < b { // 圈定c的可能活动范围
			sum = nums[a] + nums[b] + nums[c]
			switch {
			case sum < 0: // sum<0，所以c必须右移才可能找到sum=0
				c++
				for c < b && nums[c] == nums[c-1] {
					c++
				} // 跳过重复项
			case sum > 0:
				b--
				for c < b && nums[b] == nums[b+1] {
					b--
				} // 跳过重复项
			default:
				// 找到目标
				res = append(res, []int{nums[a], nums[c], nums[b]})
				c++ // c右移
				b-- // b左移
				for c < b && nums[c] == nums[c-1] {
					c++
				}   // 跳过重复项
				for c < b && nums[b] == nums[b+1] {
					b--
				}   // 跳过重复项
			}
		}
	}
	return res
}

// 比较前面两种解法，第一种是先找出所有可行解，再去重
// 后一种解法则是边找边剔除重复可能
```