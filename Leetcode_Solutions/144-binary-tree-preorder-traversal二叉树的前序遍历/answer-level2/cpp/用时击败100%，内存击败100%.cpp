### 执行结果
![image.png](https://pic.leetcode-cn.com/8046ea8d0232896969bf68d162ddd67ae4ce5e1b4f0425ac451b2a19f090a3f0-image.png)


### 解题思路
1、子树递归

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root,res);
   
        return res;
    }
    void preOrder(TreeNode* root,vector<int>& res){
        if(root==NULL) return;
        res.emplace_back(root->val);
        preOrder(root->left,res);
        preOrder(root->right,res);
    }
};


```