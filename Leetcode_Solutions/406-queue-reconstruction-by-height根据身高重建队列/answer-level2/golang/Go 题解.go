思路：
1. 将队列按前面的人数k分组并排序。
2. 创建新数组，按照k从小到大，h从高到低的顺序遍历各个分组，确定重新排序后的位置并插入队列。

```
//执行用时 :64 ms, 在所有 Go 提交中击败了64.00%的用户
//内存消耗 :8 MB, 在所有 Go 提交中击败了100.00%的用户
```
```Go []
func reconstructQueue(people [][]int) [][]int {
	if len(people) <= 1 {
		return people
	}
	// group by k
	km := make(map[int][]int)
	for _, p := range people {
		if _, ok := km[p[1]]; ok {
			km[p[1]] = append(km[p[1]], p[0])
		} else {
			a := make([]int, 1)
			a[0] = p[0]
			km[p[1]] = a
		}
	}
	// sort every group
	ka := make([]int, len(km))
	var c int
	for k := range km {
		ka[c] = k
		sort.Ints(km[k])
		c++
	}
	sort.Ints(ka)
	// reconstruct array by group
	var h int
	rcq := make([][]int, 0)
	for _, k := range ka {
		for j := len(km[k]) - 1; j >= 0; j-- {
			h = km[k][j]
			c = 0
			for j := range rcq {
				if k == 0 {
					if h < rcq[j][0] {
						rcq = append(rcq[0:j], append([][]int{{h, k}}, rcq[j:]...)...)
						c++
						break
					}
				} else if rcq[j][0] >= h {
					c++
				}
				if c == k {
					rcq = append(rcq[0:j+1], append([][]int{{h, k}}, rcq[j+1:]...)...)
					break
				}
			}
			if c < k || len(rcq) == 0 {
				rcq = append(rcq, []int{h, k})
			}
		}
	}
	return rcq
}
```
[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)
