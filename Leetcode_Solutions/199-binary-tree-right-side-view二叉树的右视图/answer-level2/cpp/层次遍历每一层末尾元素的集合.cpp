### 解题思路
执行用时 :12 ms, 在所有 C++ 提交中击败了42.24% 的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了5.11%的用户

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
	vector<vector<int>> LevelOrderRightSideView(TreeNode* root){
		vector<vector<int>> level_order_nodes;
        if(!root) return level_order_nodes;
		vector<int> curr_row_nodes = {root->val};
		level_order_nodes.push_back(curr_row_nodes);
		list<TreeNode*> list_nodes;
		list_nodes.push_back(root);
		int list_size = list_nodes.size(); //1
		while(list_size){

			if(root->left){
				list_nodes.push_back(root->left);
			}
			if(root->right){
				list_nodes.push_back(root->right);
			}
			list_nodes.pop_front();
			root = list_nodes.front();
			list_size--;

			if(!list_size && list_nodes.size()){
				vector<int> curr_row_nodes;
				for(auto& iter:list_nodes){
					curr_row_nodes.push_back(iter->val);
				}
				level_order_nodes.push_back(curr_row_nodes);
				list_size = list_nodes.size();
			}
		}
		return level_order_nodes;
	}
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> right_side_view_nodes;
    	vector<vector<int>> level_order_nodes = LevelOrderRightSideView(root);
    	for(auto& iter:level_order_nodes){
    		right_side_view_nodes.push_back(iter[iter.size()-1]);
    	}

    	return right_side_view_nodes;
    }
};
```