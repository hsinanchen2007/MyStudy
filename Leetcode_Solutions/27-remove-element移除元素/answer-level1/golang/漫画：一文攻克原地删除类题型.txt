本题额外强调（完整代码见文末）：
- 把握 “原地删除” 的关键

![image.png](https://pic.leetcode-cn.com/ed201c47d6852527e8b76ca6d0a3584e2ef8f0f3da2e5377a20a93309564b41f-image.png)

```go []
func removeElement(nums []int, val int) int {
    for i := 0; i < len(nums);{
        if nums[i] == val {
            nums = append(nums[:i],nums[i+1:]...)
        }else{
            i++
        }
    }
    return len(nums)
}
```
