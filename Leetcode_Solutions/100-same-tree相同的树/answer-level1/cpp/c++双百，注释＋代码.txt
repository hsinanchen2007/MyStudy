### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/7f818dcab9890eff5369b4306e3f0758d296256969a49a0ce50be780266b361e-image.png)

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
        if(!p&&!q) return true;  //如果都为空则相同
        if(!p||!q) return false;  //如果只有一个为空则不同
        if(p->val==q->val)  //如果都不为空且val相同则检查子节点是否相同
        return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        return false;  //否则不同
    }
};
```