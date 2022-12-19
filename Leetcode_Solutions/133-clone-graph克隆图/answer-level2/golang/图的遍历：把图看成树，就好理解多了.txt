把图看成一棵树会比较好理解
要注意和树不同的是，孩子节点可能反过来成为父节点，递归或遍历会形成无限循环
需要用额外的数据结构如哈希表来记录节点是否访问过
直观的做法是哈希表定义为键为*Node值为bool，这样不太好处理；想想，改成值为原图中节点，键为新图中节点，会比较好。

```text
递归DFS

假设所有节点个数为n，
时间复杂度O(n)，每个节点处理一次，栈调用时间复杂度O(H),H为图的最大深度，综合复杂度O(n)
空间复杂度O(n)，哈希表需要O(n)，栈需要O(H)
```
```go
func cloneGraph1(node *Node) *Node {
	visited := make(map[*Node]*Node, 0)
	var dfs func(*Node) *Node
	dfs = func(n *Node) *Node {
		if n == nil {
			return nil
		}
		if r, ok := visited[n]; ok {
			return r
		}
		r := &Node{Val: n.Val, Neighbors: make([]*Node, len(n.Neighbors))}
		visited[n] = r
		for i, v := range n.Neighbors {
			r.Neighbors[i] = dfs(v)
		}
		return r
	}
	return dfs(node)
}
```
```text
迭代BFS，存放临时节点的容器可随意选用，这里选list
时间复杂度O(n)，每个节点处理一次
空间复杂度O(n)，哈希表需要O(n), BFS使用的容器需要O(W)，其中W是图的宽度， 综合复杂度O(n)
```
```go
func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}
	queue := list.New()
	queue.PushBack(node)
	visited := make(map[*Node]*Node, 0)
	visited[node] = &Node{Val: node.Val, Neighbors: make([]*Node, len(node.Neighbors))}
	for queue.Len() > 0 {
		n := queue.Remove(queue.Front()).(*Node)
		for i, v := range n.Neighbors {
			if _, ok := visited[v]; !ok {
				queue.PushBack(v)
				visited[v] = &Node{Val: v.Val, Neighbors: make([]*Node, len(v.Neighbors))}
			}
			visited[n].Neighbors[i] = visited[v]
		}
	}
	return visited[node]
}
```