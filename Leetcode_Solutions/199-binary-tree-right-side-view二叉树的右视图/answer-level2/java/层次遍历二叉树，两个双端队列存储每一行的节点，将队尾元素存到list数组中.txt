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
    public List<Integer> rightSideView(TreeNode root) {
        Deque<TreeNode> deque1=new LinkedList<>();
        Deque<TreeNode> deque2=new LinkedList<>();
        List<Integer> list=new ArrayList<>();
        if (root==null){
            return list;
        }
        int even_odd=1;
        deque1.add(root);
        while (!deque1.isEmpty()||!deque2.isEmpty()){
            if (even_odd==1){
                list.add(deque1.getLast().val);
                while (!deque1.isEmpty()){
                    TreeNode node=deque1.pollFirst();
                    if (node.left!=null){
                        deque2.addLast(node.left);
                    }
                    if (node.right!=null){
                        deque2.addLast(node.right);
                    }
                }
                even_odd=1-even_odd;
            }else {
                list.add(deque2.getLast().val);
                while (!deque2.isEmpty()){
                    TreeNode node=deque2.pollFirst();
                    if (node.left!=null){
                        deque1.addLast(node.left);
                    }
                    if (node.right!=null){
                        deque1.addLast(node.right);
                    }
                }
                even_odd=1-even_odd;
            }
        }
        return list;
    }
}
```
