若是不在圆内则递归调用一次
```
type Solution struct {
	radius   float64
	x_center float64
	y_center float64
}

func Constructor(radius float64, x_center float64, y_center float64) Solution {
	return Solution{radius: radius, x_center: x_center, y_center: y_center}
}

func (this *Solution) RandPoint() []float64 {
	x := rand.Float64() * this.radius * 2
	y := rand.Float64() * this.radius * 2
	fmt.Println(x, y)
	a := x - this.radius
	b := y - this.radius
	if a*a+b*b < this.radius*this.radius {
		// 在圆内
		return []float64{x + this.x_center - this.radius, y + this.y_center - this.radius}
	} else {
		return this.RandPoint()
	}
}

```