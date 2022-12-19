### 解题思路
在中序遍历的时候把结点的值放进数组里面,数组里面的值就是有序的.

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
    vector<int> v;
    int ans = 101;
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        for (int i = 0; i < v.size()-1; i++)
            ans = min(ans, v[i+1] - v[i]);
        
        return ans;
    }
    
    void inOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left);
        v.push_back(node->val);
        inOrder(node->right);
    }
};
```