思路：

根据字典序的定义，从后往前找
1. 如果数组中存在nums[i-1]<nums[i]的两个数，就将nums[i-1]与nums[i-1]之后的数中比nums[i-1]大的最小的数进行交换，然后对nums[i-1]之后的数进行排序就完成了
2. 如果找不到nums[i-1]<nums[i]，则表明数组为降序序列，是字典序的最后一个元素了，根据题目要求翻转即可
```
func nextPermutation(nums []int)  {
    n := len(nums)
    var i = n-1
    for ;i > 0; i-- {
        if nums[i] > nums[i-1] {
            j := i
            for j < n && nums[j] > nums[i-1] {
                j++ 
            }
            nums[i-1], nums[j-1] = nums[j-1], nums[i-1]
            break
        }
    }
    sort.Ints(nums[i:])
}
```
