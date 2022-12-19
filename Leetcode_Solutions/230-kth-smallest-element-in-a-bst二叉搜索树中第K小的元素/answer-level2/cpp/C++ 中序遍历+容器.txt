### 解题思路
利用二叉树中序遍历,因为这题中序遍历符合升序规律

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
 /*中序遍历,因为这题中序遍历符合由小到大的规律*/
class Solution {
public:
    void traversalTree(TreeNode* root, vector<int>& res) {
        if(root != NULL){
            traversalTree(root->left, res);
            res.push_back(root->val);
            traversalTree(root->right, res);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        traversalTree(root, res);
        return res[k-1];
    }
};

```
![image.png](https://pic.leetcode-cn.com/f1385d9156d8183128457854bce56e178e682c882d2d8bf03afa8d0415cce2f9-image.png)
