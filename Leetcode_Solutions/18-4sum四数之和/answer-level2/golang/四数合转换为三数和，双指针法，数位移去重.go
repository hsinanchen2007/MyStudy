/**
四数和
=> 三数和
*/
```
整体思路在于将四数和转换为之前实现过的三数和
```
- 照样先进行数组排序，头部单独数字与尾部三数集合进行计算
- 尾部三数集合按照之前实现过的三数和，目标数值就是总目标数值减去头部单独数值
- 按照上述思路能获取到所有的组合，然后在实现的步骤中，进行去重运算
- 这边采用了一个 map[uint64]map[uint64]bool 来进行去重操作
四个数字，如 [1,2,3,4] ，数组头两个 int 数值作为一个 key，后两个数值作为另一个 key，位操作，将 index 为 0，2 的两个数值各自左位移 32 位后与剩下 1，3 数值合并放入即可，这边需要注意的是，类型转换的时候，先转成 uint32 再转为 uint64 (若一开始直接转成 uint64 会出现负数符号位异常的情况)
```go
func fourSum(nums []int, target int) (result [][]int) {
	if len(nums) < 4 {
		return
	}
	sort.Ints(nums)
	var has map[uint64]map[uint64]bool = make(map[uint64]map[uint64]bool)
	for i := 0; i < len(nums)-3; i++ {
		for _, v := range tailResult(nums[i+1:], target-nums[i]) {
			if has[uint64(uint32(nums[i]))<<32|uint64(uint32(v[0]))] == nil {
				has[uint64(uint32(nums[i]))<<32|uint64(uint32(v[0]))] = make(map[uint64]bool)
			}
            // 去重判断
			if !has[uint64(uint32(nums[i]))<<32|uint64(uint32(v[0]))][uint64(uint32(v[1]))<<32|uint64(uint32(v[2]))] {
				result = append(result, []int{nums[i], v[0], v[1], v[2]})
				has[uint64(uint32(nums[i]))<<32|uint64(uint32(v[0]))][uint64(uint32(v[1]))<<32|uint64(uint32(v[2]))] = true
			}
		}
	}
	return result
}
// 三数和
func tailResult(nums []int, target int) [][]int {
	var result [][]int
	a, b, c := 0, 1, len(nums)-1
	for a < b && b < c {
		for b < c {
			if nums[a]+nums[b]+nums[c] < target {
				goto bpp
			}
			if nums[a]+nums[b]+nums[c] == target {
				result = append(result, []int{nums[a], nums[b], nums[c]})
				c--
				goto bpp
			}
			if nums[a]+nums[b]+nums[c] > target {
				c--
			}
			continue
		bpp:
			for b < len(nums)-1 {
				if nums[b] == nums[b+1] {
					b++
				} else {
					goto bppn
				}
			}
		bppn:
			b++
		}
		for a < len(nums)-1 {
			if nums[a] == nums[a+1] {
				a++
			} else {
				break
			}
		}
		a++
		b = a + 1
		c = len(nums) - 1
	}
	return result
}
```