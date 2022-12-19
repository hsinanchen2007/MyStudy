### 解题思路
1. 通过深度优先搜索将树中所有的节点的值加入优先队列（默认大顶堆）中
2. 弹出优先队列中前k-1个元素，然后对首元素即为所求

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
    priority_queue<int> pq;
    void dfs(TreeNode* root){
        pq.push(root->val);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};
```