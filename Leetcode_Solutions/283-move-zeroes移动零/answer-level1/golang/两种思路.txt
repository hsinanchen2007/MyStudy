![image.png](https://pic.leetcode-cn.com/aa0f1d6d0241dd32edbb440058a1d8a910571275a544bd6fd62c61dfa52eeed4-image.png)

方案1: 从后向前遍历数组，遇到0进行交换
方案2: 借鉴题解中的大神的方案，此方案是先遍历数组，将不为0的值填充到数组中，再遍历一次进行补0

```
func moveZeroes(nums []int)  {
    /* 方案1
    var j int = len(nums) - 1
    for i := j; i >= 0; i-- {
        if nums[i] == 0 {
            for k := i; k < j; k++ {
                nums[k], nums[k+1] = nums[k+1], nums[k]
            }
            j--
        }
    } 
    */
    //方案2
    var index int = 0
    for _, v := range nums {
        if v != 0 {
            nums[index] = v
            index++
        }
    }
    for i := index; i < len(nums); i++ {
        nums[i] = 0
    }
}
```
