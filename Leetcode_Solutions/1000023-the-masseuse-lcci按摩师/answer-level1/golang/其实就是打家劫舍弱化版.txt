```go
 massage(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    }

    max := func(i,j int) int {
        if i >= j {
            return i 
        }
        return j
    }

    indexZeroStart := func () int {
        a := nums[0]
        b := nums[0]
        for i := 2 /*can't start from nums[1]*/;i < len(nums);i++ {
            c := max(b,a + nums[i])
            a = b
            b = c
        }
        return b
    }

    indexOneStart := func () int {
        a := 0
        b := 0
        for i := 1;i < len(nums);i++ {
            c := max(b,a + nums[i])
            a = b
            b = c
        }
        return b
    }

    return max(indexZeroStart(),indexOneStart())
}

```
