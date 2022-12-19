先按照结束时间排序，然后预处理每一个任务的前一个可执行任务的位置，最后dp
```
type AllTask struct {
	Tasks []*Task
}

type Task struct {
	Start int
	End   int
	Price int
}

func (t *AllTask) Len() int {
	return len(t.Tasks)
}
func (t *AllTask)Less(i, j int) bool{
	return t.Tasks[i].End < t.Tasks[j].End
}
func (t *AllTask)Swap(i, j int){
	t.Tasks[i],t.Tasks[j] = t.Tasks[j],t.Tasks[i]
}

func jobScheduling(startTime []int, endTime []int, profit []int) int {
	AT := &AllTask{}
	arr := make([]*Task, len(profit))
	for i,v := range profit {
		t := &Task{Start:startTime[i],End:endTime[i],Price:v}
		arr[i] = t
	}
	AT.Tasks = arr

	sort.Sort(AT)

	count := len(AT.Tasks)
	prev := make([]int, count)
	for index, _ := range AT.Tasks {
		prev[index] = -1
	}
	prev[0] = -1
	for i := 1; i < count; i++ {
		for j := i - 1; j >= 0; j-- {
			if AT.Tasks[i].Start >= AT.Tasks[j].End || AT.Tasks[j].Start >= AT.Tasks[i].End {
				prev[i] = j
				break
			}
		}
	}

	dp := make([]int, count)
	dp[0] = AT.Tasks[0].Price
	for i := 1; i < count; i++ {
		//不选
		p1 := dp[i-1]
		//选
		p2 := AT.Tasks[i].Price
		if prev[i] >= 0 {
			p2 = dp[prev[i]] + AT.Tasks[i].Price
		}
		dp[i] = int(math.Max(float64(p1), float64(p2)))
	}

	return dp[len(profit)-1]
}
```
