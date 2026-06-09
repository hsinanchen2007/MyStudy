### 解题思路
此处撰写解题思路
队列层次遍历，判断每层是否是回文
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
    bool isSymmetric(TreeNode* root) {
        if (NULL == root)
            return true;

        queue<TreeNode*> que;
        vector<int> vec;
        que.push(root);
        while (!que.empty())
        {
            int l = que.size();
            for (int i=0; i<l; i++)//层次遍历
            {
                TreeNode* node = que.front();
                que.pop();
                if (node->left != NULL) {que.push(node->left); vec.push_back(node->left->val);}
                else vec.push_back(-1);
                if (node->right != NULL) {que.push(node->right); vec.push_back(node->right->val);}
                else vec.push_back(-1);
            }
            for (int i=0; i<(int)vec.size()/2; i++)//判断回文
                if (vec[i] != vec[vec.size()-i-1])
                    return false;
            vec.clear();
        }
        return true;
    }
};
```