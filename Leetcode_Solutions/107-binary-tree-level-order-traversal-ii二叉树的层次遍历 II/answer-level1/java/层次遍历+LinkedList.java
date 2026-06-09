与普通层次遍历的差别在于直接利用linkedlist特性插入到一开始的list

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> result = new LinkedList<>();
        if (root == null) return result;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty())
        {
            result.add(0,new ArrayList<>());
            int length = queue.size();
            for (int i =0;i< length;i++)
            {
                TreeNode node = queue.poll();
                result.get(0).add(node.val);
                if (node.left!= null) queue.offer(node.left);
                if (node.right!= null) queue.offer(node.right);
            }
        }
        return result;
    }
}