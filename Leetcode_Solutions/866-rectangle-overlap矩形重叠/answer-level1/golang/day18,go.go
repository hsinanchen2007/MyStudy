### 解题思路
此处撰写解题思路

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	var overlap bool

	if len(rec1) != 4 || len(rec2) != 4 {
		return overlap
	}

	var rect1 = Rectangle{
		LeftDown:  Point{rec1[0], rec1[1]},
		LeftTop:   Point{rec1[0], rec1[3]},
		RightDown: Point{rec1[2], rec1[1]},
		RightTop:  Point{rec1[2], rec1[3]},
	}
	var rect2 = Rectangle{
		LeftDown:  Point{rec2[0], rec2[1]},
		LeftTop:   Point{rec2[0], rec2[3]},
		RightDown: Point{rec2[2], rec2[1]},
		RightTop:  Point{rec2[2], rec2[3]},
	}

	if rect2.RightDown.X > rect1.LeftTop.X && rect2.LeftDown.X < rect1.RightTop.X &&
		rect2.RightDown.Y < rect1.LeftTop.Y && rect2.RightTop.Y > rect1.LeftDown.Y {
		overlap = true
	}

	if rect2.RightDown.X > rect1.LeftDown.X && rect2.LeftTop.X < rect1.RightDown.X &&
		rect2.RightTop.Y > rect1.LeftDown.Y && rect2.LeftDown.Y < rect1.LeftTop.Y {
		overlap = true
	}

	return overlap
}

type Rectangle struct {
	LeftDown  Point
	LeftTop   Point
	RightDown Point
	RightTop  Point
}

type Point struct {
	X int
	Y int
}

```