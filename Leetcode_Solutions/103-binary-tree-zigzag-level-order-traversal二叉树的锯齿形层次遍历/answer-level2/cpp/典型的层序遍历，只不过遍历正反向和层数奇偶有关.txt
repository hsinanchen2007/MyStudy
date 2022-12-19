### 解题思路

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
在真实的面试中遇到过这道题？


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        TreeNode* cur = root;
        Q.push(cur);
        int level = 0;
        while(!Q.empty()){
            vector<int> subRes;
            for(int i = Q.size()-1;i>=0;--i){
                cur = Q.front();
                Q.pop();
                subRes.push_back(cur->val);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                
            }
            if(level%2) reverse(subRes.begin(),subRes.end());
            res.push_back(subRes);
            level++;
        }
    return res;
    }
};
```