### 解题思路
从上到下，从左到右
BFS广度优先搜索 使用队列
根节点放入队列q
进行BFS循环
1. 取队首元素命名node，并且将其移除出队列pop
2. 将node->val 加入到res数组中
3. 依此将node非空的左节点 右节点放入队列中

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* node=q.front();
            q.pop();
            res.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return res;

    }
};
```