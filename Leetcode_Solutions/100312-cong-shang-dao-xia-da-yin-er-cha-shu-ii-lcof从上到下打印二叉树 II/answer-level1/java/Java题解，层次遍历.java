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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        if(root==null) return res;
        LinkedList<TreeNode> li = new LinkedList<TreeNode>(); // 存储每一层需要遍历的元素
        li.add(root);
        while(!li.isEmpty()){
            LinkedList<Integer> tmp = new LinkedList<Integer>();
            int len = li.size();
            while(len>0){
                TreeNode treeNode = li.getFirst();
                tmp.add(treeNode.val); // 把当前遍历的层元素存储在一起
                if(treeNode.left!=null){
                    li.addLast(treeNode.left);
                } 
                if(treeNode.right!=null){
                    li.addLast(treeNode.right);
                } 
                li.removeFirst();
                len--;
            }
            res.add(tmp);
        }
        return res;
    }
}