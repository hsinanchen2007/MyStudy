### 解题思路
当栈不为空时，先记录当前栈的大小size，再依次将各自左右结点压栈，将size个元素出栈作为一行存到结果数组中。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)  return {};
        vector<vector<int>> level;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            vector<int> oneLevel;
            int size = q.size();
            while(size--){
                TreeNode* nowNode = q.front();
                if(nowNode->left != NULL){
                    q.push(nowNode->left);
                }
                if(nowNode->right != NULL){
                    q.push(nowNode->right);
                }
                oneLevel.push_back(nowNode->val);
                q.pop();
            }
            level.push_back(oneLevel);
        }
        return level;
    }
};




```