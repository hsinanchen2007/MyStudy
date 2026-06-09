### 解题思路
此处撰写解题思路

### 代码

```golang

type sortIntervals [][]int

func (s sortIntervals) Len() int {
	return len(s)
}

func (s sortIntervals) Less(i, j int) bool {
	return s[i][0] < s[j][0]
}

func (s sortIntervals) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func minMeetingRooms(intervals [][]int) int {
    if len(intervals) == 0 {
		return 0
	}
    
	n := 1
	findRooms(intervals, &n)
	return n
}

func findRooms(intervals [][]int, n *int) {
	if len(intervals) == 0 {
		return
	}

	sort.Sort(sortIntervals(intervals))
    //fmt.Println(intervals)

	intervals2 := make([][]int, 0, len(intervals))
	j := 0
    flag := false
	for i:=1;i<len(intervals);i++ {
		if intervals[i][0] < intervals[j][1] {
			intervals2 = append(intervals2, intervals[i])
			flag = true
		}else {
			j = i
		}
	}

    if flag {
		*n++
	}

	findRooms(intervals2, n)
}
```