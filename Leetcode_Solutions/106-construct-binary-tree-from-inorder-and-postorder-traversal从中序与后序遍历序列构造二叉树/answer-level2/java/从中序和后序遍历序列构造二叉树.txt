学习了一下105的官方题解
```java
class Solution {
    HashMap<Integer,Integer> idx_map = new HashMap<Integer,Integer>();
    int[] postorder;
    int[] inorder;
    int pre_idx;
    public TreeNode helper(int in_left, int in_right) {
        if (in_left == in_right)
            return null;
        int root_val = postorder[pre_idx-1]; // 后序遍历从后往前
        pre_idx --;
        int index = idx_map.get(root_val); 
        TreeNode root = new TreeNode(root_val); //新建一个根节点
        root.right = helper(index + 1, in_right); // 从右往左
        root.left = helper(in_left, index);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.inorder = inorder;
        this.postorder = postorder;
        int idx = 0;
        for(int i:inorder) {
            idx_map.put(i,idx++);
        }
        pre_idx = postorder.length;
        return helper(0,inorder.length);
    }
}
```