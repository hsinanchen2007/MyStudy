### 解题思路
1. 遍历 一遍数组
2. 计数器遇到相同的就加1,遇到不同的减1,当计数器为0时更新结果
3. 反证法
    * 当计数器发生更新时 counter == 0 时 被暂时选定的众数一定不是扫描过的子数组的众数
    * 因此如果 counter != 0 时 被暂定为众数的数 一定是扫描过的子数组的众数
    * 所以当遍历结束时 我们就可以说最后的结果一定是全局数组的众数

### 代码

```golang
func majorityElement(nums []int) int {
    counter,res := 0, nums[0]
    for i := 0; i < len(nums); i++{
        if nums[i] == res{
            counter ++
        }else{
            counter --
        }
        if  counter == 0{
            res = nums[i+1]
        }
    }
    return res
}
```