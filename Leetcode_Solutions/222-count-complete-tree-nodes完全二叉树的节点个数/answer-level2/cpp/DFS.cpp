### 解题思路
此处撰写解题思路

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
    void DFSGetNodes(TreeNode* root, int& nodes){
    	if(!root) return;
    	nodes++;
    	DFSGetNodes(root->left, nodes);
    	DFSGetNodes(root->right, nodes);
    }
    int countNodes(TreeNode* root){
    	int nodes = 0;
    	DFSGetNodes(root, nodes);
    	return nodes;
    }
};
```