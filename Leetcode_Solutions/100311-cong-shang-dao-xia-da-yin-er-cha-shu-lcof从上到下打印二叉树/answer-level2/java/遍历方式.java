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
    public int[] levelOrder(TreeNode root) {
        if (root==null) return new int[0];
        LinkedList<TreeNode> list = new LinkedList<>();
        ArrayList<Integer> arrayList = new ArrayList<>();
        list.add(root);
        while(!list.isEmpty()){
            arrayList.add(help(list));
        }
        int[] result=new int[arrayList.size()];
        for(int i=0;i<arrayList.size();i++)
            result[i]=arrayList.get(i);
        return result;
    }
    public static int help(LinkedList<TreeNode> list){
        TreeNode root=list.pop();
        if(root.left!=null) list.add(root.left);
        if(root.right!=null) list.add(root.right);
        return root.val;
    }
}
```
