### 解题思路

取母树为 $A$ ，子树为 $B$ ，需要判断 $B$ 是否为 $A$ 的子结构。

我们可以依次遍历  $A$  中的所有结点，对每个在  $A$  中遍历到的结点依次做判断，判断该结点是否可以作为子结构 $B$ 的根结点。

在代码中，我们写两个函数：

- $isSubStructure()$ ，用于遍历 A 中的所有结点，并调用 $helper()$ 进行判断
- $helper()$ ，用于判断  $A$  中当前结点能否作为 $B$ 的根结点



##### isSubStructure()

- 先序遍历 $A$ 中所有结点
- 如果当前结点为 $NULL$ 或者 $B$ 为 $NULL$ ，返回 $false$。（因为题目约定，空树不是任意一个树的子结构）



##### helper()

- 先序遍历 $A$ 和 $B$
- 如果 $B = NULL$ ，说明 $B$ 已遍历完，返回 $true$
- 如果 $A = NULL, B \neq NULL$，说明 $A$ 中结点不足以构成子结构 $B$，返回 $false$
- 如果 $A->val \neq B->val$ ，不满足结点值相等条件，返回 $false$



### 代码

```cpp
class Solution {
public:
    bool helper(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return B == NULL ? true : false;
        }
        if (A->val != B->val) {
            return false;
        }
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return false;
        }
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
```

### 最后

感谢您的观看！欢迎大家留言，一起讨论交流。

至此，您已经掌握了此题的解决方法，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)