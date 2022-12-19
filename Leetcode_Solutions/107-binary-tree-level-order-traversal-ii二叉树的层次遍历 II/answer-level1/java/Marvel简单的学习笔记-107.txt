### 解法一：BFS
常规的层序遍历稍加修改。一次把同一层的顶点全取出来，并把属于下一层的所有顶点一次性入队。然后每次都将subList插入到res的开头。
具体做法：把根结点入队，此时队列的大小为1，表示当前层含有的结点数也为1，这是显然的，然后将子结点入列后进入下一轮循环。此后，每一层的结点数都可以用队列的大小来表示，这样就做到了一次把整层的结点都处理了，将它们全部出列，并将它们的子结点入列，使得此时队列里含有的顶点都是下一层的顶点。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：
```java
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> res = new LinkedList<>();
        if(root == null)    return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            LinkedList<Integer> subList = new LinkedList<>();
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode cur = q.poll();
                subList.offer(cur.val);
                if(cur.left != null)    q.offer(cur.left);
                if(cur.right != null)   q.offer(cur.right);
            }
            res.offerFirst(subList);
        }
        return res;
    }
}
```

### 解法二：DFS
DFS递归遍历，但是多使用一个形参，记录当前层号。
如果子列表的数量小于层数，说明第一次到达该层，为结果添加一个子列表。注意为了实现自底向上输出，每次都将子列表添加到结果的开头。
子列表的下标对应的是自底向上遍历时结点所在的层号，即0对应最后一层。
然后对遍历到的顶点，将其添加到所在层号对应的子列表中即可。

```java
class Solution {
    private LinkedList<List<Integer>> ans;
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        ans = new LinkedList<>();
        getOrder(root, 1);
        return ans;
    }
    private void getOrder(TreeNode root, int level) {
        if(root == null)    return;
        if(ans.size() < level)
            ans.addFirst(new LinkedList<Integer>());
        List<Integer> subList = ans.get(ans.size() - level);
        subList.add(root.val);
        getOrder(root.left, level + 1);
        getOrder(root.right, level + 1);
    }
}
```