### 解题思路
第一种方法队列保存一个节点。res值+1

第二种方法使用一个level变量。统计层数。没写出来。
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

    // 执行用时 :40 ms, 在所有 C++ 提交中击败了73.16% 的用户
    // 内存消耗 :31.8 MB, 在所有 C++ 提交中击败了5.62%的用户
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        if(!root->left&&!root->right) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ++res;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return res;
    }

    
};
```