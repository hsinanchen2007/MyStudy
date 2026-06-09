# BFS

```kotlin
private fun TreeNode?.levelOrder(): List<List<Int>> {
    val nodes = mutableListOf<MutableList<Int>>()
    this ?: return nodes

    val queue = ArrayDeque<Pair<Int, TreeNode?>>()
    queue.offer(0 to this)
    while(queue.isNotEmpty()) {
        val (index, node) = queue.poll()
        if (node != null) {
            if (nodes.size <= index) {
                nodes.add(mutableListOf())
            }
            nodes[index].add(node.`val`)

            // 入队列
            queue.offer(index + 1 to node.left)
            queue.offer(index + 1 to node.right)
        }
    }
    return nodes
}
```

# DFS

```kotlin
private fun TreeNode?.levelOrderDFS(nodes: MutableList<MutableList<Int>>, level: Int = 0): List<List<Int>> {
    this ?: return nodes

    if (nodes.size <= level) {
        nodes.add(mutableListOf())
    }
    nodes[level].add(this.`val`)

    this.left.levelOrderDFS(nodes, level + 1)
    this.right.levelOrderDFS(nodes, level + 1)

    return nodes
}
```