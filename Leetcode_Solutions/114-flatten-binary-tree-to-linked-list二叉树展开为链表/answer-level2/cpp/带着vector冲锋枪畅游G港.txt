### 解题思路
此处撰写解题思路
使用前序遍历，将每一个节点按顺序放入vector中，再建立链表即可
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
    void flatten(TreeNode* root) {
        vector<int> num;
        inorder(root,num);
        if(!root) return;
        root->left=nullptr;
        for(int i=1;i<num.size();i++){
            TreeNode *new_node=new TreeNode(num[i]);
            root->right=new_node;
            root=root->right;
        }

        
    }
    void inorder(TreeNode *root,vector<int> &num){
        if(root==nullptr) return ;
        num.push_back(root->val);
        inorder(root->left,num);
        inorder(root->right,num);
    }
};
```