#### 方法一：深度优先搜索【通过】

**思路**

序列化二叉树。

```python [snippet1-Python]
   1
  / \
 2   3
    / \
   4   5
```

例如上面这棵树序列化结果为 `1,2,#,#,3,4,#,#,5,#,#`。每棵不同子树的序列化结果都是唯一的。


**算法**

使用深度优先搜索，其中递归函数返回当前子树的序列化结果。把每个节点开始的子树序列化结果保存在 $map$ 中，然后判断是否存在重复的子树。

```python [solution1-Python]
class Solution(object):
    def findDuplicateSubtrees(self, root):
        count = collections.Counter()
        ans = []
        def collect(node):
            if not node: return "#"
            serial = "{},{},{}".format(node.val, collect(node.left), collect(node.right))
            count[serial] += 1
            if count[serial] == 2:
                ans.append(node)
            return serial

        collect(root)
        return ans
```

```java [solution1-Java]
class Solution {
    Map<String, Integer> count;
    List<TreeNode> ans;
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        count = new HashMap();
        ans = new ArrayList();
        collect(root);
        return ans;
    }

    public String collect(TreeNode node) {
        if (node == null) return "#";
        String serial = node.val + "," + collect(node.left) + "," + collect(node.right);
        count.put(serial, count.getOrDefault(serial, 0) + 1);
        if (count.get(serial) == 2)
            ans.add(node);
        return serial;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是二叉树上节点的数量。遍历所有节点，在每个节点处序列化需要时间 $O(N)$。

* 空间复杂度：$O(N^2)$，`count` 的大小。


#### 方法二：唯一标识符【通过】

**思路**

假设每棵子树都有一个唯一标识符：只有当两个子树的 id 相同时，认为这两个子树是相同的。

一个节点 `node` 的左孩子 id 为 `x`，右孩子 id 为 `y`，那么该节点的 id 为 `(node.val, x, y)`。

**算法**

如果三元组 `(node.val, x, y)` 第一次出现，则创建一个这样的三元组记录该子树。如果已经出现过，则直接使用该子树对应的 id。

```python [solution2-Python]
class Solution(object):
    def findDuplicateSubtrees(self, root):
        trees = collections.defaultdict()
        trees.default_factory = trees.__len__
        count = collections.Counter()
        ans = []
        def lookup(node):
            if node:
                uid = trees[node.val, lookup(node.left), lookup(node.right)]
                count[uid] += 1
                if count[uid] == 2:
                    ans.append(node)
                return uid

        lookup(root)
        return ans
```

```java [solution2-Java]
class Solution {
    int t;
    Map<String, Integer> trees;
    Map<Integer, Integer> count;
    List<TreeNode> ans;

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        t = 1;
        trees = new HashMap();
        count = new HashMap();
        ans = new ArrayList();
        lookup(root);
        return ans;
    }

    public int lookup(TreeNode node) {
        if (node == null) return 0;
        String serial = node.val + "," + lookup(node.left) + "," + lookup(node.right);
        int uid = trees.computeIfAbsent(serial, x-> t++);
        count.put(uid, count.getOrDefault(uid, 0) + 1);
        if (count.get(uid) == 2)
            ans.add(node);
        return uid;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 二叉树上节点的数量，每个节点都需要访问一次。

* 空间复杂度：$O(N)$，每棵子树的存储空间都为 $O(1)$。