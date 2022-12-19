![image.png](https://pic.leetcode-cn.com/d31ec07f1a169b207b47907890637dcab32c5674f314049e9c83fc841651780f-image.png)

### 解题思路
看作插入排序就行了，在插入排序时遇到val的时候，就把它看作最大的数处理。

### 代码

```golang
func removeElement(nums []int, val int) int {
    if len(nums) == 0{
        return 0
    }

    idx := 0
    if nums[0] == val{
        idx++
    }
    j:=0
    for i:=0;i<len(nums);i++{
        j = i
        for j>0{
            if nums[j] == val{
                idx++
                break
            }
            if nums[j-1]==val || nums[j]<nums[j-1]  {
                nums[j],nums[j-1] = nums[j-1],nums[j]
            }
            j--
        }
    }

    return len(nums)-idx
}
```