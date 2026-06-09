### 解题思路
是之前那个求最深度叶子节点总和的其中一点，每用一次dfs探索，则deep深度加一，注意没有节点时深度为0，则设置maxDeepLength初始为0

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
    int maxDeepLength=0;
    void dfs(TreeNode *node,int deep){
        if(!node) return;
        if(deep>maxDeepLength){
            maxDeepLength=deep;
        }
        dfs(node->left,deep+1);
        dfs(node->right,deep+1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root,1);
        return maxDeepLength;
    }
};
```