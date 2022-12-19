### 解题思路
此处撰写解题思路

### 代码

```golang

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	result := make([][]int, 0)
	num := make([]int, 0)
	dfs(candidates, target, num, &result, 0)
	r := make([][]int,0)
	for i:=0;i<len(result);i++ {
		if !isExist(result[i],r){
			r=append(r,result[i])
		}
	}
	return r
}

func isExist(a []int, r [][]int)bool{
	for i:=0;i<len(r);i++{
		if isEqual(a,r[i]){
			return true
		}
	}
	return false 
}

func isEqual(a, b[]int)bool{
	if len(a) !=len(b){
		return false
	}
	for i:=0;i<len(a);i++{
		if a[i] !=b[i]{
			return false
		}
	}
	return true
}


func dfs(candidates []int, target int, num []int, result *[][]int, left int) {

	if target == 0 {
		tmp := make([]int, len(num))
		copy(tmp, num) //这里必须要copy，否则会有问题，因为num会被不断的修改，这会导致result里面的值被修改，因为他们使用的是同样的底层数据
		*result = append(*result, tmp)
		return
	}
	for i := left; i < len(candidates); i++ {
		if target < candidates[i] {
			return
		}
		num := append(num, candidates[i])
		dfs(candidates, target-candidates[i], num, result, i+1)
	}
}
```