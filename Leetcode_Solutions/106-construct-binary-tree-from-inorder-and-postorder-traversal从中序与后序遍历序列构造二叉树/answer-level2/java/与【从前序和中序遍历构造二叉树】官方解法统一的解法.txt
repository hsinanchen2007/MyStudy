1. 前序遍历和中序遍历的官方解法：是根据前序遍历，从前往后i++前序序列，去中序里面分割左右子树。
2. 这里的解法就可以看成是从后往前i--，遍历后序序列，去中序序列分割左右子树，分割的时候，要先构造右子树，因为后序遍历（左右根），从i--，构造就是根右左。

```
class Solution { 
    int postorderIndex = 0;
    private Map<Integer,Integer> inorderMap;
    private int[] postorder;
    private int[] inorder;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(postorder.length==0 || inorder.length == 0){
            return null;
        }
        postorderIndex = postorder.length-1;
        this.inorderMap = new HashMap<>();
        for(int i = 0; i < inorder.length; i++){
            inorderMap.put(inorder[i],i);
        }
        this.postorder = postorder;
        this.inorder = inorder;
        return useInorderBuildTree(0, inorder.length); //右边界，传递长度，左闭右开 [ )
    }

    public TreeNode useInorderBuildTree(int left, int right){
        if(left==right ){
            return null; //相等 return null
        }
        TreeNode root = new TreeNode(postorder[postorderIndex]);
        int inorderIndex = inorderMap.get(postorder[postorderIndex]);
        postorderIndex--;

        root.right = useInorderBuildTree(inorderIndex+1, right); //先构造右子树（因为后序遍历是左右根）
        root.left = useInorderBuildTree(left, inorderIndex);
        return root;
    }
}
```