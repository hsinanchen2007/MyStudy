### 解题思路
此处撰写解题思路

### 代码

```golang
func twoSum(nums []int, target int) []int {
  
    for i:=0;i<len(nums);i++{
        for j:=i+1;j<len(nums);j++{
            if nums[i]+nums[j] == target{
                return []int{i,j}
            }
        }
    }
    return []int{}
}
```