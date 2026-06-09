这题题意很明显是贪心了，那么以什么作为尺度呢？
毫无疑问的，应该是一个人去A点和去B点的花费之差
简单来说，我们看[1,1000]，那么这个人应该去A点，因为会便宜999元
再来看[10,20],[1,1000],那么第二个人应该去A点，第一个人去B点。因为第一个人去A去B最多便宜10元，第二个人去A去B则可能便宜999元，这就是贪心在这一题的尺度了。
执行结果是：执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.5 MB, 在所有 Go 提交中击败了76.47%的用户
代码如下：
```
type intS [][]int
func (s intS) Len() int           { return len(s) }
func (s intS) Less(i, j int) bool { return s[i][2] > s[j][2] }
func (s intS) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }

func twoCitySchedCost(costs [][]int) int {
	if len(costs)<=1 {
		return 0
	}
	for i:=0;i<len(costs);i++{
		costs[i]=append(costs[i], abs(costs[i][0]-costs[i][1]))
	}
	sort.Sort(intS(costs))
	toA,toB,sum:=0,0,0
	for i:=0;i<len(costs);i++{
		if toA==len(costs)/2{
			sum+=costs[i][1]
			continue
		}
		if toB==len(costs)/2 {
			sum+=costs[i][0]
			continue
		}
		if costs[i][0]>costs[i][1] {
			sum+=costs[i][1]
			toB++
		}else{
			sum+=costs[i][0]
			toA++
		}
	}
	return sum
}

func abs(i int) int {
	if i<0 {
		i=-i
	}
	return i
}
```
