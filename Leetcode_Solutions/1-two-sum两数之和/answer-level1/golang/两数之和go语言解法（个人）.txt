go解法（个人）
1、暴力解法
func twoSum(nums []int, target int) []int {
	var re []int
	for i:=0;i<len(nums)-1;i++{
		for j:=i + 1;j<len(nums);j++{
			if nums[i] + nums[j] == target {
				re = append(re,[]int{i,j}...)
				break
			}
		}
	}
	return re
}
2、空间换时间，最快8ms，空间用了3.8m
func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
	for i:=0;i<len(nums);i++{
	    j := target - nums[i]
        m[j] = i
	}
	var re []int
	for k:=0;k<len(nums);k++{
	    a := nums[k]
	    if b,ok := m[a];ok && b != k{
	        if k > a {
	            re = append(re,[]int{b,k}...)
	        }else{
	            re = append(re,[]int{k,b}...)
	        }
	        break
	    }
	}
	return re
}