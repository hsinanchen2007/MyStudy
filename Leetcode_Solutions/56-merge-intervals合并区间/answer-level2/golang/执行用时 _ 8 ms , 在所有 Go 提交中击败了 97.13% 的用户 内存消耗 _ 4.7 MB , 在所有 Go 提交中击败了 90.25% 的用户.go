代码水平很菜，但跑出来结果还行，就写个题解放这里，话不多说，直接上代码：
```
type ints [][]int

func (s ints) Len() int           { return len(s) }
func (s ints) Less(i, j int) bool { return s[i][0] < s[j][0] }
func (s ints) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }

func merge(intervals [][]int) [][]int {
	var res [][]int
	if len(intervals)==0 {
		return res
	}
	sort.Sort(ints(intervals))
	i:=0
	if i<len(intervals)-1{
		for{
			if i>=len(intervals)-1 {
				break
			}
			if intervals[i][1]<intervals[i+1][0] {
				res=append(res,intervals[i])
			}else if intervals[i][1]==intervals[i+1][0]{
				intervals[i+1][0]=intervals[i][0]
			}else{
				intervals[i+1][0]=intervals[i][0]
				if intervals[i+1][1]<intervals[i][1] {
					intervals[i+1][1]=intervals[i][1]
				}
			}
			i++
		}
	}
	res=append(res,intervals[i])
	return res
}
```
