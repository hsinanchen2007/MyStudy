### 解题思路
递归查找结点
找到节点以后分三种情况：
要删除节点w
（1）是叶子节点
（2）有左孩子无右孩子，有右孩子无左孩子
（3）既有左又有右


### 代码

```cpp
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
    void find(TreeNode ** pp,TreeNode* root, int key){
        if(!root)return ;
        if(root->val==key){
            if(!root->left && !root->right ){
                // TreeNode * tmp=root;
                *pp=NULL;
                delete root;
                
            }else if(!root->left || !root->right){
                TreeNode * tmp=root;
                *pp=root->left?root->left:root->right;
                delete tmp;
            }else{
                TreeNode * p=root->right;
                TreeNode * q=root;
                while(p->left){q=p;p=p->left;}
                root->val=p->val;
                if(q!=root)q->left=p->right;
                else{
                    q->right=p->right;
                }
                if(p->right){
                    delete p;
                }
                
            }
        }else if(root->val>key){
            find(&(root->left),root->left,key);
        }else{
            find(&(root->right),root->right,key);
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        find(&root,root,key);
        return root;
    }
};
```