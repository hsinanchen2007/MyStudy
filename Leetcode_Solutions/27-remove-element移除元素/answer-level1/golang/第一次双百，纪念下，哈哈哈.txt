### 解题思路
我只是很开心而已，第一次碰到双百。。。。。
虽然是有些简单。。。
+ 执行用时 : 0 ms, 在所有 golang 提交中击败了100.00%的用户
+ 内存消耗 : 2.1 MB, 在所有 golang 提交中击败了100.00%的用户

### 代码

```golang
func removeElement(nums []int, val int) int {
    
    index := 0
    for i, v := range nums {
        if v != val {
            if i == index {
                index++
                continue
            }
            nums[index] = v
            index++
        }
    }

    return index
}
```