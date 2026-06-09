### 解题思路
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7




1. 后续遍历post， 左右中，   序列末尾就是根；    去掉根就是右了
2. 中序遍历in， 左中右，    从上面找到根后，根左边就是左子树，右边就是右子树。
3. 
4. 构建代码，inStart inEnd  postEnd, 根据inStart > inEnd 作为递归结束条件 
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode * helper(int* inorder,int *postorder,int inStart,int inEnd, int postEnd){
    int i = 0;

    if(inStart > inEnd)     //下面两个入参，instart 和inEnd是慢慢靠拢的，所以结束条件如此
        return NULL;

    struct TreeNode * T = malloc(sizeof(struct TreeNode));
    T->val = postorder[postEnd];
    
    for(i=inStart;i<=inEnd;i++){
        if(inorder[i] == T->val)
            break;
    }
//从左中后序列中找左， 左节点在 instart ~ (i - 1)中， 右节点可能的个数为inEnd - i  
//从左右中序列中找左， 得(end - 右的个数 - 1个中)，所以下一级postEnd = (postEnd - (inEnd - i) - 1)  
    T->left = helper(inorder,postorder,inStart,i-1,
                postEnd - (inEnd - i) - 1); 
//从左中右序列中找右， 根i右边就是，  i+1 ~ inEnd 
//从左右中序列中找右， 当前中-1， 即当前postEnd - 1 ， 就是右的end边界了
    T->right = helper(inorder,postorder,i+1,inEnd,
                postEnd - 1);
    return T;
}


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){

    return helper(inorder,postorder,0,inorderSize - 1,postorderSize -1);
}


```