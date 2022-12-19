Note that we can consider the array as a non-decreaseing function and the number to be moved is 
the removable discontinuity.
Everytime we idenitify the removable discontinuity,we can add the counter by one.
As long as we spot the other kind of discontinuity,we return false.
Also note that it is not very convient to idenitify the discontinuity at the edge case,so we just extract them out.

Here is a soltuion for Golang:


func checkPossibility(nums []int) bool {
    changeNum := 0
	for i := 1;i<=len(nums)-3;i++ {
		if nums[i] > nums[i+1]{
			//removable discontinuity
			if nums[i-1] <= nums[i+1] {
				changeNum++
			}else if nums[i] <= nums[i+2] {
				changeNum++
			}else {
				//jump discontinuity
				return false
			}
		}
	}
		//edge conditions
    if len(nums) >= 2 && nums[0] > nums[1] {
		changeNum++
	}
    if len(nums) >= 3 && nums[len(nums)-2] > nums[len(nums)-1] {
		changeNum++
	}
	return changeNum == 0 || changeNum == 1
}