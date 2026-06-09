
假设原始的值是从0开始，格雷码产生的规律是：
第一步，改变最右边的位元值；
第二步，改变右起第一个为1的位元的左边位元；
第三步，第四步重复第一步和第二步，直到所有的格雷码产生完毕（换句话说，已经走了(2^n) - 1 步）。
用一个例子来说明：
　　假设产生3位元的格雷码，原始值位 000
　　第一步：改变最右边的位元值： 001
　　第二步：改变右起第一个为1的位元的左边位元： 011
　　第三步：改变最右边的位元值： 010
　　第四步：改变右起第一个为1的位元的左边位元： 110
　　第五步：改变最右边的位元值： 111
　　第六步：改变右起第一个为1的位元的左边位元： 101
　　第七步：改变最右边的位元值： 100
```
func grayCode(n int) []int {
	if n == 0 {
		return []int{0}
	}
	l := int(math.Pow(2, float64(n))) // 共l个格雷码序列
	res := make([]int, l)

	first := make([]int, n, n)
	for i := 1; i < l; i++ {
		if i % 2 == 1 {
			first[n-1] = 1 - first[n-1]
		} else {
			for j := n-1; j > 0; j-- {
				if first[j] == 1{
					first[j-1] = 1 - first[j-1]
					break
				}
			}
		}
		res[i] = conv(first)
	}
	return res

}

func conv(data []int) int {
	res := 0
	for i := 0; i < len(data); i++ {
		res += data[i]* int(math.Pow(2, float64(len(data)-i-1)))
	}
	return res
}
```