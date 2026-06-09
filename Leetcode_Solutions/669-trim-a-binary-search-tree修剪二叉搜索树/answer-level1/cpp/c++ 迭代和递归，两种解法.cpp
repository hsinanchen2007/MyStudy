递归清晰明确。主要是迭代解法，迭代思路首先确定根结点，然后通过使用栈，再迭代左右子节点
```c++
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
    /*recurisive methods*/
    /*TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(nullptr==root) return root;
        if(root->val<L) return trimBST(root->right,L,R);
        if(root->val>R) return trimBST(root->left,L,R);
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        return root;
    }
    */
    /*Iteration methods*/
    TreeNode* trimBST(TreeNode* root,int L,int R){
        while(nullptr!=root){  // to find the root node
            if(root->val>R){
                root=root->left;
                continue;
            }else if(root->val<L){
                root=root->right;
                continue;
            }
            break;
        }
        if(nullptr==root) return root;  // maybe ,we don't found the root node
        std::stack<TreeNode*> node_stack;
        node_stack.push(root);
        while(!node_stack.empty()){
            auto p=node_stack.top();
            node_stack.pop();
            auto pl=p->left;
            while(nullptr!=pl){  // iteration for finding the left node
                if(pl->val<L){
                    pl=pl->right;
                    continue;
                }
                break;
            }
             p->left=pl;
            if(nullptr!=pl)  // if not nullptr，we need to push the stack
            node_stack.push(p->left);
            auto pr=p->right;
            while(nullptr!=pr){  //iteration for finding the right node
                if(pr->val>R){
                    pr=pr->left;
                    continue;
                }
                break;
            }
            p->right=pr;
            if(nullptr!=pr) // if not nullptr,we need to push the stack
            node_stack.push(p->right); 
        }
        return root;
    }
};
```
