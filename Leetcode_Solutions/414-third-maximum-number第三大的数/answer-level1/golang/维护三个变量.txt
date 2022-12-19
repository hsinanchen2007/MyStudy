### 解题思路
一开始n1 为第一个元素，n2,n3为math.MinInt32-1
遍历数组，然后进行比较，调整n1,n2,n3

### 代码

```golang
func thirdMax(nums []int) int {
    n1,n2,n3 := nums[0],math.MinInt32-1,math.MinInt32-1
    for i:=1;i<len(nums);i++ {
        if nums[i] == n1 || nums[i] == n2 || nums[i] == n3{
            continue
        }
        if nums[i] > n1 {
            n3 = n2
            n2 = n1
            n1 = nums[i]
        }else if nums[i] > n2 {
            n3 = n2
            n2 = nums[i]
        }else if nums[i] > n3 {
            n3 = nums[i]
        }
    }
    if n3 == math.MinInt32-1 {
        return n1
    }
    return n3
}
```