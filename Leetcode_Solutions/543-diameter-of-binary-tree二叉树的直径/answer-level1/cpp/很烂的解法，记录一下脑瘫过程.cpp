### 解题思路
遍历每一个结点，每遍历一个结点的时候，计算从该结点开始左右子树加起来的最长直径。
每遍历一个结点对全局Max更新。还没有做优化的版本
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
    int MAX_LENGTH=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        diameterOfBinaryTree_Helper1(root);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return MAX_LENGTH;

    }
    //此结点最大深度
    int diameterOfBinaryTree_Helper(TreeNode* root){
        if(root==nullptr) return 0;
        return  1+max(diameterOfBinaryTree_Helper(root->right),diameterOfBinaryTree_Helper(root->left))   ;
    }
    //计算一个结点为根的最大直径
    void diameterOfBinaryTree_Helper1(TreeNode* root){
        if(root==nullptr) return;
        int leftMaxLength=diameterOfBinaryTree_Helper(root->left);
        int rightMaxLength=diameterOfBinaryTree_Helper(root->right);
        int allLength=leftMaxLength+rightMaxLength;
        MAX_LENGTH=max(MAX_LENGTH,allLength);
    }
};
```