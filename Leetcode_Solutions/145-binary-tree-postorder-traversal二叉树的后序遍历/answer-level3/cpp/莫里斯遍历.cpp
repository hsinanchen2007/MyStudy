### 基本思路
- 前序遍历为**root -> left -> right**，后序遍历为**left -> right -> root**。
- 可以修改前序遍历成为**root -> right -> left**，那么这个顺序就和后序遍历正好相反。
- 套用[***前序遍历的莫里斯法***](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/er-cha-shu-de-qian-xu-bian-li-by-leetcode/)，然后反转，即可得到后续遍历。


### C++代码
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *curr = root;
        TreeNode *pre;  // 前驱节点
        while(curr != NULL){
            if(curr->right == NULL){
                result.insert(result.begin(), curr->val);    // 没有右子树，直接访问当前根节点（此处是从头插入，后续不用再反转）
                curr = curr->left;                           // 接下来访问左子树
            }else{
                // 寻找右子树中的最左的叶节点
                pre = curr->right;
                while(pre->left != NULL && pre->left != curr){
                    pre = pre->left;
                }

                // 第一次访问，直接访问当前根节点，然后前驱节点指向根（建立伪边）
                if(pre->left == NULL){
                    result.insert(result.begin(), curr->val);
                    pre->left = curr;
                    curr = curr->right;
                }else{
                    pre->left = NULL;  // 第二次访问，说明当前根节点的右子树已经访问完，接下来访问左子树
                    curr = curr->left;
                }
            }
        }
        return result;
    }
};
```
### 算法复杂度
- 时间复杂度：每个前驱恰好访问两次，因此复杂度是 `O(N)`，其中 `N`是顶点的个数，也就是树的大小。
- 空间复杂度：我们在计算中不需要额外空间，但是输出需要包含 `N` 个元素，因此空间复杂度为 `O（N）`。

