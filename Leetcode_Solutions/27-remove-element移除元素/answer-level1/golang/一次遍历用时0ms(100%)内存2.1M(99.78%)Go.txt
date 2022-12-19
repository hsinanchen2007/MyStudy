### 解题思路
遍历数组, 遇到需要移除的值跳过, 将不需要移除的值移动到最后一位. 
于是只需要一个标记最后一位位置的下标即可.
最后下标停在哪儿, 就是最终的长度.

### 代码

```golang
func removeElement(nums []int, val int) int {
    var index = 0;
    for i:= 0; i< len(nums); i++{
        if nums[i] != val {
            if i != index {
                nums[index] = nums[i]
            }
            index ++;
        }
    }
    return index
}
```