
```golang
func threeSumClosest(nums []int, target int) int {
    //排序
    sort.Ints(nums)
    ln := len(nums)
    res := nums[0]+nums[1]+nums[2]
    for i:=0;i< ln;i++{
        l := i+1
        r := ln-1
        for l < r {
            sum := nums[i]+nums[l]+nums[r]
            //设置最有解
            if abs(res-target) > abs(sum-target){
                res = sum
            }
            //移动双指针
            if target > sum {
                l++
            }else if sum == target{
                return sum
            }else {
                r--
            }
        }
    }
    return res
}

func abs(a int)int{
    if a>0{
        return a
    }
    return -a
}

```