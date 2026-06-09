使用中序遍历就能使二叉排序树从小到大进行排序,然后取出第K个数
```java []
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        List<TreeNode> list  = new ArrayList<TreeNode>();
        KthNode(root, list);
        TreeNode result =list.get(k -1);
        return result.val;
    }
    
    private void KthNode(TreeNode root, List<TreeNode> list){
        if(root == null){
            return;
        }
        KthNode(root.left, list);
        list.add(root);
        KthNode(root.right, list);
    }
}