#### 方法一：排序【通过】

**思路和算法**

将树中所有节点的值写入数组，之后将数组排序。依次计算相邻数之间的差值，找出其中最小的值。

```java [solution1-Java]
class Solution {
    List<Integer> vals;
    public int minDiffInBST(TreeNode root) {
        vals = new ArrayList();
        dfs(root);
        Collections.sort(vals);

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < vals.size() - 1; ++i)
            ans = Math.min(ans, vals.get(i+1) - vals.get(i));

        return ans;
    }

    public void dfs(TreeNode node) {
        if (node == null) return;
        vals.add(node.val);
        dfs(node.left);
        dfs(node.right);
    }
}

```

```python [solution1-Python]
class Solution(object):
    def minDiffInBST(self, root):
        vals = []
        def dfs(node):
            if node:
                vals.append(node.val)
                dfs(node.left)
                dfs(node.right)

        dfs(root)
        vals.sort()
        return min(vals[i+1] - vals[i]
                   for i in xrange(len(vals) - 1))
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是树中节点的个数，其为排序所消耗的时间。

* 空间复杂度：$O(N)$，其为 `vals` 的大小。

#### 方法二：中序遍历【通过】

**思路和算法**

在二叉搜索树中，中序遍历会将树中节点按数值大小顺序输出。只需要遍历计算相邻数的差值，取其中最小的就可以了。

```java [solution2-Java]
class Solution {
    Integer prev, ans;
    public int minDiffInBST(TreeNode root) {
        prev = null;
        ans = Integer.MAX_VALUE;
        dfs(root);
        return ans;
    }

    public void dfs(TreeNode node) {
        if (node == null) return;
        dfs(node.left);
        if (prev != null)
            ans = Math.min(ans, node.val - prev);
        prev = node.val;
        dfs(node.right);
    }
}
```

```python [solution2-Python]
class Solution(object):
    def minDiffInBST(self, root):
        def dfs(node):
            if node:
                dfs(node.left)
                self.ans = min(self.ans, node.val - self.prev)
                self.prev = node.val
                dfs(node.right)

        self.prev = float('-inf')
        self.ans = float('inf')
        dfs(root)
        return self.ans
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 为树中节点的个数。

* 空间复杂度：$O(H)$，其中 $H$ 为树的高度，其为递归调用 `dfs` 产生函数栈的大小。