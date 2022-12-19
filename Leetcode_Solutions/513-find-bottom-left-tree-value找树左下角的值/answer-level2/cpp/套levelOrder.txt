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
	vector<vector<int>> findBottomLeftValueCore(TreeNode* root){ // levelOrder Helper function
		vector<vector<int>> level_order_nodes;
		if(!root) return level_order_nodes;

		vector<int> cur_level_nodes(1, root->val);
		if(!root->left && !root->right){
			level_order_nodes.push_back(cur_level_nodes);
			return level_order_nodes;
		}

		list<TreeNode*> list_nodes;
		list_nodes.push_back(root);
		size_t size = list_nodes.size();

		while(size){
			if(root->left){
				list_nodes.push_back(root->left);
			}
			if(root->right){
				list_nodes.push_back(root->right);
			}
			list_nodes.pop_front();
			root = list_nodes.front();
			size--;

			if(!size && root){
				cur_level_nodes.clear();
				for(auto& iter:list_nodes){
					cur_level_nodes.push_back(iter->val);
				}
				level_order_nodes.push_back(cur_level_nodes);
				size = list_nodes.size();
			}
		}

		return level_order_nodes;
	}
    int findBottomLeftValue(TreeNode* root) {
    	vector<vector<int>> level_order_nodes = findBottomLeftValueCore(root);
    	return level_order_nodes[level_order_nodes.size()-1][0];
    }
};
```