记住上一步的偶数和,改一个变化的值,就得出新一步的值
```
func sumEvenAfterQueries(A []int, queries [][]int) []int {
	//懒得判断边界,就多初始化一个,最后还前面的切片就行
	ans := make([]int, len(queries)+1)
	//算出初始A数组的偶数和
	for _, value := range A {
		if isEven(value) {
			ans[0] += value
		}
	}
	for key, value := range queries {
		//如果该位置原值为偶数,则先减原值
		if isEven(A[value[1]]) {
			ans[key] -= A[value[1]]
		}
		A[value[1]] += value[0]
		//如果该位置更改后为偶数,则加上更改后的值
		if isEven(A[value[1]]) {
			ans[key] += A[value[1]]
		}
		//把下一步的初始值算出来
		ans[key+1] = ans[key]
	}
	return ans[:len(queries)]
}

//判断是不是偶数
func isEven(a int) bool {
	return a%2 == 0
}
```

执行用时 :
88 ms, 在所有 Go 提交中击败了93.33%的用户
内存消耗 :
7.5 MB, 在所有 Go 提交中击败了100.00%的用户
