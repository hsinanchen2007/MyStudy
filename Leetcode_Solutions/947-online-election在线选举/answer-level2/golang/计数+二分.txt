预处理数据，查询的数据的时候二分
```
type TopVotedCandidate struct {
	Persons []int
	Times   []int
	Result  []int
}

func Constructor(persons []int, times []int) TopVotedCandidate {
	r := TopVotedCandidate{Persons: persons, Times: times}
	r.Cal()
	return r
}

func (this *TopVotedCandidate)Cal() {
	this.Result = make([]int, len(this.Persons))
	max := -1
	maxNum := this.Persons[0]
	counts := make(map[int]int)
	for indx, _:=range this.Times {
		counts[this.Persons[indx]]++
		if max <= counts[this.Persons[indx]] {
			max = counts[this.Persons[indx]]
			maxNum = this.Persons[indx]
		}
		this.Result[indx] = maxNum
	}
}

func (this *TopVotedCandidate) Q(t int) int {
	left := 0
	right := len(this.Times)-1
	mid := 0
	for left <= right  {
		mid = left + (right-left)/2
		if this.Times[mid] == t {
			break
		}else if this.Times[mid] < t {
			if mid == len(this.Times)-1 || this.Times[mid+1]>t {
				break
			}
			left = mid+1
		}else {
			right = mid-1
		}
	}
	return this.Result[mid]
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * obj := Constructor(persons, times);
 * param_1 := obj.Q(t);
 */

```
