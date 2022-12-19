### 解题思路
算法 BFS
难点 因为需要逐层锯齿输出，所以需要利用额外的结构来记录层数（level）， 参考@ZAZA 的 写法

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
class TreeNodeWithLevel {
public:
    TreeNode* node;
    int level;
    TreeNodeWithLevel(TreeNode* node, int level): node(node), level(level) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // pre judge (special case)
        vector<vector<int>> ret;
        if (root == NULL) return ret;

        // init data
        queue<TreeNodeWithLevel*> helper;
        TreeNodeWithLevel *node = new TreeNodeWithLevel(root, 0);

        helper.push(node);
        
        // first bfs
        int level = 0;
        while(!helper.empty()){
            TreeNodeWithLevel* node = helper.front();
            level = node->level;
            helper.pop();
            if (level >= ret.size()){
                vector<int> temp = {node->node->val};
                ret.push_back(temp);
                if ((level-1)%2 == 1){
                    reverse(ret[level-1].begin(),ret[level-1].end());
                }
            }else{
                ret[level].push_back(node->node->val);
            }
            if (node->node->left != NULL) {
                TreeNodeWithLevel* left = new TreeNodeWithLevel(node->node->left, level+1);
                helper.push(left);
            }
            if (node->node->right != NULL){
                TreeNodeWithLevel* right = new TreeNodeWithLevel(node->node->right, level+1);
                helper.push(right);
            } 
        }
        if ((level)%2 == 1){
            reverse(ret[level].begin(),ret[level].end());
        }
        return ret;

    }
};
```