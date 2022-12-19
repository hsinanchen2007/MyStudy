# 借助二维数组
```
执行用时 :40 ms, 在所有 Go 提交中击败了100.00%的用户

内存消耗 :7.3 MB, 在所有 Go 提交中击败了100.00%的用户
```
使用二维数组保存多米诺0度或180度逆转相同的数组的数量，然后(n-1)*n/2得到每个相同的多米诺的配对的数
```
func Factorial(n uint64)(result uint64) {
	return n*(n-1)/2
}
func numEquivDominoPairs(dominoes [][]int) int {
	var num [9][9]uint64
	var ret uint64
	for i:=0;i<len(dominoes);i++{
		if dominoes[i][0]<dominoes[i][1]{
			num[dominoes[i][0]-1][dominoes[i][1]-1]++
		}else {
			num[dominoes[i][1]-1][dominoes[i][0]-1]++
		}
	}
	for i:=0;i<len(num) ; i++ {
		for j:=0;j<len(num[i]);j++{
			if num[i][j]>1{
				ret+=Factorial(num[i][j])
			}

		}
	}
	return int(ret)
}
```