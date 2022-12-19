```
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
    private Map<TreeNode, TreeNode> pmap = new HashMap<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        dfs(root, null);
    
        return helper(root, target, K);
    }

    private List<Integer> helper(TreeNode root, TreeNode target, int k) {
        List<Integer> rlist = new LinkedList<>();
        if (root == null) return rlist;

        List<TreeNode> nodeList = new LinkedList<>();
        nodeList.add(target);
        int level = 0;
        Set<TreeNode> seenSet = new HashSet<>();
        while (!nodeList.isEmpty()) {
            int size = nodeList.size();
            List<Integer> ilist = new LinkedList<>();
            seenSet.add(target);
            for (int i = 0; i < size; i++) {
                TreeNode node = nodeList.remove(0);
                ilist.add(node.val);
                if (node.left != null && seenSet.add(node.left)) nodeList.add(node.left);
                if (node.right != null && seenSet.add(node.right)) nodeList.add(node.right);
                if (pmap.containsKey(node)&&seenSet.add(pmap.get(node))){
                    nodeList.add(pmap.get(node));
                }
            }
            if (++level==k+1) {
                rlist = new LinkedList<>(ilist);
            }else {
                ilist.clear();
            }
        }
        return rlist;

    }

    private void dfs(TreeNode node, TreeNode parent) {
        if (node == null) return;
        if (parent != null) {
            pmap.put(node, parent);
        }
        dfs(node.left, node);
        dfs(node.right, node);
    }
}
```