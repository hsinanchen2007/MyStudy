### 解题思路
此处撰写解题思路

### 代码

```golang
func judgeCircle(moves string) bool {
	x:=0
	y:=0
	for _,v:=range moves{
		switch v {
		case 'R':
			x++
		case 'L':
			x--
		case 'U':
			y++
		case 'D':
			y--
		default:
			fmt.Println("err")

		}

	}
	if x==0&&y==0{
		return true
	}
	return false
}
```