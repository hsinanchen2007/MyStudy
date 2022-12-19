### 解题思路

用flag来控制每行元素个数，每次向tmp插入一个元素，flag+1，当flag=c时，表示一行的元素数量够了，把tmp添加到结果数组 

### 代码

```golang
func matrixReshape(nums [][]int, r int, c int) [][]int {
	if len(nums) * len(nums[0]) != r * c {
		return nums
	}
	res := [][]int{}
	tmp := []int{}
	flag := 0
	for _,i := range nums {
		for _,j := range i {
			tmp = append(tmp,j)
			flag++
			if flag == c {
				res = append(res,tmp)
				tmp = []int{}
				flag = 0
			}
		}
	}
	return res
}
```