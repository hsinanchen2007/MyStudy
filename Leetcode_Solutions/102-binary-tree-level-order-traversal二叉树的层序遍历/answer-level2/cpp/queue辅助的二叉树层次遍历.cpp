### queue辅助的层次遍历方法
1, 使用一个queue< pair<TreeNode*, int> >  存放TreeNode节点指针和其对应的层次，第一次插入根节点，层次为1
2, 判断 queue是否为空，如果不为空，则记录当前节点的 node->val，并将非空的node->left和node->right压入queue中
3，重复第二步直到 queue为空 

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
        queue< pair<TreeNode*, int> > help;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }

        help.push( {root, 0} );
        while(!help.empty()){
            //取出queue.front 存储的节点，如果左子树存在，则递增level并push进队列
            TreeNode* tree = help.front().first;
            int level = help.front().second;

            //当ans行数与level相等时，表示需要新增一行，才能存储level行的节点;
            if( ans.size() == level ){
                ans.push_back( {} );
            }
            ans[level].push_back(tree->val);

            if(tree->left){
                help.push( {tree->left, level+1} );
            }
            if(tree->right){
                help.push( {tree->right, level+1} );
            }
            //弹出当前节点;
            help.pop();
        }

        return ans;

    }
};
```