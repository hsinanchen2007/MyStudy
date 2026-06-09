### 解题思路
先序遍历二叉树，如果遍历到的节点有子节点，交换子节点，直到二叉树被遍历完。
参考[swap()函数](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/solution/di-gui-by-user2473e-9/)

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
    template<typename T>
    void swap(T& left, T& right){
        T temp = left;
        left = right;
        right = temp;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return nullptr;

        swap(root->left, root->right);

        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);

        return root;
    }
};
```