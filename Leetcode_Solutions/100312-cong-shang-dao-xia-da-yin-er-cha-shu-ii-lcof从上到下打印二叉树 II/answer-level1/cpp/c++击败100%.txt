### 解题思路
此处撰写解题思路
用一个结点来标记每层最后一个结点
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return { };
        vector<vector<int>> ret;
        vector<int> v;
        TreeNode* end=root;//指向每一层最后一个结点
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            if(temp==end)
            {
                end=q.back();//end指向下一层最后一个结点
                ret.push_back(v);
                v.clear();//一层输入完就清除
            }
        }
        return ret;
    }
};
```