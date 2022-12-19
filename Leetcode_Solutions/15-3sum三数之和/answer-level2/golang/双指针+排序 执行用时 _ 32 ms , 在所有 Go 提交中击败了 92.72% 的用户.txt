### 解题思路
跟2sum的解法不同（2sum是利用了一个map）本体使用map面临了去重的问题，而且go处理起来也是很复杂的，所以果断使用了排序+双指针的解体方法。

> [了解更多后端知识体系](https://github.com/googege/GOFamily#20.md)
### 代码

```golang
func threeSum(nums []int) [][]int {
    if nums == nil {
        return [][]int{}
    }
    sort.Ints(nums) // 排序
    result := [][]int{}
    for k,v := range nums {
        if k == len(nums)-2 { // 为了给 r l 腾地方所以要剩余两个元素
            break
        }
        if k >0 && nums[k] == nums[k-1] {// 当遇到遍历的时候第一个数据数据重复了，那么就直接跳过
           continue 
        }
        
        l,r := k+1,len(nums)-1 // 在剩余的子数组中，使用两个指针来分别代表最左端和最右端
        for l< r {
            value := nums[l]+nums[r]+v // 判断是否为零
            if value >0 { // 不等于冷比零大意味着右边太大了。所以要把指针往左边移动
                r--
            }else if value <0  { // 同理
                l++
            }else { // 当等于0了，先把数据append
                value := []int{nums[l],nums[r],v}
                result =append(result,value)
                for l < r &&nums[l] == nums[l+1]{ // 这里是观察后面的 l和r 往前和往后是否还是有重复的数据如果有的话直接就跳过即可
                    l++
                    }
                for l < r && nums[r] == nums[r-1]{ // 更上面的那个理由一样
                    r--
                    }
                l++ // 这里跳动主要是为了数据的前移。
                r--
            }   
        }
    }
    return result
}
```