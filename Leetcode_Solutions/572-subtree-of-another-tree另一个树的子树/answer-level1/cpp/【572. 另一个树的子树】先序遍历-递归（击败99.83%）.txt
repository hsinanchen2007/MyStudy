## 思路
1. 首先寻找根节点相同节点。
   1. 先判断根节点是否相等，如果相等，再判断子树是否相等。
   2. 否则，判断子树是否等于原树左子树的子树。
   3. 否则，判断子树是否等于原树右子树的子树。
2. 然后判断子树是否相等
   - 如果都为空，则相等。
   - 如果其中一个不为空，则不等。
   - 如果都不为空，但值不相等，则不等。
   - 递归判断对应左右节点是否相等。
## 代码
```c++
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {        
        bool flag = false;
        if (s != nullptr && t != nullptr) {
            if (s->val == t->val) {
                flag = DoesTreeHavaTree(s, t);
            }
            if (!flag) {
                flag = isSubtree(s->left, t);
            } 
            if (!flag) {
                flag = isSubtree(s->right, t);
            }
        }        
        return flag;
    }
    bool DoesTreeHavaTree(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return DoesTreeHavaTree(s->left, t->left) && DoesTreeHavaTree(s->right, t->right);
    }
};
```
