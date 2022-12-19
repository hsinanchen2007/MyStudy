### 解题思路
遍历数组

### 代码

```golang
func removeElement(nums []int, val int) int {

    for i:=0;i<len(nums);i++{

        if nums[i]==val{
            nums=append(nums[:i],nums[i+1:]...)
            i--
        }

    }

    return len(nums)

}
```