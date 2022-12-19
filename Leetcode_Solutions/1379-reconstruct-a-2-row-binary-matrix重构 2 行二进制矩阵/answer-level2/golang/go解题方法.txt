### 解题思路
我的思路是如果是colsum是1的情况，优先将upper减一，也就是优先将第一行的值设为1，并且用center数组记录该值为多少列，如果遇到colsum为2的情况而且upper=0，则从center的最后一个值取出记录的列数，并交换第一行和第二行该列的值，此时lower需要减2

### 代码

```golang
func reconstructMatrix(upper int, lower int, colsum []int) [][]int {
var total int
	for j := 0; j < len(colsum); j++ {
		total += colsum[j]
	}
	if upper + lower != total {
		return [][]int{}
	}
	var nums [][]int
	var nums0 = make([]int,0)
	var nums1 = make([]int,0)
	var center []int
	a := 1
	b := 0
	for i:=0; i<len(colsum); i++ {
		a = 1
		b = 0
		if colsum[i] - a > 0{
			a = 1
			b = 1
			if upper <= 0{
				cNum := center[len(center) - 1]
                center = center[:len(center) -1]
				nums0[cNum] = 0
				nums1[cNum] = 1
				lower = lower -2
			}else if lower <= 0{
				return [][]int{}
			}else {
				upper --
				lower --
			}
			// fmt.Println("-----11111--->",upper,lower, colsum[i])
		}else if colsum[i] - a == 0 {
			if upper - 1 >= 0 {
				a = 1
				b= 0
				upper --
				center = append(center, i)
				// fmt.Println("-------22222--->",upper,lower, colsum[i])
			}else if lower - 1 >= 0 {
				a = 0
				b = 1
				lower--
				// fmt.Println("----33333---->",upper,lower, colsum[i])
			}

		}else {
			a = 0
			b = 0
		}
		nums0 = append(nums0, a)
		nums1 = append(nums1, b)

	}

	if len(nums0) == len(colsum) && len(nums1) == len(colsum) {
		nums = append(nums, nums0)
		nums = append(nums, nums1)

	}
	return nums
}
```