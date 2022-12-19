执行用时 :44 ms, 在所有 C++ 提交中击败了90.67%的用户
内存消耗 :18.4 MB, 在所有 C++ 提交中击败了92.07%的用户

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
    TreeNode* increasingBST(TreeNode* root) {
        
        stack<TreeNode*> tree;
        queue<TreeNode*> temp;

        TreeNode* node = root;
        
        while(!tree.empty() || node!=NULL){//中序遍历原树
            
            if(node!=NULL){
                
                tree.push(node);
                node = node->left;
            }
            else{
                
                node = tree.top();
                
                //cout << node->val << "----";


                if(node!=NULL){
                    
                    temp.push(node);//将中序遍历所寻得的节点按序压入队列中
                }
                
                tree.pop();
                node = node->right;
            }
        }
        
        root = temp.front();
        
        while(!temp.empty()){//将队列以队首为根重新排列成树
            
            //cout << temp.front()->val << endl;
            
            TreeNode* node = temp.front();
            temp.pop();
            
            node->left = NULL;
            if(!temp.empty())
                node->right = temp.front();
            
            
        }
        
        return root;
    }
};
```
