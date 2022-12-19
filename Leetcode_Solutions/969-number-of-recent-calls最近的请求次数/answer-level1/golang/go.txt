```
type RecentCounter struct {
    queue []int
}


func Constructor() RecentCounter {
    return RecentCounter {
        queue: make([]int, 0),
    }
}


func (this *RecentCounter) Ping(t int) int {
    this.queue = append(this.queue, t)
    l, ans := len(this.queue), 1
    for l -= 2; l >= 0; l-- {
        if t - this.queue[l] <= 3000 {
            ans++
        } else {
            this.queue = this.queue[l + 1:]
            break
        }
    }
        
    return ans
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
```
