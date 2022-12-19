## DFS、BFS遍历树
### 解法一：BFS
层序遍历，借助队列，每次都处理整层的结点。
从根结点开始入列，只要队列不空，每次循环都先记录队列中结点的数目，然后仅对这些数目的结点进行出列，再将它们的子结点入列。这样一来，此时队列中的结点都是下一层的结点了。如此这般，使得每次循环处理的都是同一层的结点，以层为单元，将节点添加到子列表中，然后将子列表添加到结果中。

时间复杂度：$O(n)$。
空间复杂度：$O(n)$。

代码：
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if(root == null)    return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            List<Integer> subList = new LinkedList<>();
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode cur = q.poll();
                subList.add(cur.val);
                if(cur.left != null)    q.offer(cur.left);
                if(cur.right != null)   q.offer(cur.right);
            }
            res.add(subList);
        }
        return res;
    }
}
```

### 解法二：DFS
DFS递归遍历，但是多使用一个形参，记录当前层号。
如果子列表的数量小于层数，说明第一次到达该层，为结果res添加一个子列表。
子列表在res中的下标对应的是结点所在的层号，即0对应第一层。
然后对遍历到的顶点，将其添加到所在层号对应的子列表中即可。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：
```java
class Solution {
    private List<List<Integer>> res;
    public List<List<Integer>> levelOrder(TreeNode root) {
        res = new LinkedList<>();
        getOrder(root, 1);
        return res;
    }
    private void getOrder(TreeNode root, int layer) {
        if(root == null)    return;
        if(res.size() < layer)
            res.add(new LinkedList<Integer>());
        List<Integer> sub = res.get(layer - 1);
        sub.add(root.val);
        getOrder(root.left, layer + 1);
        getOrder(root.right, layer + 1);
    }
}
```