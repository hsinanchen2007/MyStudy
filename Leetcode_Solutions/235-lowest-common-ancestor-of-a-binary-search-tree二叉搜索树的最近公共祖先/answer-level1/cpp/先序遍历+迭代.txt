执行用时 :48 ms, 在所有 C++ 提交中击败了80.08%的用户
内存消耗 :25.4 MB, 在所有 C++ 提交中击败了99.87%的用户


```
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        stack<TreeNode*> tree;//存储探索过的节点
        
        TreeNode* node = root;//指向root
        
        while(!tree.empty() || node!=NULL){//先序遍历
            
            if(node!=NULL){
                
                //cout << node->val << endl;
                if((node->val >= p->val && node->val <= q->val) || (node->val <= p->val && node->val >= q->val))
                    //根据搜索二叉树的特点，当且仅当节点值位于pq中间时返回
                    return node;
                
                tree.push(node);
                node = node->left;
            }
            else{
                
                node = tree.top();
                tree.pop();
                node = node->right;
            }
        }
        
        return node;
    }
};
```
