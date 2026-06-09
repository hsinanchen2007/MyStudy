### 解题思路

创建切片
### 代码

```golang
func twoSum(nums []int, target int) []int {
    
	var results []int
    //从数组头开始遍历
    for i:=0;i<len(nums)-1;i++{
    //与每个元素比较
        for j:=i+1;j<len(nums);j++{
            if nums[i]+nums[j]==target{
                results=append(results,i,j)
                return results
            }
        }
    }
    return results
	
}
```