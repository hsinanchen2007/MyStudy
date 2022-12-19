### 解题思路
二叉搜索的中序遍历是递增序列
中序遍历的同时，按序构建一个新的树，其左子节点为NULL 右子节点是当前节点的右节点

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
    TreeNode* convertBiNode(TreeNode* root) {
        //利用中序遍历把二叉搜索树设置为单向链表
        TreeNode* head=new TreeNode(-1);
        TreeNode* res=head;
        stack<TreeNode*>sk;
        while(!sk.empty()||root){
            while(root){
                sk.push(root);
                root=root->left;
            }
            root=sk.top();
            sk.pop();
             root->left=NULL;
            res->right=root;
            res=root;
            root=root->right;

        }
        return head->right;
    }
};
```