### 解题思路


### 代码

```golang
// 分制
func sortArray(nums []int) []int {
    var lens = len(nums)
    // 拆出来可能是单个的处理下
    if lens <= 1{
        return nums
    }
    // 比较+交换
    if lens == 2{
        if nums[0] > nums[1]{
            nums[1],nums[0] = nums[0],nums[1]
        }
        return nums
    }
    return Merge(sortArray(nums[:lens/2]),sortArray(nums[lens/2:]))
}
// 合并
func Merge(Pre,Post []int) []int{
    var lenPre,lenPost = len(Pre),len(Post)
    var list []int
    var i,j int 
    // 比较+合并
    for i<lenPre && j<lenPost{
        if Pre[i]<=Post[j]{
            list = append(list,Pre[i])
            i++
        }else{
            list = append(list,Post[j])
            j++
        }
    }
    // 多出来数的直接接到后面
    if i<lenPre{
        list = append(list,Pre[i:]...)
    }
    if j<lenPost{
        list = append(list,Post[j:]...)
    }
    return list
}
```