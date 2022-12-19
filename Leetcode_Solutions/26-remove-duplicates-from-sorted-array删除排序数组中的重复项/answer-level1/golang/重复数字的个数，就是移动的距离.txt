### 解题思路

![WX20191224-181848@2x.png](https://pic.leetcode-cn.com/eaaed34918246f5e99e9e98d84465a133bb948277a1febd88e12435a34d19f7e-WX20191224-181848@2x.png)

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = len(nums)
        if length <= 1:
            return length

        step = 0
        for index in range(1, length):
            pre = nums[index-1]
            if nums[index] != pre:
                nums[index-step] = nums[index]
            else:
                step += 1
        return length-step
```
```golang
func removeDuplicates(nums []int) int {
	length := len(nums)
	if length <= 1{
		return length
	}else{
		removeStep := 0
		for i := 1; i < length; i++ {
			prev := nums[i-1]
			if nums[i] != prev{
				nums[i-removeStep] = nums[i]
			}else{
				removeStep ++
			}
		}
		return length - removeStep
	}
}
```