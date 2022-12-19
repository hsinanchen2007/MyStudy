### 解题思路
递归求解
这里要注意的是输出为vector，所以在给定的框架内进行解题是不合适的，需要另开一个function。用引用传递就可以方便地对vector进行操作了

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
private:
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;       
        inorderTraversal_core(root, re);
        return re;
    }
    void inorderTraversal_core(TreeNode* root, vector<int> & re) {
         if (root) {
            inorderTraversal_core(root->left, re);
            re.push_back(root->val);
            inorderTraversal_core(root->right, re);
        }       
    }
};
```