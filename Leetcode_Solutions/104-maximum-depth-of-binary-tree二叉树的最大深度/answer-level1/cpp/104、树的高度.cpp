### 解题思路
1、第一种是DFS，就是求左右子树的高度+1，用递归实现
2、第二种是按层遍历，BFS
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
#include <algorithm>
#include <queue>
class Solution {
private:
    queue<TreeNode*> q;
public:
    // DFS 方法
    // int maxDepth(TreeNode* root) {
    //     if(!root){
    //         return 0;
    //     }
    //     return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    // }
    // BFS
    int maxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int depth = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            depth++;
            for(int i=0;i<size;++i){
                TreeNode* temp = q.front();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
            }
        }
        return depth;
    }
};
```