执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.9 MB, 在所有 C++ 提交中击败了73.43%的用户

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        
        TreeNode* node1 = p;
        TreeNode* node2 = q;
        
        //先序遍历同时探索两颗树
        while(!stack1.empty() || !stack2.empty() || node1!=NULL || node2!=NULL){

            
            if(node1!=NULL && node2!=NULL){
                
                if(node1->val!=node2->val)//如果两个指针所指的节点的值不同 则返回false
                    return false;
                
                stack1.push(node1);
                stack2.push(node2);
                
                node1 = node1->left;
                node2 = node2->left;
            }
            else if(node1==NULL && node2==NULL){
                
                node1 = stack1.top();
                node2 = stack2.top();
                stack1.pop();
                stack2.pop();
                
                node1 = node1->right;
                node2 = node2->right;
            }
            else//其它情况是指有一个指针指向的为NULL
                return false;
        }
        
        
        return true;
        
    }
};
```
