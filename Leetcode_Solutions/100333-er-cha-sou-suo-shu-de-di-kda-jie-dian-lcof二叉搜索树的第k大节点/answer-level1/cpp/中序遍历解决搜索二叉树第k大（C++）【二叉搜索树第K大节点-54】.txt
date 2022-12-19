### 解题思路
- 首先思考，二叉搜索树的中序遍历是有序的；
- 将二叉树的中序遍历存入数组；
- 然后取出第K大即可
- 注意从后开始取！因为中序遍历后数组递增。

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
    vector<int> ans;
public:
    int kthLargest(TreeNode* root, int k) {
        inTraverse(root);
        int index=ans.size()-k;
        return ans[index];
        
    }

    void inTraverse(TreeNode *root){
        if(root==NULL)  return;
        inTraverse(root->left);
        ans.push_back(root->val);
        inTraverse(root->right);
    }
};
```