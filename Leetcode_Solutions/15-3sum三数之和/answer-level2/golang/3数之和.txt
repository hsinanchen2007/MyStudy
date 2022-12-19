### 解题思路
1. 先将数组排序
2. 我们知道，如果满足3数之和为0，首先排除几个情况：全正数和全负数，以及大小小于3的数组。
3. 剩下的就是正负数均有或者全0。
4. 遍历的时候，我们只遍历所有非正数，即第一个指针i遍历所有非正数。
5. 第二个指针从最后一个最大的正数逆向遍历，遍历到i所指的数的绝对值的一半即可。
6. 指针i和j指过的数不再处理，也就是说，相同的数i和j只指向一次。因为数组排序了，这一点很好做到。
7. 第三个数的索引必须介于i和j之间，这样可以保证找出的不会重复。

### 代码

```golang
func threeSum(nums []int) [][]int {
    var result [][]int
	// 先将 nums 排序
	sort.Ints(nums)
	// 不到3个数或者都是正数或都是负数，返回空
	if len(nums) < 3 || nums[0] > 0 || nums[len(nums)-1] < 0 {
		return result
	}
	for i := 0; i < len(nums); i++ {
		// 如果大于 0，则不可能存在结果
		if nums[i] > 0 {
			return result
		}
		// 如果该数已经找过，则直接跳过
		if i >= 1 && nums[i] == nums[i-1] {
			continue
		}
		j := len(nums) - 1
		for j >= 0 && nums[j] >= (-nums[i])/2 {
			// 如果该数已经找过，则直接跳过
			if j+1 < len(nums) && nums[j] == nums[j+1] {
				j--
				continue
			}
			// v > i && v < j 确保结果不重复
			target := -(nums[i] + nums[j])
			v := sort.SearchInts(nums[i+1:], target) + i + 1
			if  v != len(nums) && nums[v] == target && v > i && v < j {
				tmp := []int{nums[i], target, nums[j]}
				result = append(result, tmp)
			}
			j--
		}
	}
	return result
}
```