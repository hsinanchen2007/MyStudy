### 解题思路
这个题需要注意一个地方，不能被题目中的图给迷惑了。因为题目说的是经过若干次翻转后 可以得到完全对称，要你判断是否完全对称。那如果不翻转呢，那不也是对称吗。所以要分两种情况：1.翻转若干次至完全对称。2.不翻转维持原状，也是完全对称。
对于第一种情况：需要 左值=右值，右值=左值
对于第二种情况：需要 左值=左值，右值=右值
临界null的情况就不详细说了，比较容易，直接上代码。0ms

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       if(root1 == NULL && root2 == NULL){
           return true;
       }
       if(root1 == NULL || root2 == NULL){
           return false;
       }
       if(root1->val != root2->val){
           return false;
       }
       return (flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right))
           || (flipEquiv(root1->right,root2->left) && flipEquiv(root1->left,root2->right));
    }
};
```