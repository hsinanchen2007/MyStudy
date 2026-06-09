### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了93.01% 的用户
内存消耗 :14.5 MB, 在所有 C++ 提交中击败了24.03%的用户

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
	vector<vector<int>> levelOrder(TreeNode* root){
		vector<vector<int>> nodes_all_level;
		if(!root) return nodes_all_level;	
        
        list<TreeNode*> _list;
		_list.push_front(root);
		int this_level_size = _list.size();

		// to push the root of the whole tree
		vector<int> nodes_this_level;
		nodes_this_level.push_back(root->val);
		nodes_all_level.push_back(nodes_this_level);

		while(_list.size()){
			this_level_size--;

			if(root->left){
				_list.push_back(root->left);
			}
			if(root->right){
				_list.push_back(root->right);
			}

			_list.pop_front();
			root = _list.front();

			vector<int> nodes_this_level;
			if(!this_level_size && _list.size()){
				for(auto& iter:_list){
					nodes_this_level.push_back(iter->val);
				}
				nodes_all_level.push_back(nodes_this_level);
				this_level_size = _list.size();
				//cout << "updated this_level_size = " << this_level_size << endl;
			}
		}
		return nodes_all_level;
	}
};
```