
```golang
func fourSum(nums []int, target int) [][]int {
    //排序
    sort.Ints(nums)
    n := len(nums)
    ans := [][]int{}
    if n <4{
        return ans
    }

    for i:=0;i<n-3;i++{
        //去重
        if i>0 && nums[i] == nums[i-1]{
            continue
        }
        //升序排除
        //最小四数字和
        if nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target {
            break
        }
        //升序排除
        //最大四数字和
        if nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target {
            continue
        }
        for j:=i+1;j<n-2;j++{
            //去重
            //import::: j-i >1
            if j-i>1 && nums[j] == nums[j-1]{
                continue
            }
            //最小四数字和
            if nums[i]+nums[j]+nums[j+1]+nums[j+2] > target {
                break
            }
            //最大四数字和
            if nums[i]+nums[j]+nums[n-2]+nums[n-1] < target {
                continue
            }
            //双指针
            left := j+1
            right := n-1
            for left < right{
                //临时结果
                tempRes := nums[i] + nums[j] + nums[left] + nums[right]
                if tempRes == target{
                    //目标结果
                    ans = append(ans,[]int{nums[i] ,nums[j] ,nums[left] , nums[right]})
                    //left 去重
                    for left < right && nums[left] == nums[left+1]{
                        left++
                    }
                    //right 去重
                    for left < right && nums[right] == nums[right-1]{
                        right--
                    }
                    right--
                    left++
                }else if tempRes > target{
                    right--
                }else{
                    left++
                }
            }
        }
    }
    return ans
}
```