### 解题思路
感觉思路没问题，但不知道为什么效率不高。。。执行用时击败22.93%
DFS框架思路：
1、从根节点开始加和，一直加到叶子节点再开始判断总和是否满足。

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
    vector<vector<int>> re;
    int S=0;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root==NULL) return re;
        S=sum;
        vector<int> path;
        DFS(root, 0, path);
        return re;
    }
    void DFS(TreeNode* root, int sum, vector<int> path){
        if (root==NULL) return;
        if (sum+root->val == S){
            path.push_back(root->val);
            if (root->left == NULL && root->right == NULL){
                re.push_back(path);//总和满足&&是叶子结点，才进入结果
                return;
            }
        }
        else path.push_back(root->val);
        DFS(root->left, sum+root->val, path);
        DFS(root->right, sum+root->val, path);
        return;
    }
};
```