一开始的解法，之后看了官方题解，发现官方的要更简明
```
/*
1. 借助字典
用两个字典，分别记录两个数组里元素出现的个数；键为元素，值为其出现的个数
然后合并结果
假设数组的长度分别为m，n，则时间与空间复杂度均为O(m+n)
*/
func intersect1(nums1 []int, nums2 []int) []int {
	if len(nums1) == 0 || len(nums2) == 0 {
		return nil
	}
	m1 := make(map[int]int, len(nums1))
	for _, v := range nums1 {
		m1[v] ++
	}
	m2 := make(map[int]int, len(nums2))
	for _, v := range nums2 {
		m2[v] ++
	}
	var result []int
	for k1, v1 := range m1 {
		if m2[k1] == 0 {
			continue
		}
		for i := 0; i < min(v1, m2[k1]); i++ {
			result = append(result, k1)
		}
	}
	return result
}

/*
2.在1的基础上优化空间复杂度
将两个数组排序；遍历其中一个，不断在另一个数组里边用两次二分法查找元素出现的次数，同时统计在当前数组里出现的次数，以得到结果
另一个优化是可以利用当前数组作为结果数组

综合看，空间复杂度为常数级O(1)
时间复杂度O(nlogn + mlogm)，主要为排序和最后的筛选结果
*/
func intersect(nums1 []int, nums2 []int) []int {
	m, n := len(nums1), len(nums2)
	if m == 0 || n == 0 {
		return nil
	}
	if m > n {
		nums1, nums2 = nums2, nums1
		m, n = n, m
	}
	sort.Ints(nums1)
	sort.Ints(nums2)
	time1 := 1 // 统计nums1里某个元素的个数，下边遍历使用
	k := 0
	// 借用nums1的空间作为返回数组
	for i := 0; i < m-1; i++ {
		v := nums1[i]
		if v == nums1[i+1] {
			time1++
			continue
		}
		time2 := count(nums2, v)  // nums2中v出现的个数
		time := min(time1, time2) // v在结果里的个数， 包含time2为0的情况
		k = write(nums1, k, v, time)
		time1 = 1
	}
	// 处理最后一个元素
	last := nums1[m-1]
	time2 := count(nums2, last)
	if time2 == 0 {
		return nums1[:k]
	}
	if m == 1 || last != nums1[m-2] {
		nums1[k] = last
		k ++
	} else {
		time1 ++
		time := min(time1, time2)
		k = write(nums1, k, last, time)
	}
	return nums1[:k]
}

// arr 已经排序
func count(arr []int, x int) int {
	left := sort.SearchInts(arr, x)
	if left == len(arr) || arr[left] != x {
		return 0
	}
	return searchFromRight(arr, x) - left
}

// arr 已经排序
func searchFromRight(nums []int, target int) int {
	left, right := 0, len(nums)
	for left < right {
		mid := left + (right-left)/2
		switch {
		case nums[mid] <= target:
			left = mid + 1
		case nums[mid] > target:
			right = mid
		}
	}
	return left
}

//从索引k开始向结果数组里写入time个v, 返回写完后的索引
func write(r []int, k, v, time int) int {
	for j:=0; j<time; j++ {
		r[k] = v
		k ++
	}
	return k
}

func min(a, b int) int {
	return int(math.Min(float64(a), float64(b)))
}
```