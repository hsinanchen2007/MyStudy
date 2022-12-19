### 解题思路
逆中序遍历 写出来让自己加深印象。
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
    int n = 0;
    int kthLargest(TreeNode* root, int k) {
        // 二叉搜索树的中序遍历结果是有序的
        if(root==NULL) return INT_MIN;
        if(root->right!=NULL){ //不空
            int res = kthLargest(root->right,k);
            if(res!=INT_MIN) return res;
        }
        n++;
        if(n==k) return root->val;
        if(root->left!=NULL){
            return kthLargest(root->left,k);
        }
        return INT_MIN;
    }
};
```