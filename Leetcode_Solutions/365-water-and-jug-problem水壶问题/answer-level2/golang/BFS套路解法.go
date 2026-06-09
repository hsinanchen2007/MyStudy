```
type State struct {
	X int
	Y int
}

// 从(0,0)-->(z,0) || (0,z)) || (X,Y),X+Y=z的路径可达性
func canMeasureWater(x int, y int, z int) bool {
	if x+y < z {
		return false
	}
	return bfs(x, y, z)
}

// bfs的套路：
// 1. 初始化状态: 队列，记录是否访问过的map，起点入队
// 2. 循环判断队列长度非空
// 3. 循环内：队首元素出队(获取当前状态)，判断是否访问过（防止重复搜索死循环），判断截止条件，把下一次可达的所有状态入队
func bfs(x, y, z int) bool {
	var queue []State
	initState := State{
		X: 0,
		Y: 0,
	}
	queue = append(queue, initState)
	visitedMap := make(map[State]bool)

	for len(queue) > 0 {
		nowState := queue[0]
		queue = queue[1:]
		if visitedMap[nowState] {
			continue
		}
		visitedMap[nowState] = true

		// 截止条件
		if nowState.X == z || nowState.Y == z || nowState.X+nowState.Y == z {
			return true
		}

		// 增加下一次可达的状态：倒满X
		nextState := State{
			X: x,
			Y: nowState.Y,
		}
		queue = append(queue, nextState)

		// 增加下一次可达的状态：倒满Y
		nextState = State{
			X: nowState.X,
			Y: y,
		}
		queue = append(queue, nextState)

		// 增加下一次可达的状态：清空X
		nextState = State{
			X: 0,
			Y: nowState.Y,
		}
		queue = append(queue, nextState)

		// 增加下一次可达的状态：清空Y
		nextState = State{
			X: nowState.X,
			Y: 0,
		}
		queue = append(queue, nextState)

		// 增加下一次可达的状态：X的水倒入Y
		if nowState.X > y-nowState.Y {
			nextState = State{
				X: nowState.X + nowState.Y - y,
				Y: y,
			}
			queue = append(queue, nextState)
		} else {
			nextState = State{
				X: 0,
				Y: nowState.X + nowState.Y,
			}
			queue = append(queue, nextState)
		}

		// 增加下一次可达的状态：Y的水倒入X
		if nowState.Y > x-nowState.X {
			nextState = State{
				X: x,
				Y: nowState.X + nowState.Y - x,
			}
			queue = append(queue, nextState)
		} else {
			nextState = State{
				X: nowState.X + nowState.Y,
				Y: 0,
			}
			queue = append(queue, nextState)
		}
	}
	return false
}

```
