根据pos排序，依次判断后面的车能否超越前车
```
type Node struct {
	pos   int
	speed int
}

func carFleet(target int, position []int, speed []int) int {
	node := make([]Node, len(position))
	for i := 0; i < len(position); i++ {
		node[i] = Node{position[i], speed[i]}
	}
	sort.Slice(node, func(i, j int) bool {
		return node[i].pos > node[j].pos
	})
	count := 0
	for len(node) > 1 {
		pre := node[0]
		prePos := pre.pos + pre.speed
		pre.pos = prePos
		tmp := make([]Node, 0, len(node))
		for i := 1; i < len(node); i++ {
			now := node[i]
			nowPos := now.pos + now.speed
			now.pos = nowPos
			if nowPos >= prePos {
				if nowPos > target {
					if float64(target-(now.pos-now.speed))/float64(now.speed) >= float64(target-(pre.pos-pre.speed))/float64(pre.speed) {
						count++
						pre = now
						prePos = nowPos
					}
				}
			} else {
				if prePos >= target {
					count++
				} else {
					tmp = append(tmp, pre)
				}
				pre = now
				prePos = nowPos
			}
		}
		if prePos >= target {
			count++
		} else {
			tmp = append(tmp, pre)
		}
		node = tmp
	}
	if len(node) == 1 {
		count++
	}
	return count
}
```
