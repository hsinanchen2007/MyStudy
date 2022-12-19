- ### 解题思路

根据搜索树特性，判断：k 与（右子树+当前结点) 的大小关系

1）k == 右子树 + 当前结点
    直接返回当前节点的值，找到第k大的节点
2）k > 右子树 + 当前结点
    停止在右子树中搜索，说明 右子树与当前结点的个数加起来也不到第k个大的节点，那么，必然在其左子树中，递归左子树如下：
        kthLargest(root->left, k - num);
3）k < 右子树 + 当前结点
    说明 第k大的节点，在当前节点的右子树中，递归右子树：
        kthLargest(root->right, k);

定义numTree函数，递归求树的节点个数
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
    int numTree(TreeNode* node){
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right == NULL)
            return 1;
        return numTree(node->left) + numTree(node->right) + 1;
    }
    int kthLargest(TreeNode* root, int k) {
        int num = 1;
        if(root == NULL)
            return -1;
        if(root->right != NULL)
            num = numTree(root->right) + 1;
        if(k == num){
            return root->val;
        }
        if(k < num)
            return kthLargest(root->right, k);
        if(k > num)
            return kthLargest(root->left, k - num);
        return -1;
    }
};
```