## 中序遍历

二叉搜索树中序遍历后为一个有序数组，即左<中<右，因此可以在中序遍历代码的基础上进行改进，我们使用中序遍历可以得到每一个节点，然后当前节点的值和前一个节点的值进行比较，如果大于，那么继续遍历，否则我们返回false！如果可以成功遍历每个节点，并都满足那个比较条件，那么返回true。

```python []
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root: return True
        s, pre = [], float('-inf')
        p = root
        while s or p:
            if p:
                s.append(p)
                p = p.left
            else:
                p = s.pop()
                if p.val <= pre:
                    return False
                pre = p.val
                p = p.right
        return True
```
```C++ []
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        stack <TreeNode*> s;
        TreeNode* p = root;
        double pre = - DBL_MAX;
        while (!s.empty() || p){
            if (p){
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                if (p->val <= pre) return false;
                pre = p->val;
                p = p->right;
            }
        }
        return true;
    }
};
```