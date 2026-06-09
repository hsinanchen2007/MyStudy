这是个好问题，思路是用广度优先搜索来找到最短路径，有一些细节好好挖掘能形成编程技巧。<br>
如果对BFS不熟，可以先参考这个题解：[[778] 在水位上升的泳池中游泳](https://leetcode-cn.com/problems/swim-in-rising-water/solution/go-xiang-xi-bfsjiang-jie-guan-fang-ti-jie-de-ben-z/)
```text
解法一：常规广度优先搜索
用一个集合存储当前访问状态列表
从 0000 开始搜索，对于每一个状态，可以扩展到最多 8 个状态，即将每一位增加 1 或减少 1，
将这些状态中没有搜索过并且不在 deadends 中的状态全部加入到队列中，并继续搜索，直到到达目标状态。

注意 0000 本身有可能也在 deadends 中。
为方便计数，可以在visited里维护到达每个状态的步数
存储当前访问状态列表的集合可以任选，切片、list、map等都可以，对顺序没有要求
```
```go
func openLock(deadends []string, target string) int {
	// 预处理，边界情况及时返回
	const initial = "0000"
	if target == initial {
		return 0
	}
	isDead := make(map[string]bool, 0) // 将deadends处理成哈希表，方便迅速查找某个状态是否在里边
	for _, v := range deadends {
		isDead[v] = true
	}
	if isDead[initial] {
		return -1
	}
	// 广度优先搜索
	// BFS 准备
	queue := list.New()
	queue.PushBack(initial)
	visited := map[string]int{initial: 0} // 已访问过的状态集合，并记录到达该状态花的步数
	visitNextStatus := func(origin string) { // 获取origin的下一个状态（在这里有8种）并将合适的状态入队
		b := []byte(origin)
		for i, c := range b {
			for d := -1; d <= 1; d += 2 { // 1 或 -1， b的每一位要加1或减1，以得到下一个状态
				b[i] = byte((int(c-'0')+d+10)%10) + '0'
				next := string(b)
				b[i] = c // 恢复原字符串
				if _, ok := visited[next]; ok || isDead[next] {
					continue
				}
				visited[next] = visited[origin] + 1
				queue.PushBack(next)
			}
		}
	}
	// BFS主体逻辑
	for queue.Len() > 0 {
		s := queue.Remove(queue.Front()).(string)
		if s == target {
			return visited[s]
		}
		visitNextStatus(s)
	}
	return -1
}
```
```text
解法二：优化后的广度优先搜索
首先一开始可以把deadends里的状态放入visited，这样不用另开辟isDead的空间；实际测试这个优化对性能提升并不明显
看了别的题解，有这样一个优化：
可以分别从初始状态和目标状态向中间状态搜索，如果中间有状态相同，即完成了BFS
实际测试发现，维持这两个搜索使用的集合大小相当，会显著优化时间花费
注意，为了能迅速获知两个集合是不是有相同元素，这里的集合用哈希表再合适不过
```
参考的 [leetcode题解](https://leetcode-cn.com/problems/open-the-lock/solution/da-kai-zhuan-pan-suo-shi-xian-yu-zheng-li-by-eiger/)
```go
func openLock(deadends []string, target string) int {
	const initial = "0000"
	if target == initial {
		return 0
	}
	visited := make(map[string]bool)
	for _, v := range deadends {
		visited[v] = true
	}
	if visited[initial] {
		return -1
	}

	start := map[string]bool{initial: true}
	end := map[string]bool{target: true}
	return bfs(start, end, visited, 0) // count代表步数，从0开始
}

// 模拟双向搜索。 count为步数
func bfs(start, end, visited map[string]bool, count int) int {
	if len(start) > len(end) { // 从已经遍历少的那一端开始， 维持两端搜索的数量相当，能明显优化搜索步数
		return bfs(end, start, visited, count)
	}
	if len(start) <= 0 {
		return -1
	}

	nextStatus := make(map[string]bool) //存储start端下一步需要处理的状态
	for s := range start {
		if _, ok := end[s]; ok { // end队列也有，说明从初始到目标状态的一个通路形成了
			return count
		}
		visited[s] = true
		b := []byte(s)
		for i, c := range b {
			for d := -1; d <= 1; d += 2 { // 1 或 -1， b的每一位要加1或减1，以得到下一个状态
				b[i] = byte((int(c-'0')+d+10)%10) + '0'
				next := string(b)
				b[i] = c // 复原状态
				if visited[next] {
					continue
				}
				nextStatus[next] = true
			}
		}
	}
	count++
	return bfs(nextStatus, end, visited, count)
}
```