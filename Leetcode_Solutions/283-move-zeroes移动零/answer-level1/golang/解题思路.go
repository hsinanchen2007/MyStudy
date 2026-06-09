### 解题思路
* 首先创建个变量index来记录最后一位非零元素的索引
* 遍历数组nums，将非零元素添加到数组索引index位置上，index 加 1 
* 遍历完之后数组nums[index]前的都是非零元素，那么让index之后到数组长度的元素全置为0即可

### 代码

```golang
func moveZeroes(nums []int)  {
    index := 0
    for _, value := range nums {
        if (value != 0) {
            nums[index] = value
            index++
        }
    }

    for i:=index; i < len(nums); i++ {
        nums[i] = 0
    }
}
```