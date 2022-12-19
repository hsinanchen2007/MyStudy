### 解题思路
![Snipaste_2020-04-08_20-33-44.png](https://pic.leetcode-cn.com/e24d737df70d23c40de8f7ef603365ab805dd928dff6f5c4658e17c1e53a8007-Snipaste_2020-04-08_20-33-44.png)

**使用递归：**
**思路：先排除特殊情况，两棵树都为空时，或者一棵树为空另一棵树不为空时，返回false**
**先比较根节点，如果不同，返回false；如果相同，向下递归比较左子树和右子树，都相同时，返回true。**

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
        if(p == NULL && q == NULL)
        {
            return true;
        }
        if(p == NULL || q == NULL)
        {
            return false;
        }
        if(p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
        }
    }
};
```