### 解题思路
此处撰写解题思路
如果有人能改进以下我这个，让内存占用小一些就好了
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL)return false;
        if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right) || p->val!=q->val) 
            return false;
        return true;
    }
};
```