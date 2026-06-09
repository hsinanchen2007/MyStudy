### 解题思路
1. 首先查找出两个节点的所有祖先，用List保存
2. 从两个List中的第一个元素开始往后比较，第一个不相同的就是祖先节点

### 代码

```java
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
        if (p.val == root.val)
            return p;
        if (q.val == root.val)
            return q;
        List<TreeNode> list_p = findAncestor(root, p, new ArrayList<>());
        list_p.add(p);
        List<TreeNode> list_q = findAncestor(root, q, new ArrayList<>());
        list_q.add(q);
        int i = list_p.size();
        int j = list_q.size();
        TreeNode res = new TreeNode(-1);
        while (i-- != 0 && j-- != 0){
            TreeNode temp1 = list_p.remove(0);
            TreeNode temp2 = list_q.remove(0);
            if (temp1.val == temp2.val)
                res = temp1;
            else
                break;
        }

        return res;
    }

    private List<TreeNode> findAncestor(TreeNode root,TreeNode target,List<TreeNode> list){
        if (root == null)
            return null;
        if (root.val == target.val){
            return list;
        }
        list.add(root);
        List<TreeNode> ancestors1 = findAncestor(root.left, target, list);
        if (ancestors1 != null)
            return ancestors1;
        List<TreeNode> ancestors2 = findAncestor(root.right, target, list);
        if (ancestors2 != null)
            return ancestors2;
        list.remove(list.size()-1);
        return null;
    }
}
```