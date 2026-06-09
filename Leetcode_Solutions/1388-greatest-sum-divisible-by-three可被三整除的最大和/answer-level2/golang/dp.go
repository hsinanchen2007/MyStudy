dp，记录下每次加一个数的时候模3分别等于0，1，2的最大值，加第i个数的时候，分别和三个最大值比较，取大值存储，最后m3里面的第一个数就是余数为0的最大值
```
func maxSumDivThree(nums []int) int {
	m3 := make([]int, 3)
	for idx,_:=range m3 {
		m3[idx] = 0
	}
	t := make([]int, 3)
	for _, num := range nums {
		for _, m := range m3 {
			total := m+num
			mod := total%3
			if mod == 0 {
				t[0] = int(math.Max(float64(t[0]),float64(m+num)))
			}else if mod == 1 {
				t[1] = int(math.Max(float64(t[1]),float64(m+num)))
			}else {
				t[2] = int(math.Max(float64(t[2]),float64(m+num)))
			}
		}
		m3 = append([]int{}, t...)
	}
	return m3[0]
}
```
