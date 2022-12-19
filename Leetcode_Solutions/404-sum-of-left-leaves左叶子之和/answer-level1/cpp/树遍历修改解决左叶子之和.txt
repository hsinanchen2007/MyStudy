### 解题思路

使用任何一种树遍历的方法，对每个节点进行左子树非空检查时检查其左子树是否为叶节点，如果是就加入其值，便可得到所有左叶子的和。

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
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int sum=0;
        stack<TreeNode*> S;
        TreeNode* temp;
        
        S.push(root);
        
        while(!S.empty()){
            
            temp = S.top();
            S.pop();
            if(temp->left!=NULL){
                if(temp->left->left==NULL &&  temp->left->right==NULL)
                    sum+=temp->left->val;
                S.push(temp->left);
            }
            if(temp->right!=NULL)
                S.push(temp->right);
            
        }
        
        return sum;
    }
};
```