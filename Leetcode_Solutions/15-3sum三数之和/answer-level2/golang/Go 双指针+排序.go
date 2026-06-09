### 代码

```golang
func threeSum(nums []int) [][]int {
	var n = len(nums)
	if n < 3 {
		return nil
	}
	var l,r int
	var sum [][]int
    // 排序
	sort.Ints(nums)
    // 迭代
	for i := range nums{
        // i > 0 就执行完毕
        if nums[i]>0{
			return sum
		}
        // 前一个值和我一样，该次循环作废
        if i>0 && nums[i] == nums[i-1]{
            continue
        }
        // 设置左右指针
		l = i+1
		r = n-1
		for l < r {
            // 满足条件
			if nums[l]+nums[r]+nums[i] == 0{
                // 加入结果
				sum = append(sum,[]int{nums[l],nums[r],nums[i]})
                //下面再找找有没有里面有 num[i] 但是左右不一样也能求和为 0 的
                // 如果后一个跟l一样，指针再往后挪
				for l<r && nums[l] == nums[l+1]{
					l++
				}
                // 如果前一个和r一样，往前挪
				for l<r && nums[r-1] == nums[r]{
					r--
				}
				l++
				r--
			}else if nums[l]+nums[r]+nums[i] > 0{// 不满足条件，挪动右指针
				r--

			}else if  nums[l]+nums[r]+nums[i] < 0{// 不满足条件，挪动左指针
				l++
			}
		}
	}
	return sum
}
```