所谓 p 的后继节点，就是这串升序数字中，比 p 大的下一个。

+ 如果 p 大于当前节点的值，说明后继节点一定在 RightTree
+ 如果 p 等于当前节点的值，说明后继节点一定在 RightTree
+ 如果 p 小于当前节点的值，说明后继节点一定在 LeftTree 或自己就是
    + 递归调用 LeftTree，如果是空的，说明当前节点就是答案
    + 如果不是空的，则说明在 LeftTree 已经找到合适的答案，直接返回即可

```cpp
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) {
            return NULL;
        }

        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode *leftRet = inorderSuccessor(root->left, p);
            if (!leftRet) {
                return root;
            } else {
                return leftRet;
            }
        }
    }
```