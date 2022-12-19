golang解决，回溯+剪枝

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)

```
// 组合问题　回溯 + 剪枝
// 时间复杂度：O(k*Cₙᵏ)  空间复杂度：O(Cₙᵏ)
                                    
var res [][]int

func combine(n int, k int) [][]int {
	res = [][]int{}
	if n<k || n==0 || k==0 {
		return res
	}

	var t []int
	getCombinations(n, k, 1, 0, t)
	return res
}

func getCombinations(n int, k int, start int, cnt int, t []int) {
	if cnt==k {
		s := make([]int, len(t))
		copy(s, t)
		res = append(res, s)
		return 
	}

	// 剪枝："i<=n"  -->  "i<=n-(k-cnt)+1" 
	for i:=start; i<=n-(k-cnt)+1; i++ {  
		t = append(t, i)
		getCombinations(n, k, i+1, cnt+1, t)
		t = t[:len(t)-1]
	}
}
```

