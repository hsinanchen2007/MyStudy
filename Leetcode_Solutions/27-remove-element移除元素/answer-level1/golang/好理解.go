### 解题思路

从数值的前后两端同时向中间遍历，前端比较与Val的大小，相等时与尾端互换位置，同时尾端向前进一前端往后退一，交换的次数就是Val的个数。注意边界条件可取等号。

### 代码

```golang
func removeElement(nums []int, val int) int {
    j:=len(nums)-1
    count := 0
    for i:=0;i <= j;i++{
        if nums[i] == val{
            nums[i],nums[j]=nums[j],nums[i]
            i--
            j--
            count++
        }   
    }
    return len(nums) - count
}
```