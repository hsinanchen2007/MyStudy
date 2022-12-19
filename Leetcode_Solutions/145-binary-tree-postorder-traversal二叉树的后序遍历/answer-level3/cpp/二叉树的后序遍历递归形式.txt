### 解题思路
递归实现

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
    vector<int> postorderTraversal(TreeNode* root) {
        //后序遍历递归形式
        vector<int> v;
        postorder(root,v);
        return v;
    }
private:
    void postorder(TreeNode* root,vector<int> &v){
        if(root!=NULL){
            postorder(root->left,v);
            postorder(root->right,v);
            v.push_back(root->val);
        }
    }
};
```