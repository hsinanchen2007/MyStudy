### 解题思路
本质是对图的遍历,题里给的邻接表形式，可以使用dfs 或者bfs 都是可以的，这里代码提供的dfs，深度优先遍历，并染色已遍历的点。最终对比遍历过的点和所有的点进行对比即可。

### 代码

```swift
class Solution {
func canVisitAllRooms(_ rooms: [[Int]]) -> Bool {
	var queue = [0]
	var vsed = Set<Int>()

	while queue.isEmpty == false {
		guard let k = queue.popLast() else {
			continue
		}
		if vsed.contains(k) == false {
			let keys = rooms[k]
			vsed.insert(k) //添加已访问房间
			queue += keys //将要访问的
		}
	}
	return vsed.count == rooms.count
}
}
```

![sf.png](https://pic.leetcode-cn.com/e75859702f6ffb6fc4e2807946bd7967a6ec42133a5615b373b2a84dece2168b-sf.png)

# [欢迎一起来讨论算法 欢迎start](https://github.com/ifgyong/SF)

# [欢迎一起来讨论算法 欢迎start](https://github.com/ifgyong/SF)


# [欢迎一起来讨论算法 欢迎start](https://github.com/ifgyong/SF)