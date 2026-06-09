### 解题思路
1、先利于非递归中序遍历将二叉搜索树按值的大小顺序保存
2、递归构建二叉平衡树

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
        void PreOrder(vector<TreeNode*>& tmp, TreeNode* root){
        stack<TreeNode*> stack;
        TreeNode* p=root;
        while(p!=NULL || !stack.empty()){
            while(p!=NULL){
                stack.push(p);
                p=p->left;
            }
            p=stack.top();
            stack.pop();
            tmp.push_back(p);
            p=p->right;
        }
    }
    
    TreeNode* balanceBSTCore(vector<TreeNode*>& tmp, int m, int n){
        if(m>n)
            return NULL;
        int k=(m+n)/2;
        tmp[k]->left=balanceBSTCore(tmp,m,k-1);
        tmp[k]->right=balanceBSTCore(tmp,k+1,n);
        return tmp[k];
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> tmp;
        PreOrder(tmp, root);
        int size=tmp.size()-1;
        return balanceBSTCore(tmp,0,size);
    }
};
```