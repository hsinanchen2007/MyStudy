```
import "math"

var (
	SameX = Point{
		X: 10086,
		Y: 10086,
	}
	SameY = Point{
		X: 10010,
		Y: 10010,
	}
	SamePoint = Point{
		X: 99527,
		Y: 99527,
	}
)

func maxPoints(points [][]int) (maxCount int) {
	var (
		i, j, currCount int
		exists          bool
		slope           Point
		pointA, pointB  Point
		currCounts      map[Point]int
		length          = len(points)
	)
	switch length {
	case 0:
		return 0
	case 1:
		return 1
	}

	for i = 0; i < length-1; i++ {
		pointA = NewPoint(points[i])
		currCounts = map[Point]int{
			SameX: 1,
		}
		for j = i + 1; j < length; j++ {
			pointB = NewPoint(points[j])
			slope = pointB.Slope(pointA)
			if _, exists = currCounts[slope]; !exists && slope != SamePoint {
				currCounts[slope] = 2
			} else {
				currCounts[slope]++
			}
		}
		for slope, currCount = range currCounts {
			if slope == SamePoint {
				continue
			}
			if currCount+currCounts[SamePoint] > maxCount {
				maxCount = currCount + currCounts[SamePoint]
			}
		}
	}
	return
}

type Point struct {
	X, Y int
}

func NewPoint(point []int) Point {
	return Point{
		X: point[0],
		Y: point[1],
	}
}

// 因为 float64 有精度问题，所以借鉴别人的 slope 求值方法
func (p Point) Slope(p2 Point) Point {
	if p2.X == p.X {
		if p2.Y == p.Y {
			return SamePoint
		}
		return SameX
	} else if p2.Y == p.Y {
		return SameY
	}

	dy := p.Y - p2.Y
	dx := p.X - p2.X
	g := gcd(abs(dy), abs(dx))
	dy /= g
	dx /= g
	if dx < 0 {
		dy = -dy
		dx = -dx
	}
	return Point{dy, dx}
}

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	if a%b == 0 {
		return b
	}
	return gcd(b, a%b)
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

```
