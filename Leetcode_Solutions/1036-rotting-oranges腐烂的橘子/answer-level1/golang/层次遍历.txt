```
type Node struct {
	level int
	iIndex int
	jIndex int
}


func orangesRotting(grid [][]int) int {
	if len(grid) == 0{
		return 0
	}
	var queue = make([]Node,0)
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid[0]) ;j++  {
			if grid[i][j] == 2{
				queue = append(queue, Node{level: 1,iIndex: i, jIndex: j,})
			}
		}
	}
	var maxLevel int
	var node Node
	for len(queue) != 0{
		node = queue[0]
		if node.level > maxLevel{
			maxLevel = node.level
		}
		queue = queue[1:]
		var left,right = node.jIndex-1,node.jIndex+1
		var top,bottom = node.iIndex-1,node.iIndex+1
		if left >= 0 && grid[node.iIndex][left] == 1{
			queue = append(queue,Node{level: node.level+1,iIndex: node.iIndex, jIndex: left})
			grid[node.iIndex][left] = 2
		}
		if right < len(grid[0]) && grid[node.iIndex][right] == 1{
			queue = append(queue,Node{level: node.level+1,iIndex: node.iIndex, jIndex: right})
			grid[node.iIndex][right] = 2
		}
		if top >= 0 && grid[top][node.jIndex] == 1{
			queue = append(queue,Node{level: node.level+1,iIndex: top, jIndex: node.jIndex})
			grid[top][node.jIndex] = 2
		}
		if bottom >= 0 && grid[bottom][node.jIndex] == 1{
			queue = append(queue,Node{level: node.level+1,iIndex: bottom, jIndex: node.jIndex})
			grid[bottom][node.jIndex] = 2
		}
	}
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid[0]) ;j++  {
			if grid[i][j] == 1{
				return -1
			}
		}
	}
	return maxLevel
}

```
