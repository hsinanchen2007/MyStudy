func twoSum(nums []int, target int) []int {
        indices := []int{}
        for i := 0; i < len(nums); i++ {
                for j := i + 1; j < len(nums); j++ {
                        if nums[i]+nums[j] == target {
                                indices = []int{i, j}
                                return indices
                        }
                }
        }
        return indices
}
