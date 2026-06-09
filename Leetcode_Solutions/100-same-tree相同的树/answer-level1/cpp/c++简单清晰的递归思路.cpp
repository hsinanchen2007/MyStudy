### 解题思路
首先判断当前p和q是否相等
case 1.都为空 返回true
case 2.其中一个不为空 返回false
case 3.两者不为空，但是val不一样返回false
这时候可以认为p和q是相等的

然后递归的用相同的法则判断 p->left是否与q->left相等 && p->right是否与q->right相等
### 代码

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr) || p->val != q->val) {
            return false;
        }
        //note:p->val == q->val
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);;
    }
};
```