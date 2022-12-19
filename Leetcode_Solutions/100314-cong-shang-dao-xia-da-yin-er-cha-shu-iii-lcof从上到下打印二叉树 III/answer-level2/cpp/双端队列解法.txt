双端队列
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
        vector<vector<int>> ans;
        if ( !root )
        {
            return ans;
        }
        deque<TreeNode*> dq;
        dq.push_back( root );
        int flag = 1; // 
        while ( !dq.empty())
        {
            //　每次进入循环重新计算队列 size , 就是当前层所有元素
             int num  = dq.size();
            vector<int> nodes;
            for ( int i = 0 ; i < num; i ++ )
            {
                if ( flag == 1) // 当前层节点前端弹出，子节点先左后右、后端进入
                {
                    TreeNode* cur = dq.front();
                    nodes.push_back( cur->val );
                    dq.pop_front( ) ;
                    if( cur->left )
                        dq.push_back(cur->left);
                    if (cur->right)
                        dq.push_back(cur->right);
                }
                else if ( flag == 0 ) // 当前层节点后端弹出，子节点先右后左，前端进入
                {
                    TreeNode* cur = dq.back();
                    nodes.push_back(cur->val);
                    dq.pop_back();
                    if( cur->right )
                        dq.push_front(cur->right);
                    if( cur->left)
                        dq.push_front(cur->left);
                }
            }
            ans.push_back(nodes);
            flag = ( flag == 1) ? 0 : 1;
        }
        return ans;    
    }
};
```