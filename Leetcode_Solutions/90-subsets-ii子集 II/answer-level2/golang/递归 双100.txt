```
import "sort"

func subsetsWithDup(nums []int) (rst [][]int) {
	sort.Ints(nums)
	return subsetsWithDupSorted(nums)
}

func subsetsWithDupSorted(nums []int) (rst [][]int) {
	switch len(nums) {
	case 0:
		return [][]int{
			{},
		}
	case 1:
		return [][]int{
			{},
			{nums[0]},
		}
	}
	used := map[int]bool{}
	for i := 0; i < len(nums); i++ {
		if used[nums[i]] {
			continue
		}
		used[nums[i]] = true
		tmp := subsetsWithDupSorted(nums[i+1:])
		for j := 0; j < len(tmp); j++ {
			rst = append(rst, append([]int{nums[i]}, tmp[j]...))
		}
	}
	rst = append(rst, []int{})

	return
}
```
