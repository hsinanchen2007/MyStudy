### 解题思路
二叉搜索树的中序遍历得到的是升序序列，本题求的是第K大节点，可以采用二叉搜索树的逆中序遍历，得到降序序列
递归方法简单，迭代方法可以利用栈实现

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
    //方法1 递归
     int res=0;
     int n=0;
     int kthLargest(TreeNode* root, int k) {   
         dfs(root,k);
         return res;
     }
     void dfs(TreeNode* root,int k){
         if(root==NULL)return ;
         if(root->right)dfs(root->right,k);
         n++;
         if(n==k)res=root->val;
         if(root->left)dfs(root->left,k);
         return ;
     }


     //方法2 迭代
     int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*>sk;
        int n=0;
        while(!sk.empty()||root){
            while(root){
                sk.push(root);
                root=root->right;
            }
            root=sk.top();
            sk.pop();
            n++;
            if(n==k)return root->val;
            root=root->left;
        }
        return 0;
    }
};
```