执行用时 :12 ms, 在所有 C++ 提交中击败了
83.20%的用户内存消耗 :13.6 MB, 在所有 C++ 提交中击败了95.30%的用户


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        
        queue<TreeNode*> temp;//临时保存探索过的节点
        
        vector<int> layer;//保存每一层的所有节点
        stack<vector<int>> TEMP;//临时保存每一层
        vector<vector<int>> output;
        
        
        
        if(root==NULL)
            return output;
        
        
        temp.push(root);
        
        
        while(!temp.empty()){
            
            layer.clear();            
            int size = temp.size();//记录每层节点数
            
            for(int i=0; i<size; i++){
                
                TreeNode* node = temp.front();                
                temp.pop();
                layer.push_back(node->val);
                
                if(node->left!=NULL)
                    temp.push(node->left);
                if(node->right!=NULL)
                    temp.push(node->right);
                
            }

            TEMP.push(layer);
   
        }
        
        while(!TEMP.empty()){
            
            output.push_back(TEMP.top());
            TEMP.pop();
        }
        
        return output;
    }
};
```
