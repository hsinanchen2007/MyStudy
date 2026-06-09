
特别注意不要用
`if(p->val == q-> val)`
判断是否相等，因为如果根节点的值相等会直接返回

```
/**执行用时 :4 ms, 在所有 C++ 提交中击败了81.88%的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了91.33%的用户

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
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;         //这里不能用相等判断
        
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
    }
};
```
