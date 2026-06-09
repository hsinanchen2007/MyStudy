某个节点如果偷的话，那么它的左孩子节点和右孩子节点都不能被偷，但左孩子和右孩子的子节点可以偷。
那么就分两种情况，1、偷根节点和四个它的孩子的孩子节点，2、根节点不偷，偷两个孩子节点。
即 dp=max{root.val+rob(root.left.left)+rob(root.left.right)+rob(root.right.left)+rob(root.right.right) 
   ,     rob(root.left)+rob(root.right)},当然要提前判断root和root.left,root.right是否为空。
```
class Solution {
    HashMap<TreeNode,Integer> map=new HashMap();
    public int rob(TreeNode root) {
        if(root==null)
            return 0;
        if(map.containsKey(root))
            return map.get(root);
        int max=root.val
            +(root.left==null?0:rob(root.left.left)+rob(root.left.right))
            +(root.right==null?0:rob(root.right.left)+rob(root.right.right));
        max=Math.max(rob(root.left)+rob(root.right),max);
        map.put(root,max);
        return max;
    }
}
```
