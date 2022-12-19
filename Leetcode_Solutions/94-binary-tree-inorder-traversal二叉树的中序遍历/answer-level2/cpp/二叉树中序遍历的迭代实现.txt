### 解题思路
每遇到一个节点就使用`goAlongLeftBranch()`函数找到该节点的左侧链的叶子节点，然后访问该节点，然后将访问权交给该叶子节点的右孩子。如此迭代进行最终会遍历整个树~

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> s;
        vector<int> v;
        int tem;
        while(true) {
            goAlongLeftBranch(root, s);
            if (s.empty())
                break;
            root = s[s.size() - 1];
            tem = root->val;
            s.pop_back();
            v.push_back(tem);
            root = root->right;
        }
        return v;
    }
    void goAlongLeftBranch(TreeNode* x, vector<TreeNode*>& s) {
        while(x){
            s.push_back(x);
            x = x->left;
        }
    }
};
```