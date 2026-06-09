### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :13.8 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    vector<int> levelOrder(TreeNode* root) {
    	vector<int> nodes_levelorder;
    	if(!root) return nodes_levelorder;
    	nodes_levelorder.push_back(root->val);
    	list<TreeNode*> _list;
    	_list.push_back(root);
    	while(_list.size()){
    		//for debug
//    		TraverseTreeNodeList(_list);
    		if(root->left){
    			_list.push_back(root->left);
    		}
    		if(root->right){
    			_list.push_back(root->right);
    		}
    		_list.pop_front();
    		if(_list.size()){
        		root = _list.front();
        		nodes_levelorder.push_back(root->val);
    		}
    	}
    	return nodes_levelorder;
    }
};
```