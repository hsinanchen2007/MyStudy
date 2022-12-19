执行用时 :8 ms, 在所有 C++ 提交中击败了76.28%的用户
内存消耗 :13.3 MB, 在所有 C++ 提交中击败了99.46%的用户

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
    
    vector<int> leaves(TreeNode* root){//收集数的叶子
        
        vector<int> output;
        
        stack<TreeNode*> tree;
        TreeNode* node = root;
        
        while(!tree.empty() || node!=NULL){//先序遍历树
            
            if(node!=NULL){
                
                if(node->left==NULL && node->right==NULL){//没有左子右子的节点即为叶
                    output.push_back(node->val);
                    //cout << node->val << endl;
                }
                    
                
                tree.push(node);
                node = node->left;
            }
            else{
                
                node = tree.top();
                tree.pop();
                node = node->right;
            }
        }
        
        return output;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        
        
        return (leaves(root1)==leaves(root2));
        
        
    }
};
```
