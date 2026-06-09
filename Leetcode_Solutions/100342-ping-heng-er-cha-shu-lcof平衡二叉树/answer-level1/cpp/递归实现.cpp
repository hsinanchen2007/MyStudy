### 解题思路
我是通过计算高度差来判断是否为平衡树
从根节点开始先计算出左右结点的高度差，如果高度差大于1或小于-1则直接返回false，否则遍历左子树和右子树，如果都为左右子树都是平衡树则返回true
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
    int Max(int a, int b){
        return a>b?a:b;
    }
    int GetHeight(TreeNode *root){
        if(root){
            return Max(GetHeight(root->left), GetHeight(root->right))+1;
        }else{
            return 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root){
            int bf = GetHeight(root->left)-GetHeight(root->right);
            if(bf>1||bf<-1){
                return false;
            }else{
                return isBalanced(root->left)&&isBalanced(root->right);
            }
        }else{
            return true;
        }
    }
};
```