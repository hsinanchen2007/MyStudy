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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder == null || preorder.length == 0 || inorder == null || inorder.length == 0) return null;
        return createBinarySearchTreeByPreIn(preorder,inorder,0,preorder.length-1,0,inorder.length-1);
    }

    /**
 *
 * 根据先根和中根遍历算法构造二叉树
 * @param preList 先根遍历次序数组
 * @param inList 中根遍历次序数组
 * @param preStart
 * @param preEnd
 * @param inStart
 * @param inEnd
 * return root 最终返回的根结点
 */
public TreeNode  createBinarySearchTreeByPreIn(int[] preList , int[] inList,int preStart ,int preEnd ,int inStart ,int inEnd){
    //preList[preStart]必须根结点数据,创建根结点root
    TreeNode p=new TreeNode(preList[preStart]);
    //如果没有其他元素,就说明结点已构建完成
    if (preStart == preEnd && inStart == inEnd) {
        return p;
    }
    //找出中根次序的根结点下标root
    int root=0;

    for (root = inStart; root < inEnd; root++) {
            //如果中根次序中的元素值与先根次序的根结点相当,则该下标index即为inList中的根结点下标
            if (preList[preStart] == inList[root]){
                break;
            }
    }

    //获取左子树的长度
    int leftLength=root-inStart;
    //获取右子树的长度
    int rightLength=inEnd-root;

    //递归构建左子树
    if(leftLength>0){
        //左子树的先根序列：preList[1] , ... , preList[i]
        //左子树的中根序列：inList[0] , ... , inList[i-1]
        p.left=createBinarySearchTreeByPreIn(preList,inList,preStart+1,preStart+leftLength,inStart,root-1);
    }

    //构建右子树
    if (rightLength>0){
        //右子树的先根序列：preList[i+1] , ... , preList[n-1]
        //右子树的中根序列：inList[i+1] , ... , inList[n-1]
        p.right=createBinarySearchTreeByPreIn(preList,inList,preStart+leftLength+1,preEnd,root+1,inEnd);
    }

    return p;
}

}
```
