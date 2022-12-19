#### 方法一：使用 HashSet【通过】

最简单的方法就是遍历整棵树，找出所有可能的组合，判断是否存在和为 $k$ 的一对节点。现在在此基础上做一些改进。

如果存在两个元素之和为 $k$，即 $x+y=k$，并且已知 $x$ 是树上一个节点的值，则只需判断树上是否存在一个值为 $y$ 的节点，使得 $y=k-x$。基于这种思想，在树的每个节点上遍历它的两棵子树（左子树和右子树），寻找另外一个匹配的数。在遍历过程中，将每个节点的值都放到一个 $set$ 中。

对于每个值为 $p$ 的节点，在 $set$ 中检查是否存在 $k-p$。如果存在，那么可以在该树上找到两个节点的和为 $k$；否则，将 $p$ 放入到 $set$ 中。

如果遍历完整棵树都没有找到一对节点和为 $k$，那么该树上不存在两个和为 $k$ 的节点。

```java [solution1-Java]
public class Solution {
    public boolean findTarget(TreeNode root, int k) {
        Set < Integer > set = new HashSet();
        return find(root, k, set);
    }
    public boolean find(TreeNode root, int k, Set < Integer > set) {
        if (root == null)
            return false;
        if (set.contains(k - root.val))
            return true;
        set.add(root.val);
        return find(root.left, k, set) || find(root.right, k, set);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $N$ 是节点的数量。最坏的情况下，整棵树被遍历一次。

* 空间复杂度：$O(n)$。最坏的情况下，$set$ 存储 $n$ 个节点的值。


#### 方法二：使用 BFS 和 HashSet【通过】

**算法**

本方法中，$set$ 的用途与 *方法一* 相同。但是本方法使用广度优先搜索遍历二叉树，这是一种非常常见的遍历方法。

使用广度优先搜索查找一对节点和为 $k$ 的过程如下。首先维护一个与 *方法一* 用途相同的 $set$。将根节点加入 $queue$，然后执行以下步骤：

1. 从队列首部删除一个元素 $p$。

2. 检查 $set$ 中是否存在 $k-p$。如果存在，返回 True。

3. 否则，将 $p$ 加入 $set$。然后将当前节点的左孩子和右孩子加入 $queue$。

4. 重复步骤一至三，直到 $queue$ 为空。

5. 如果 $queue$ 为空，返回 False。

按照以上步骤，逐层遍历二叉树。

```java [solution2-Java]
public class Solution {
    public boolean findTarget(TreeNode root, int k) {
        Set < Integer > set = new HashSet();
        Queue < TreeNode > queue = new LinkedList();
        queue.add(root);
        while (!queue.isEmpty()) {
            if (queue.peek() != null) {
                TreeNode node = queue.remove();
                if (set.contains(k - node.val))
                    return true;
                set.add(node.val);
                queue.add(node.right);
                queue.add(node.left);
            } else
                queue.remove();
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 是树中节点的数量。最坏的情况下，需要遍历整棵树。

* 空间复杂度：$O(n)$。最坏的情况下，$set$ 存储 $n$ 个节点的值。


#### 方法三：使用 BST【通过】

**算法**

在本方法中利用 BST 的性质，BST 的中序遍历结果是按升序排列的。因此，中序遍历给定的 BST，并将遍历结果存储到 $list$ 中。

遍历完成后，使用两个指针 $l$ 和 $r$ 作为 $list$ 的头部索引和尾部索引。然后执行以下操作：

1. 检查 $l$ 和 $r$ 索引处两元素之和是否等于 $k$。如果是，立即返回 True。

2. 如果当前两元素之和小于 $k$，则更新 $l$ 指向下一个元素。这是因为当我们需要增大两数之和时，应该增大较小数。

3. 如果当前两元素之和大于 $k$，则更新 $r$ 指向上一个元素。这是因为当我们需要减小两数之和时，应该减小较大数。

4. 重复步骤一至三，直到左指针 $l$ 大于右指针 $r$。

5. 如果左指针 $l$ 到右指针 $r$ 的右边，则返回 False。

注意，在任何情况下，都不应该增大较大的数，也不应该减小较小的数。这是因为如果当前两数之和大于 $k$，不应该首先增大 $list[r]$ 的值。类似的，也不应该首先减小 $list[l]$ 的值。

``` java [solution3-Java]
public class Solution {
    public boolean findTarget(TreeNode root, int k) {
        List < Integer > list = new ArrayList();
        inorder(root, list);
        int l = 0, r = list.size() - 1;
        while (l < r) {
            int sum = list.get(l) + list.get(r);
            if (sum == k)
                return true;
            if (sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
    public void inorder(TreeNode root, List < Integer > list) {
        if (root == null)
            return;
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 是树中节点的数量。本方法需要中序遍历整棵树。

* 空间复杂度：$O(n)$，$list$ 中存储 $n$ 个元素。