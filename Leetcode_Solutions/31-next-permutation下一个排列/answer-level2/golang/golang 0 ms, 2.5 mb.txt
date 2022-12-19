```
import "sort"

func nextPermutation(nums []int)  {
    i, j, find := findSwapPoints(nums)
    if find {
        nums[i], nums[j] = nums[j], nums[i]
        sort.Ints(nums[i+1:])
    } else {
        sort.Ints(nums)
    }
}

func findSwapPoints(nums []int) (onePos int, twoPos int, find bool) {
    for i := len(nums)-1; i > 0; i-- {
        if nums[i] > nums[i-1] {
            onePos, find = i - 1, true
            break
        }
    }
    if find {
        for j := onePos + 1;  j <= len(nums)-1; {
            if nums[j] > nums[onePos] {
                if j == len(nums)-1 {
                    twoPos = j
                    break
                }
                j += 1
            } else {
                twoPos = j - 1
                break
            }
        }
        return onePos, twoPos, true
    } else {
        return onePos, twoPos, false
    }
}
```