### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //二叉树的前序遍历中的第一位一定是根节点
        if(preorder.size() == 0 || inorder.size() == 0) return NULL; //出口
        //找到根节点在中序遍历中的位置，中序遍历之前的节点都是左子树节点，之后都是右子树节点
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);  
    }

    TreeNode* build(vector<int>& preorder, int a1, int b1, vector<int>& inorder, int a2, int b2){
        TreeNode* root = new TreeNode(preorder[a1]);//创建当前的根节点
        int i = a2;
        while(inorder[i] != preorder[a1]) i++;//找到当前根节点在中序遍历中的位置i
        int left = i - a2;   //左子树的长度
        int right = b2 - i;  //右子树的长度
        if(left>0)root -> left = build(preorder, a1+1, a1+left, inorder, a2, i - 1);//对左子树递归
        if(right>0)root -> right = build(preorder, a1 + left+1, b1, inorder ,i + 1, b2);//对右子树递归
        return root;
    }
};
//递归法
```