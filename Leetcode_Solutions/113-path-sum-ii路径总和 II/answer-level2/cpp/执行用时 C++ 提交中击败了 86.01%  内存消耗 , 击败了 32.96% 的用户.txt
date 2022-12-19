我们需要使用三个对应栈，分别表示节点、从根节点到该节点的数值和、从根节点到该节点的路径vector。
按照先序的思路，进行遍历即可。
当弹出节点是叶节点，检查到该节点的数值和是不是sum。
当不是叶节点上时，在将该节点的左右节点压入栈中。

```
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // 就是对于所有路径的值求和，而不是找出所有路径了，还是可以类比257题
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        TreeNode* cur;
        int cur_sum;
        vector<int> cur_vec;

        stack<TreeNode*> nodes;
        stack<int> nodes_sum;
        stack<vector<int>> nodes_vec;

        nodes.push(root);
        nodes_sum.push(root->val);
        cur_vec.push_back(root->val);
        nodes_vec.push(cur_vec);

        
        while(!nodes.empty()){
            cur = nodes.top();
            cur_sum = nodes_sum.top();
            cur_vec = nodes_vec.top();
            nodes.pop();
            nodes_sum.pop();
            nodes_vec.pop();
            
            if(cur->left == NULL && cur->right == NULL){
                if(cur_sum == sum){
                    res.push_back(cur_vec);
                }
            }
            if(cur->left){
                nodes.push(cur->left);
                nodes_sum.push(cur_sum + cur->left->val);//加上该节点的值
                cur_vec.push_back(cur->left->val);
                nodes_vec.push(cur_vec);
                cur_vec.pop_back();// 删除最后一个，因为可能右节点也要用
            }
            if(cur->right){
                nodes.push(cur->right);
                nodes_sum.push(cur_sum + cur->right->val);//加上该节点的值
                cur_vec.push_back(cur->right->val);
                nodes_vec.push(cur_vec);
                cur_vec.pop_back();
            }
        }
        return res;

    }
};
```
