使用队列，每弹出一个节点，则压入其左右节点

定义了两个辅助变量:
 - curNums  记录当前层的剩余遍历的节点数。当curNums==0，则将下一层的节点数赋值给curNums。
 - nextNums 记录下一层的节点数

`执行用时 :4 ms, 在所有 C++ 提交中击败了98.48% 的用户
内存消耗 :13.8 MB, 在所有 C++ 提交中击败了70.85%的用户`

``` c++
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
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        vector<int> level_res;
        int curNums=1, nextNums=0 ;
        
        TreeNode* node;
        
        while(!queue.empty() )
        {
            node = queue.front();
            
            level_res.push_back( node->val );
            queue.pop();
            curNums--;
            
            if(node->left)
            {
                queue.push(node->left);
                nextNums ++;
            }
                
            if(node->right)
            {
                queue.push(node->right);
                nextNums ++;
            }
                
            
            if(curNums == 0)
            {
                res.push_back(level_res);
                
                level_res.clear();
                
                curNums = nextNums;
                nextNums = 0;
            }
                
        }

        return res;
        
    }
};
```
