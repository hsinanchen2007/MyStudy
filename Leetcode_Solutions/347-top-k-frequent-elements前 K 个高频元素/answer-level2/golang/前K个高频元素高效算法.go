```
type Pair struct {
	Key	int
	Value	int
}

type Pairs []Pair

func (p Pairs) Swap(i, j int) { p[i], p[j] = p[j], p[i] }
func (p Pairs) Len() int { return len(p)}
func (p Pairs) Less(i, j int) bool { return !(p[i].Value < p[j].Value) }

func topKFrequent(nums []int, k int) []int {
	times := make(map[int]int)
	var res []int

	for _, v := range nums {
		if times[v] != 0 {
			times[v]++
		} else {
			times[v] = 1
		}
	}

	p := make(Pairs, len(times))
	i := 0
	for num, v := range times {
		p[i] = Pair{num, v}
		i++
	}
	sort.Sort(p)

	for i, v := range p {
		if i < k {
			res = append(res, v.Key)
		}
	}
	return res
}
```
