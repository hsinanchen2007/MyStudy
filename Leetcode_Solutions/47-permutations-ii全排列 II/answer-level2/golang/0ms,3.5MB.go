![image.png](https://pic.leetcode-cn.com/a92555ee1437436491f08469820ed0936d9c46d595e990cf1fd48ab8a06eb432-image.png)

### 解题思路
剪枝，就是在交换当前位置跟其他位置的值的时候，先判断是不是已经用过了，没用过就交换。
这里本想使用排序，然后判断后一位是否重复，但是发现排序的话会导致每次遍历后边的位置会发生变化。
因此只能在遍历是用map保存是否用过。
### 代码

```golang
func permuteUnique(nums []int) [][]int {
	var total [][]int
	quan(nums, 0, &total)
	return total
}

func quan(nums []int, idx int, total *[][]int) {
	if idx >= len(nums)-1 {
		n := make([]int, len(nums))
		copy(n, nums)
		(*total) = append((*total), n)
		return
	}
	m := make(map[int]int)
	for i := idx; i < len(nums); i++ {
		if _, ok := m[nums[i]]; !ok {
            m[nums[i]]++
            nums[idx], nums[i] = nums[i], nums[idx]
            quan(nums, idx+1, total)
            nums[idx], nums[i] = nums[i], nums[idx]
        }


	}
}
```