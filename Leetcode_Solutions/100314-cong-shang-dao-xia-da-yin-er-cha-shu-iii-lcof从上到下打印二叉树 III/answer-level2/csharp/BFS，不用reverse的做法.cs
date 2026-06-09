BFS的时候由于前一次是反向遍历，所以所有child nodes也是反向加入list的。
下一轮遍历时就不需要reverse，只要直接反向遍历就行了。
但是是先add left还是先add right还是要区分。所以传一个参数leftFirst。
少了reverse效率肯定是要高很多的。

```
public class Solution {
    List<IList<int>> result = new List<IList<int>>();
    void Helper(List<TreeNode> nodes, bool leftFirst) {
        var list = new List<TreeNode>();
        var ret = new List<int>();
        for (int i = nodes.Count - 1; i >= 0; i--) {
            ret.Add(nodes[i].val);
            if (leftFirst) {
                if (nodes[i].left != null) list.Add(nodes[i].left);
                if (nodes[i].right != null) list.Add(nodes[i].right);
            } else {
                if (nodes[i].right != null) list.Add(nodes[i].right);
                if (nodes[i].left != null) list.Add(nodes[i].left);
            }
        }
        if (ret.Count > 0) result.Add(ret);
        if (list.Count > 0) Helper(list, !leftFirst);
    }

    public IList<IList<int>> LevelOrder(TreeNode root) {
        if (root == null) return new List<IList<int>>();
        var l = new List<TreeNode>();
        l.Add(root);
        Helper(l, true);
        return result;
    }
}
```
