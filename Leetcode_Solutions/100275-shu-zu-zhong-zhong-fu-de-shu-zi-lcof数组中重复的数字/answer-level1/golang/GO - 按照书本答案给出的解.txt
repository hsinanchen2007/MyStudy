### 解题思路
使用的就是书本上的思路, 一边排序一边比较元素的值
假定元素没有重复的, 由于限定了元素的值为[0, n-1], 因此元素的值最终回被排成[0, n-1]的切片.
书中给了一段描述, 任何两个数, 最多两次交换就能到正确的位置, 这个要好好的思考, 而且只要排好位置的元素就不会再被弄乱了, 除非有重复的元素, 那么此时就可以返回元素的解了.

### 代码

```golang
func findRepeatNumber(nums []int) int {
    if nums == nil || len(nums) == 0 {
        panic("数组为空")
    }

    for i:=0; i<len(nums); i+=1 {
        if nums[i] < 0 || nums[i] > len(nums) - 1 {
            panic("数组的值不符合题目的要求")
        }
    }

    for i := 0; i<len(nums); i += 1 {
        // 只要i != nums[i]就一直循环
        for i != nums[i] {
            if nums[nums[i]] == nums[i] {
                // 返回结果
                return nums[i]
            }
            nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
        }
    }
    // 没有结果
    return -1
}

```