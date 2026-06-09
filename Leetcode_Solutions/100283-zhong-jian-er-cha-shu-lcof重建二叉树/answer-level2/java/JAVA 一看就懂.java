```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0) return null;
        TreeNode root = new TreeNode(preorder[0]);
        List<Integer> list_inorder = Arrays.stream(inorder).boxed().collect(Collectors.toList()); 
        buildNext(preorder, inorder, list_inorder, 0, preorder.length-1, 0, preorder.length-1, root);
        return root;
    }

    void buildNext(int[] preorder, int[] inorder, List<Integer> list_inorder, int pi, int pj, int oi, int oj, TreeNode root){
        if(pi>=pj) return;
        int index = list_inorder.indexOf(preorder[pi]);
        if(index> oi){
            TreeNode left = new TreeNode(preorder[pi+1]);
            root.left = left;
            buildNext(preorder,inorder, list_inorder, pi+1,pi+(index-oi),oi,index-1, left);
        }
        if(index<oj){
            TreeNode right = new TreeNode(preorder[pi+(index-oi)+1]);
            root.right = right;
            buildNext(preorder,inorder, list_inorder, pi+(index-oi)+1,pj,index+1,oj, right);
        }
    }
}
```
