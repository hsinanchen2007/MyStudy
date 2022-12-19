为什么用fliter直接过滤显示的结果不样
```
var removeElement = function(nums, val){
    let nums = nums.filter(num => {
        return num!==val
    })
    return nums.length
}
```
输入[3,2,2,3]跑出来结果是[3,2]。。。。。。。
我**，心态崩了
