### 解题思路
考虑节省空间，使用空间复杂度为O(N)的算法。在每次加入元素的同时进行判断，如果需要覆盖循环队列中的元素，则用总和减去需要替换的值，然后加上新值，这样就不需要每次都计算一次总和了，使得时间复杂度简化
为O(1)

### 代码

```golang
type MovingAverage struct {
    Size    int   `json:"size"`    //滑动窗口大小
	Element []int `json:"element"` //存储元素
	Move    int   `json:"move"`    //当前位置
    Total   int   `json:"total"`   //当前元素和
}


/** Initialize your data structure here. */
func Constructor(size int) MovingAverage {
    ret := MovingAverage{}
	ret.Size = size
	ret.Element = make([]int, 0, size)
	return ret
}


func (this *MovingAverage) Next(val int) float64 {
    if len(this.Element) < cap(this.Element) {
		this.Element = append(this.Element, val)
		this.Total += val

	} else {
		this.Total -= this.Element[this.Move]
		this.Total += val
		this.Element[this.Move] = val
		this.Move += 1
		this.Move %= this.Size
	}

	return float64(this.Total) / float64(len(this.Element))
}


/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */
```