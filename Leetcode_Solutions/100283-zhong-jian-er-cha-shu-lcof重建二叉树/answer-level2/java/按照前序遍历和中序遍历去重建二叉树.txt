**题解：**
二叉树的题，基本都离不开递归；
- 搞清楚，前序遍历和中序遍历的特点；
- 采用Map,存储中序遍历集合，获取对应数值及下标，便于重建时找到根节点在中序遍历集合中的位置；
- 根节点在是前序遍历集合的首个元素，获取在中序遍历中的位置，就可以得到左子树的大小；
- 将二叉树，分为 左子树和右子树递归重建；
- 递归的终止条件就是 preL>preR；
```java
class Solution {
    //中序遍历用来确定左右子树的容量，前序遍历可以获取根节点
    public Map<Integer,Integer> map = new HashMap<>();
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        for(int i=0;i<inorder.length;i++){
            map.put(inorder[i],i);
        }
        return reConstructBinaryTree(preorder,0,preorder.length-1,0);
    }

    public TreeNode  reConstructBinaryTree(int[] preorder,int preL,int preR,int inL){
        if(preL>preR){
            return null;
        }
        TreeNode root = new TreeNode(preorder[preL]);
        int index = map.get(root.val);
        int leftTreeSize = index -  inL;
        root.left = reConstructBinaryTree(preorder,preL+1,preL+leftTreeSize,inL);
        root.right = reConstructBinaryTree(preorder,preL+leftTreeSize+1,preR,inL+leftTreeSize+1);
        return root;
    }
}
```
