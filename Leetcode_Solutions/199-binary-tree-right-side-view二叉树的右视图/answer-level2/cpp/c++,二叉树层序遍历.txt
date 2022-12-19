### 解题思路
此处撰写解题思路
广度优先遍历二叉树，每次取队列最后一个元素的值 
![截图.PNG](https://pic.leetcode-cn.com/21624cd921721dd99eac5a60fc973c588c5e15055bd821ec3c46903cdef9a3fb-%E6%88%AA%E5%9B%BE.PNG)

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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int len = q.size();
            int val;
            for(int i  = 0; i < len; i++){
                auto node = q.front();
                q.pop();
                val =node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            res.push_back(val);
        }
        return res;
    }
};
```