### 解题思路
1. 获得root到p、q节点的path；
2. 遍历两个路径，出现不同节点时即找到公共祖先

类似题目：[113路径总和](https://leetcode-cn.com/problems/path-sum-ii/submissions/)
这样做的出发点：1.把问题转化到之前解决过的问题；2.用一个思路解多个题目。

### 代码

```java []
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
   public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        List<List<TreeNode>> pPath = getPath(root, p, new LinkedList<>(), new ArrayList<>());
        List<List<TreeNode>> qPath = getPath(root, q, new LinkedList<>(), new ArrayList<>());
        return getAncestor(pPath.get(0), qPath.get(0));
    }
    //找路径
    public List<List<TreeNode>> getPath(TreeNode node, TreeNode p, LinkedList<TreeNode> path,List<List<TreeNode>> res) {
        if (node == null) return res;

        path.addLast(node);
        if (node.val == p.val) res.add(new ArrayList<>(path));
        getPath(node.left, p, path, res);
        getPath(node.right, p, path, res);
        path.removeLast();

        return res;
    }

    //遍历路径，找不同
    public TreeNode getAncestor(List<TreeNode> pPath, List<TreeNode> qPath) {
        int min = Math.min(pPath.size(), qPath.size());
        for (int i = 0; i < min; i++) {
            if (pPath.get(i).val == qPath.get(i).val) continue;
            return i > 0 ? pPath.get(i - 1) : pPath.get(0);
        }

        return pPath.get(min - 1);
    }
}
```

```C# []
    public class Solution 
    {
        public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) 
        {
            if (root == null) throw new Exception("Not Found");
            var pPath = GetPath(root, p, new LinkedList<TreeNode>(), new List<List<TreeNode>>());
            var qPath = GetPath(root, q, new LinkedList<TreeNode>(), new List<List<TreeNode>>());
            return GetAncestor(new List<TreeNode>(pPath[0]), new List<TreeNode>(qPath[0]));   
        }
        public List<List<TreeNode>> GetPath(TreeNode node, TreeNode p, LinkedList<TreeNode> path, List<List<TreeNode>> res)
        {
            if (node == null) return res;

            path.AddLast(node);
            if (node.val == p.val) res.Add(new List<TreeNode>(path));
            GetPath(node.left, p, path, res);
            GetPath(node.right, p, path, res);
            path.RemoveLast();

            return res;
        }

        public TreeNode GetAncestor(List<TreeNode> pPath, List<TreeNode> qPath)
        {
            int min = Math.Min(pPath.Count, qPath.Count);
            for (int i = 0; i < min; i++)
            {
                if (pPath[i].val == qPath[i].val) continue;
                return i > 0 ? pPath[i - 1] : pPath[0];
            }

            return pPath[min - 1];
        }
}

```