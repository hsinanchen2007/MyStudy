
```
class Solution {
    
    public int kthSmallest(TreeNode root, int k) {
        LinkedList<TreeNode> list = new LinkedList<>();
        TreeNode current = root;
        TreeNode ans = null;
        while(k-->0){
            while(current!=null){
                list.addLast(current);
                current = current.left;
            }
            ans = list.removeLast();
            current = ans.right;
        }
        return ans.val;
    }
}
```
以上