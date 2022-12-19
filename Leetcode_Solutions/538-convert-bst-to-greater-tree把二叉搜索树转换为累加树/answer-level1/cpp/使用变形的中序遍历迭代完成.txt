执行用时 :52 ms, 在所有 C++ 提交中击败了71.06%的用户
内存消耗 :23.5 MB, 在所有 C++ 提交中击败了85.07%的用户

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
    TreeNode* convertBST(TreeNode* root) {
        

        //使用变形的中序遍历（右子->根->左子）的顺序遍历二叉树
        stack<TreeNode*> stack;
        TreeNode* node = root;
        
        int temp = 0;
        
        while(!stack.empty() || node!=NULL){
            
            if(node!=NULL){
                
                stack.push(node);
                node = node->right;
            }
            else{
                
                node = stack.top();
                stack.pop();
                
                //将上一个处理过的节点的值 累加到下一个即将处理的节点上
                temp += node->val;               
                node->val = temp;

                node = node->left;
            }
        }
        
        return root;
        
        
        
        
        
    }
};
```
