### 解题思路
此处撰写解题思路
**执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了100.00%的用户**
### 代码

```golang
func removeElement(nums []int, val int) int {

    slow := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] != val {
            nums[slow] = nums[i]
            slow++
        }
    }
    return slow
}
```