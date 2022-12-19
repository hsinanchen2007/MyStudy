golang解决，排序+双指针之对撞指针

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 排序+双指针之对撞指针
// 先排序，然后固定一个元素,另外两个元素由对撞指针确定，注意对三个元素的去重处理
// 时间复杂度：O(n^2)  空间复杂度：O(1)

func threeSum(nums []int) [][]int {
	res := [][]int{}

	sort.Ints(nums)
	for i:=0; i<len(nums); i++ {
		// 优化点：排序后，第一个数最小，若三数之和为0,则第一个数不能为0,否则和必大于0
		if nums[i]>0 {
			return res
		}

		// 第一个元素去重处理
		if i>0 && nums[i]==nums[i-1]{
			continue
		}

		temp := -nums[i]
		j := i+1
		k := len(nums)-1
		for j<k {		 
			if nums[j]+nums[k]==temp {
				res = append(res, []int{nums[i], nums[j], nums[k]})

				// 第二个元素去重处理
				for j<k && nums[j+1]==nums[j] {
					j++
				}
				// 第三个元素去重处理
				for k>j && nums[k-1]==nums[k] {
					k--
				}

				j++
				k--			
			}else if nums[j]+nums[k]>temp {
				k--
			}else {
				j++
			}
		}
	}

	return res
}
```
