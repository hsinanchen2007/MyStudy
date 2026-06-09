````
mport (
	"sort"
)

func threeSum(nums []int) [][]int {
	var result [][]int

	if lens := len(nums); lens < 3 {
		return result
	} else {
		sort.Ints(nums)

		for i := 0; i < lens; i++ {
			if nums[i] > 0 {
				break
			}
			if i > 0 && nums[i] == nums[i - 1] {
				continue
			}
			left, right := i + 1, lens - 1
			for left < right {
				if total := nums[i] + nums[left] + nums[right]; total == 0 {
					result = append(result, []int{nums[i], nums[left], nums[right]})
					for ; left < right && nums[left] == nums[left + 1]; left++ {}
					for ; left < right && nums[right] == nums[right - 1]; right-- {}
					left++
					right--
				} else if total > 0 {
					right--
				} else {
					left++
				}
			}
		}
		return result
	}
}
````