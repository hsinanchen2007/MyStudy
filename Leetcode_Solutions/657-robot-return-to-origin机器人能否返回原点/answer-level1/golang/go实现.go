# 方法1：通过x,y模拟路径
```

func judgeCircle(moves string) bool {
	var x,y int
	for i:=0;i<len(moves) ;i++  {
		switch moves[i] {
		case 'L':
			x--
		case 'R':
			x++
		case 'U':
			y++
		case 'D':
			y--
		}
	}
	if x == 0 && y==0{
		return true
	}else{
		return false
	}
}
```
# 方法2：堆栈实现（耗时耗力）
```

func judgeCircle(moves string) bool {
	var stackLR = make([]byte,0)
	var stackUD = make([]byte,0)
	for i:=0;i<len(moves) ;i++  {
		if moves[i] == 'L' || moves[i] == 'R'{
			if len(stackLR) == 0{
				stackLR = append(stackLR,moves[i])
			}else if stackLR[len(stackLR)-1] == moves[i]{
				stackLR = append(stackLR,moves[i])
			}else if stackLR[len(stackLR)-1] != moves[i]{
				stackLR = stackLR[:len(stackLR)-1]
			}
		}else if moves[i] == 'U' || moves[i] == 'D'{
			if len(stackUD) == 0{
				stackUD = append(stackUD,moves[i])
			}else if stackUD[len(stackUD)-1] == moves[i]{
				stackUD = append(stackUD,moves[i])
			}else if stackUD[len(stackUD)-1] != moves[i]{
				stackUD = stackUD[:len(stackUD)-1]
			}
		}
	}
	if len(stackUD) == 0 && len(stackLR) == 0{
		return true
	}else{
		return false
	}
}
}
```

