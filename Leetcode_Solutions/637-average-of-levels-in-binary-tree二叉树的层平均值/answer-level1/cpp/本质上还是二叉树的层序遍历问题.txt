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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> output;
        
        queue<TreeNode*> tree;//用队列临时保存探索过的节点
        tree.push(root);
        
        if(tree.empty())//原树为空的情况下返回null
            return output;
        
        while(!tree.empty()){
            
            double sum = 0;
            int size = tree.size();//实时更新队列长度
            
            for(int i=0; i<size; i++){
                
                TreeNode* node = tree.front();
                tree.pop();
                sum += node->val;
                
                if(node->left!=NULL)
                    tree.push(node->left);
                if(node->right!=NULL)
                    tree.push(node->right);
            }
            
            output.push_back(sum/size);
        }
        
        return output;
        
        
        
    }
};
```
