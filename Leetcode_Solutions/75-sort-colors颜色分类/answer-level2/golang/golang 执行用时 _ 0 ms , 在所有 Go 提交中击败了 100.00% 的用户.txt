### 解题思路
- 遍历一遍记录三种颜色的个数
- 然后依次填充对应数量的颜色到原始数组

### 代码

```golang
func sortColors(nums []int)  {
    var cnts [3]int
    for _, v := range nums {
        cnts[v]++
    }
    j := 0
    for i, cnt := range cnts {
        for ; j < len(nums); j++ {
            nums[j] = i
            if cnt == 0 {
                break
            }
            cnt--
        }
    }
}
```