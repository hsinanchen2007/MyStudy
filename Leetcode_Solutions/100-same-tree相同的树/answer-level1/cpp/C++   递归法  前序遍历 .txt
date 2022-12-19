### 解题思路
遍历时当出现不一致时，标记位flag置为false，注意NULL点的判断。

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
    bool flag = true;
    void preOrderTraversal(TreeNode* p, TreeNode* q){
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) flag = false;
        if(p != NULL && q != NULL){
            if(p->val != q->val) flag = false;
            preOrderTraversal(p->left, q->left);
            preOrderTraversal(p->right, q->right);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return p==q ? true : false;
        preOrderTraversal(p, q);
        return flag;
    }
};
```