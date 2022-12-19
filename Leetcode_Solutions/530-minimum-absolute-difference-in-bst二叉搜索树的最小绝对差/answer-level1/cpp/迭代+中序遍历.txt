执行用时 :24 ms, 在所有 C++ 提交中击败了87.27%的用户
内存消耗 :22.1 MB, 在所有 C++ 提交中击败了84.88%的用户

搜索树的中序遍历是升序，使用了一个栈来记录上一次探索到的节点的值。


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
    int getMinimumDifference(TreeNode* root) {
        
        
        stack<TreeNode*> Stack;
        TreeNode* node = root;
        
        int min_num = 9999;
        stack<int> temp;
        
        //中序遍历二叉树
        while(!Stack.empty() || node!=NULL){
            
            if(node!=NULL){
                
                Stack.push(node);
                node = node->left;
            }
            else{
                node = Stack.top();
                Stack.pop();
                
                if(temp.empty())
                    temp.push(node->val);
                else{
                    
                    //将探索到的每个节点和上一次探索到的节点做绝对差，找出差值最小的值
                    min_num = min(abs(temp.top() - node->val), min_num);
                    temp.push(node->val);
                }

                
                node = node->right;
            }
        }

        
        return min_num;
        
    }
};
```
