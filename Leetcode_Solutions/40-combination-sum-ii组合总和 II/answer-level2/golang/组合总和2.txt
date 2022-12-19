### 解题思路
和组合总和1不同点
1. 数组中可能含有重复元素
2. 数组中每个元素只能用一次
3. 不同点2很好解决，只要每次都从下一个元素开始递归就行了；但是不同点1，却会导致结果中会有重复组合，如何去重就是很关键的一个问题了：
	 - 数组中的相同元素不能同时出现于组合中的某个位置。比如数组中有两个1，那么以1开头的所有组合只能是两个1中的其中一个
	 - 如何保证上面的限制呢？必须对数组进行排序，然后在for循环中跳过重复元素；
	 - for循环代表的意思是什么呢？代表了组合中某个位置可能的元素。比如最开始的for循环就代表了组合可能以哪些元素作开头
	 - 递归考虑的才是组合的后续元素应该是什么！

### 代码

```golang
func p(candidates []int, path []int, residule int, res *[][]int) {
	if residule == 0 {
		*res = append(*res, path)
		return
	}
	l := len(candidates)
	//组合中某个位置可能出现的元素！
	for i := 0; i < l; i++ {
		if residule-candidates[i] < 0 {
			break
		}
		//跳过在组合中相同位置出现多次的元素！
        if i > 0 && candidates[i] == candidates[i-1] {
            continue
        }
		if l == 1 {
			p(nil, append(path, candidates[i]), residule-candidates[i], res)
		} else {
			p(candidates[i+1:], append(path, candidates[i]), residule-candidates[i], res)
		}
	}
}
func combinationSum2(candidates []int, target int) [][]int {
	var res [][]int
	if len(candidates)==0 {
		return res
	}
	sort.Ints(candidates)
	p(candidates,nil,target,&res)
	return res
}
```