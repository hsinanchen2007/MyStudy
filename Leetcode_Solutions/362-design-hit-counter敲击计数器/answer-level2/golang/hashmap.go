### 解题思路
此处撰写解题思路

### 代码

```golang
type HitCounter struct {
	m map[int]int
}

/** Initialize your data structure here. */
func Constructor() HitCounter {
	c := HitCounter{m: map[int]int{}}
	return c
}

/** Record a hit.
  @param timestamp - The current timestamp (in seconds granularity). */
func (this *HitCounter) Hit(timestamp int) {
	this.m[timestamp]++
}

/** Return the number of hits in the past 5 minutes.
  @param timestamp - The current timestamp (in seconds granularity). */
func (this *HitCounter) GetHits(timestamp int) int {
	start := timestamp - 300 + 1
	sum := 0
	for i := start; i <= timestamp; i++ {
		if v, ok := this.m[i]; ok {
			sum += v
		}
	}
	return sum
}

```