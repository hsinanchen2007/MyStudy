### 解题思路

上面有人提到的算法的一个go版本

### 代码

```golang
func threeSum(nums []int) [][]int {
	answer := [][]int{}
	if len(nums) < 3{
		return answer
	}
	sort.Ints(nums)
	for index, elem := range nums{
		if elem > 0 {
			return answer
		}

		if index > 0{
			if elem == nums[index - 1]{
				continue
			}
		}

		L := index + 1
		R := len(nums) - 1
		for L < R {
			if elem + nums[L] + nums[R] == 0{
				answer = append(answer, append([]int{}, elem, nums[L], nums[R]))
				for  L < R && nums[L] == nums[L+1]{
					L += 1
				}
				for L < R && nums[R] == nums[R-1]{
					R -= 1
				}
				L += 1
				R -= 1
			} else if elem + nums[L] + nums[R] > 0{
				R -= 1
			} else if elem + nums[L] + nums[R] < 0{
				L += 1
			}
		}
	}
	return answer
}
```