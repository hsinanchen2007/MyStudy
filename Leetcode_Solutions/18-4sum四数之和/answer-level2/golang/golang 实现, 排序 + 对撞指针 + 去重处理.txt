golang 实现, 排序 + 对撞指针 + 去重处理

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 排序 + 对撞指针 + 去重处理
// 时间复杂度：O(n^3)  空间复杂度：O(k)  其中，k为存储最终输出所占的空间

func fourSum(nums []int, target int) [][]int {
	var res [][]int
	
	sort.Ints(nums)
	for i:=0; i<len(nums)-3; i++ {
		if i>0 && nums[i]==nums[i-1] {  // 第一个元素去重处理
			continue
		}

		for j:=i+1; j<len(nums)-2; j++ {
			if j>i+1 && nums[j]==nums[j-1] {  // 第二个元素去重处理
				continue
			}

			m := j+1
			n := len(nums)-1
			for m<n {
				sum := nums[i] + nums[j] + nums[m] + nums[n]

				if sum==target {
					res = append(res, []int{nums[i], nums[j], nums[m], nums[n]})
					for m<n && nums[m+1]==nums[m] {  // 第三个元素去重处理
						m++
					}
					for m<n && nums[n-1]==nums[n] {  // 第四个元素去重处理
						n--
					}
					m++
					n--
				}else if sum<target {
					m++
				}else {
					n--
				}
			}
		}
	}

	return res 
}
```
