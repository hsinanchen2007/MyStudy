### 解题思路
1、对每一行求和，得出有几个1，然后使用二维切片保存求和的值和对应索引
2、使用排序对上述得到的切片进行排序
3、获取切片前k个切片中的第二个值
### 代码

```golang
func kWeakestRows(mat [][]int, k int) []int {
    sliceSum := func (s []int) int {
		var sum int
		for _, v := range s {
			sum += v
		}
		return sum
	}
	var s [][]int
	for i, v :=  range mat {
		tmp := []int{sliceSum(v), i}
		s = append(s, tmp)
	}
	sort.Slice(s, func(i, j int) bool {
		return s[i][0] < s[j][0] || (s[i][0] == s[j][0] && s[i][1] < s[j][1])
	})
	res := make([]int, k)
	for i := 0; i < k; i++ {
		res[i] = s[i][1]
	}
    return res
}
```