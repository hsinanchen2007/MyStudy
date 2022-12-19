### 解题思路
代码虽然有点长，但是很容易理解，而且执行效率很高
树中的节点可以分为四种：
1.左右都有子树，就把右子树压如栈中，左子树变为右子树
2.只有左子树，直接把左子树变为右子树
3.只有右子树，不操作继续往前遍历
4.没有子树，判断一下栈中是否有元素，若有则跳转到该子树，若无则表示遍历结束

时间复杂度为O(N)

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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true)
        {
            if(node->left!=NULL&node->right!=NULL)
            {
                st.push(node->right);
                node->right=node->left;
                node->left=NULL;
                node=node->right;
            }
            else if(node->left!=NULL&&node->right==NULL)
            {
                node->right=node->left;
                node->left=NULL;
                node=node->right;  
            }
            else if(node->left==NULL&&node->right!=NULL)
            {   node=node->right;   } 
            else
            {
                if(st.size()==0) break;
                node->right=st.top();
                st.pop();
                node=node->right;
            }   
        }
    }
};
```