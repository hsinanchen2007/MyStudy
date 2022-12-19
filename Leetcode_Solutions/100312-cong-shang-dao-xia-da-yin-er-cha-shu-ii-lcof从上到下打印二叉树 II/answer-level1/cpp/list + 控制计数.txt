### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :14.2 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    	vector<vector<int>> nodes_levelorder;
    	if(!root) return nodes_levelorder;

    	list<TreeNode*> _list;
    	_list.push_back(root);
    	vector<int> this_level_nodes;
    	this_level_nodes.push_back(root->val);
    	nodes_levelorder.push_back(this_level_nodes);

    	int level_size = _list.size();
    	while(_list.size()){
    		if(root->left){
    			_list.push_back(root->left);
    		}
    		if(root->right){
    			_list.push_back(root->right);
    		}

    		level_size--;
    		_list.pop_front();
    		root = _list.front();
    		//for debug
//    		cout << "level_size-- = " << level_size << endl;
    		//TraverseTreeNodeList(_list);
    		if(!level_size && _list.size()){
    			this_level_nodes.clear();
    			for(auto& iter:_list){
    				this_level_nodes.push_back(iter->val);
    			}
    			nodes_levelorder.push_back(this_level_nodes);
    			level_size = _list.size();//
    		}
    	}

    	return nodes_levelorder;
    }
};
```