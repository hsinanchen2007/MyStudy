

### 代码

```golang
type RecentCounter struct {
    counts []int
}


func Constructor() RecentCounter {
    return RecentCounter{}
}


func (this *RecentCounter) Ping(t int) int {
    var count int
    this.counts = append(this.counts,t)
    for _,v := range this.counts{
        if v + 3000 >= t {
            count++
        }
    }
    
    return count
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
```