### 解题思路
此处撰写解题思路

### 代码

```golang
func fourSum(nums []int, target int) [][]int {
    if len(nums) < 4 {
        return [][]int{}
    }

    result := make([][]int, 0)
    sort.Ints(nums)

    for i:=0; i < len(nums); i++ {
        if i!= 0 {
            for nums[i] == nums[i-1] {
                i++
                if i == len(nums) {    // {... 1,1,1,1}
                    break
                }
            }
        }

        if i == len(nums) {
            break
        }
        for j := i+1; j < len(nums); j++ { 
            if j != i+1 {
                for nums[j] == nums[j-1] {
                    j++
                    if j == len(nums) {     // {... 1,1,1,1}
                        break
                    }
                }
            }

            if j == len(nums) {
                break
            }

            left, right := j+1, len(nums)-1

            for left < right {
                sum := nums[i] + nums[j] + nums[left] + nums[right]

                if sum == target {
                    result = append(result, []int{nums[i], nums[j], nums[left], nums[right]}) 

                    for left < right && nums[left] == nums[left+1] {
                        left++
                    }
                    for left < right && nums[right] == nums[right-1] {
                        right--
                    }
                    left++ 
                    right--
                }else if sum > target {
                    right--
                }else {
                    left++
                }

            }

        }
    }

    return result
}
```