### 解题思路
参考快排，设置两个index， 从头遍历交换0值和非0值的index。

### 代码

```golang
func moveZeroes(nums []int)  {
    i1,i2 := 0,0
    length := len(nums)
    if length <= 0{
        return
    }
    for i1<length {
        for i1 <length && nums[i1] != 0  {
            i1++
        }
        if i1 >= length{
            return
        }
        i2 = i1+1
        for i2 <length && nums[i2] == 0{
            i2++
        }
        if i2 >= length{
            return
        }
        nums[i1],nums[i2] = nums[i2],nums[i1]
        i1++
    }
}
```