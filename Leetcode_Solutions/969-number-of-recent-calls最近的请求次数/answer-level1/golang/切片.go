### 解题思路
此处撰写解题思路

### 代码

```golang
type RecentCounter struct {
	time []int
}


func Constructor() RecentCounter {
	return RecentCounter{time:[]int{}}
}


func (this *RecentCounter) Ping(t int) int {
	p:=t-3000
	for len(this.time)>0&&this.time[0]<p{
		this.time=this.time[1:]
	}
	this.time= append(this.time, t)
	return len(this.time)
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
```