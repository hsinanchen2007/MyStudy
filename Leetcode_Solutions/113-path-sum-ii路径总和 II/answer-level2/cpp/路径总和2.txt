两个栈：一个栈存放节点，另一个栈存放到节点的路径向量
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
    //迭代解法
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;

        stack<TreeNode*> node_stk;
        stack<vector<int>> vec_stk;
        node_stk.push(root);
        vec_stk.push({root->val});

        TreeNode *cur_node;
        vector<int> cur_vec;

        while(!node_stk.empty()){
            cur_node = node_stk.top();
            node_stk.pop();
            cur_vec = vec_stk.top();
            vec_stk.pop();

            if(!cur_node->left && !cur_node->right){
                int s = 0;
                for(auto ele : cur_vec) s += ele;
                if(s == sum){
                    res.push_back(cur_vec);
                }
            }
            if(cur_node->right){
                node_stk.push(cur_node->right);
                cur_vec.push_back(cur_node->right->val);
                vec_stk.push(cur_vec);
                cur_vec.pop_back();
            }
            if(cur_node->left){
                node_stk.push(cur_node->left);
                cur_vec.push_back(cur_node->left->val);
                vec_stk.push(cur_vec);
            }
        }
        return res;
    }
};
```
