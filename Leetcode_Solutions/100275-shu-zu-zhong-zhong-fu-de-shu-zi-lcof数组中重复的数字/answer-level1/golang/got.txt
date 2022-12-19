### 解题思路
时间o(n),空间o(1)
注意交换元素时别换错了

### 代码

```golang
func findRepeatNumber(nums []int) int {
    index:=0
    for{
        if nums[index]==index{
            index++
            continue
        }else if nums[nums[index]]==nums[index]{
            return nums[index]
        }else{
            swap(nums,index,nums[index])
        }
    }
}
func swap(nums []int,a,b int){
    temp:=nums[a]
    nums[a]=nums[b]
    nums[b]=temp
}
```