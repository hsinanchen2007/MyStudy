#### 方法一： 深度优先搜索

**思路**

如果节点有指向父节点的引用，也就知道了距离该节点 `1` 距离的所有节点。之后就可以从  `target` 节点开始进行深度优先搜索了。

**算法**
对所有节点添加一个指向父节点的引用，之后做深度优先搜索，找到所有距离 `target` 节点 `K` 距离的节点。

```Java []
class Solution {
    Map<TreeNode, TreeNode> parent;
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        parent = new HashMap();
        dfs(root, null);

        Queue<TreeNode> queue = new LinkedList();
        queue.add(null);
        queue.add(target);

        Set<TreeNode> seen = new HashSet();
        seen.add(target);
        seen.add(null);

        int dist = 0;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == null) {
                if (dist == K) {
                    List<Integer> ans = new ArrayList();
                    for (TreeNode n: queue)
                        ans.add(n.val);
                    return ans;
                }
                queue.offer(null);
                dist++;
            } else {
                if (!seen.contains(node.left)) {
                    seen.add(node.left);
                    queue.offer(node.left);
                }
                if (!seen.contains(node.right)) {
                    seen.add(node.right);
                    queue.offer(node.right);
                }
                TreeNode par = parent.get(node);
                if (!seen.contains(par)) {
                    seen.add(par);
                    queue.offer(par);
                }
            }
        }

        return new ArrayList<Integer>();
    }

    public void dfs(TreeNode node, TreeNode par) {
        if (node != null) {
            parent.put(node, par);
            dfs(node.left, node);
            dfs(node.right, node);
        }
    }
}
```

```Python []
class Solution(object):
    def distanceK(self, root, target, K):
        def dfs(node, par = None):
            if node:
                node.par = par
                dfs(node.left, node)
                dfs(node.right, node)

        dfs(root)

        queue = collections.deque([(target, 0)])
        seen = {target}
        while queue:
            if queue[0][1] == K:
                return [node.val for node, d in queue]
            node, d = queue.popleft()
            for nei in (node.left, node.right, node.par):
                if nei and nei not in seen:
                    seen.add(nei)
                    queue.append((nei, d+1))

        return []
```


**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是树中节点个数。

* 空间复杂度： $O(N)$。

#### 方法二： 计算节点之间距离

**思路**

如果 `target` 节点在 `root` 节点的左子树中，且 `target` 节点深度为 `3`，那所有 `root` 节点右子树中深度为 `K - 3` 的节点到 `target` 的距离就都是 `K`。

**算法**

深度优先遍历所有节点。定义方法 `dfs(node)`，这个函数会返回 `node` 到 `target` 的距离。在 `dfs(node)` 中处理下面四种情况：

* 如果 `node == target`，把子树中距离 `target` 节点距离为 `K` 的所有节点加入答案。

* 如果 `target` 在  `node` 左子树中，假设 `target` 距离 `node` 的距离为 `L+1`，找出右子树中距离 `target` 节点 `K - L - 1` 距离的所有节点加入答案。

* 如果 `target` 在 `node` 右子树中，跟在左子树中一样的处理方法。

* 如果 `target` 不在节点的子树中，不用处理。

实现的算法中，还会用到一个辅助方法  `subtree_add(node, dist)`，这个方法会将子树中距离节点 `node` `K - dist` 距离的节点加入答案。

```java [solution2-Java]
class Solution {
    List<Integer> ans;
    TreeNode target;
    int K;
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        ans = new LinkedList();
        this.target = target;
        this.K = K;
        dfs(root);
        return ans;
    }

    // Return vertex distance from node to target if exists, else -1
    // Vertex distance: the number of vertices on the path from node to target
    public int dfs(TreeNode node) {
        if (node == null)
            return -1;
        else if (node == target) {
            subtree_add(node, 0);
            return 1;
        } else {
            int L = dfs(node.left), R = dfs(node.right);
            if (L != -1) {
                if (L == K) ans.add(node.val);
                subtree_add(node.right, L + 1);
                return L + 1;
            } else if (R != -1) {
                if (R == K) ans.add(node.val);
                subtree_add(node.left, R + 1);
                return R + 1;
            } else {
                return -1;
            }
        }
    }

    // Add all nodes 'K - dist' from the node to answer.
    public void subtree_add(TreeNode node, int dist) {
        if (node == null) return;
        if (dist == K)
            ans.add(node.val);
        else {
            subtree_add(node.left, dist + 1);
            subtree_add(node.right, dist + 1);
        }
    }
}
```

```python [solution2-Python]
class Solution(object):
    def distanceK(self, root, target, K):
        ans = []

        # Return distance from node to target if exists, else -1
        # Vertex distance: the # of vertices on the path from node to target
        def dfs(node):
            if not node:
                return -1
            elif node is target:
                subtree_add(node, 0)
                return 1
            else:
                L, R = dfs(node.left), dfs(node.right)
                if L != -1:
                    if L == K: ans.append(node.val)
                    subtree_add(node.right, L + 1)
                    return L + 1
                elif R != -1:
                    if R == K: ans.append(node.val)
                    subtree_add(node.left, R + 1)
                    return R + 1
                else:
                    return -1

        # Add all nodes 'K - dist' from the node to answer.
        def subtree_add(node, dist):
            if not node:
                return
            elif dist == K:
                ans.append(node.val)
            else:
                subtree_add(node.left, dist + 1)
                subtree_add(node.right, dist + 1)

        dfs(root)
        return ans
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 树的大小。

* 空间复杂度： $O(N)$。