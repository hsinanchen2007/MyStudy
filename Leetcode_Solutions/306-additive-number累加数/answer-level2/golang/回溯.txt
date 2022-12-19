### 解题思路
此处撰写解题思路

### 代码

```golang
func isAdditiveNumber(num string) bool {
    nums := make([]int, len(num))

    for i := 0; i < len(num); i++ {
		nums[i] = int(num[i])-48
	}
    count := 0
    backtrack(nums, nil, &count)

    if count == 0 {
        return false
    }
    return true
}

func backtrack(nums, track []int, count *int) {
    if !judge(track) {
        return 
    }
    if len(nums) == 0 && len(track) >= 3{ 
        *count++
        return 
    }

    for i :=0; i < len(nums); i++ {
        if i!=0 && nums[0] == 0 {
            return
        }

        numscopy := append([]int{}, nums...) 
        trackcopy := append([]int{}, track...)
         
        backtrack(numscopy[i+1:], append(trackcopy, transfer(numscopy[:i+1])) ,count )
    }
}

func judge(track []int) bool {
    
    if len(track) <= 2 {
        return true
    }

    length := len(track)

    if track[length-1] != track[length-2] + track[length-3] {
        return false
    }
    return true
}

func transfer(data []int) int {
    count :=0

    for i:=0; i < len(data); i++ {
        count = count * 10 + data[i]
    }
    return count
}
```