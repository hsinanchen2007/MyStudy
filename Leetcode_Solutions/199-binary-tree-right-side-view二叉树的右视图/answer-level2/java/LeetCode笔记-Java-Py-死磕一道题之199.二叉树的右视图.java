### 方法1：DFS
当采用前序遍历时，采用的是根左右，本题我们改写前序遍历的方式，采用的是根右左，带来的好处是在每一层的时候，第一次出现的是右视图，也就是我们想要收集的，
现在的问题是如何返回：
 
```
if (depth >= resList.size()) resList.add(root.val);
```


意思也很简单，当这一层的层数比`resList`的`size`要大的时候，证明此时是第一次到达这一层，开始添加
> 此处注意`resList`的size指的是元素的个数，而`depth`从`0`开始，也就是第一层是`0`，导致的结果是`depth`总是先于`resList`的`size`
出口的条件同样可以这样写：
```
if (depth == resList.size()) resList.add(root.val);
```



```java []
public List<Integer> rightSideView(TreeNode root) {
    List<Integer> resList = new ArrayList<>();
    if (root == null) return resList;
    dfs(root, resList, 0);
    return resList;
}

public void dfs(TreeNode root, List<Integer> resList, int depth) {
    if (root == null) return;
    if (depth >= resList.size()) resList.add(root.val);
    if (root.right != null) dfs(root.right, resList, depth + 1);
    if (root.left != null) dfs(root.left, resList, depth + 1);
}
```
```python []
print('Hello world!')
```






###  方法2：BFS
```java []
public List<Integer> rightSideView(TreeNode root) {
    List<Integer> resList = new ArrayList<>();
    if (root == null) return resList;
    bfs(root, resList);
    return resList;
}

public void bfs(TreeNode root, List<Integer> resList) {
    if (root == null) return;
    Queue<TreeNode> nodeQueue = new LinkedList<>();
    Queue<Integer> depthQueue = new LinkedList<>();
    nodeQueue.add(root);
    depthQueue.add(0);
    while (!nodeQueue.isEmpty()) {
        TreeNode curNode = nodeQueue.poll();
        int curDepth = depthQueue.poll();
        if (depthQueue.isEmpty() || depthQueue.peek() != curDepth) {
            resList.add(curNode.val);
        }
        if (curNode.left != null) {
            nodeQueue.add(curNode.left);
            depthQueue.add(curDepth + 1);
        }
        if (curNode.right != null) {
            nodeQueue.add(curNode.right);
            depthQueue.add(curDepth + 1);
        }
    }

}
```
```python []
print('Hello world!')
```




### 方法3：BFS层次遍历变体[Java/Python]
准备一个`queue`，先进先出，遍历每一层的时候，先左节点后右节点，这样，在这一层的最后一个节点就是我们要的，如下取到
```
 if (i == (size - 1)) resList.add(curNode.val);
```


`size`是当前这一层的大小，当到达这一层的最后一个即是所求
每次先`peek`到这个节点，以便记录其左右节点

> 其中append方法是往队列的末尾添加元素
> pop(0)指的是弹出队列索引为0的元素，即对头元素
> -1切片操作，取最后一个元素


```java []
public List<Integer> rightSideView(TreeNode root) {
    List<Integer> resList = new ArrayList<Integer>();
    if (root == null) return resList;
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);
    while (!queue.isEmpty()) {
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            TreeNode curNode = queue.peek();
            queue.poll();
            if (i == (size - 1)) resList.add(curNode.val);
            if (curNode.left != null) queue.add(curNode.left);
            if (curNode.right != null) queue.add(curNode.right);
        }
    }
    return resList;
}
```
```python []
def rightSideView(self, root: TreeNode) -> List[int]:
    res = []
    if not root: return res
    queue = [root]
    while queue:
        size = len(queue)
        # 取这一层的最后一个元素的值，也就是最右边的节点
        res.append(queue[-1].val)
        for _ in range(size):
            # 弹出队列的第一个元素，也就是对头元素
            cur = queue.pop(0)
            if cur.left: queue.append(cur.left)
            if cur.right: queue.append(cur.right)
    return res

```






