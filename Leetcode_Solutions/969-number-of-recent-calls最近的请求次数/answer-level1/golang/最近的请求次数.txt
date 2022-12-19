### 解题思路
使用队列维护ping的时间, 清楚过期时间

### 代码

```golang
type RecentCounter struct {
	time []int
}


func Constructor() RecentCounter {
	return RecentCounter{time: []int{}}
}


func (rc *RecentCounter) Ping(t int) int {
	p := t - 3000
	for len(rc.time)>0 && p > rc.time[0] {
		rc.time = rc.time[1:]
	}
	rc.time = append(rc.time, t)
	return len(rc.time)
}
```