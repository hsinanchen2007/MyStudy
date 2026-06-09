### 解题思路
分治（递归方法一定含返回值，需要用到）：
1）先看当前方法的返回值够不够用，不够用，需要新方法。当前是bool，够用；
2）分：bool left = isSameTree(p->left, q->left);
      bool right = isSameTree(p->right, q->right);
3）治：return left && right
4) 结束条件：
        // 左右都空，说明走到最后都没有返回false，则相同
        if(p == NULL && q == NULL) {
            return true;
        }
        // 右先走到空
        if(p == NULL && q != NULL) {
            return false;
        }
        // 左先走到空
        if(p != NULL && q == NULL) {
            return false;
        }
        // val不相等
        if(p->val != q->val) return false;

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
        if(p == NULL && q == NULL) {
            return true;
        }

        if(p == NULL && q != NULL) {
            return false;
        }

        if(p != NULL && q == NULL) {
            return false;
        }
        if(p->val != q->val) return false;
        
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right;
    }
};
```