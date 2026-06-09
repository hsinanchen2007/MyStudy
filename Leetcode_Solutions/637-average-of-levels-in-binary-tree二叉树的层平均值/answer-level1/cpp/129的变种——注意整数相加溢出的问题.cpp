### 解题思路
执行用时 :28 ms, 在所有 C++ 提交中击败了34.35% 的用户
内存消耗 :24 MB, 在所有 C++ 提交中击败了5.44%的用户

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
    vector<vector<long>> LevelOrderAvgOfLevels(TreeNode* root){
    	vector<vector<long>> all_level_nodes;
    	if(!root) all_level_nodes;

    	vector<long> curr_level_nodes = {root->val};
    	all_level_nodes.push_back(curr_level_nodes);

    	list<TreeNode*> list_nodes;
    	list_nodes.push_back(root);
    	int list_size = list_nodes.size();
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
    			vector<long> curr_level_nodes;
    			for(auto& iter:list_nodes){
    				curr_level_nodes.push_back(iter->val);
    			}
    			all_level_nodes.push_back(curr_level_nodes);
    			list_size = list_nodes.size();
    		}
    	}

    	return all_level_nodes;
    }
    vector<double> averageOfLevels(TreeNode* root) {
    	vector<double> avg_per_level_nodes;
    	vector<vector<long>> all_level_nodes = LevelOrderAvgOfLevels(root);
    	for(auto& iter:all_level_nodes){
    		vector<long> curr_level_nodes = iter;
    		//std::accumulate似乎没法处理整数溢出的问题，只能手写实现sum
    		double sum = 0.0;
    		for(auto& iter2:iter){
//    			cout << "iter2 = " << hex << iter2 << endl;
    			sum += (double)iter2;
    		}
////    		long sum = std::accumulate(curr_level_nodes.begin(), curr_level_nodes.end(), 0);
//    		cout << "sum = " << sum << " = " << hex << sum << endl;
//    		cout << "curr level size is " << iter.size() << endl;
    		double avg = sum / iter.size();
    		avg_per_level_nodes.push_back(avg);
    	}
    	return avg_per_level_nodes;
    }
};
```