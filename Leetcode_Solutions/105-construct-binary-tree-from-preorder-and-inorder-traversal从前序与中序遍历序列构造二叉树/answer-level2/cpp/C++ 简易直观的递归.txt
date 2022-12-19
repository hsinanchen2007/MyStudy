### 简易的C++递归版本
如何通过前序和中序遍历来建二叉树呢?
当然是先找到根，然后再建立左子树和右子树。

### 题解第一次遍历图解
![前序和中序建树.png](https://pic.leetcode-cn.com/9a8daf05b4c465285cd81c5848a5414f3630052d2e35b150c20d1eba90c1b07a-%E5%89%8D%E5%BA%8F%E5%92%8C%E4%B8%AD%E5%BA%8F%E5%BB%BA%E6%A0%91.png)


### 题解：
```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return getBinaryTree(0, inorder.size()-1, 0, preorder, inorder);
    }
private:
    // 中序遍历序列下标: [begin, end];
    // 前序的根节点下标: root 
    TreeNode* getBinaryTree(int begin, int end, int root, const vector<int>& preorder, const vector<int>& inorder)
    {
        if (begin > end) return nullptr;

        int p = 0;
        while (inorder[begin + p] != preorder[root]) p++;
        TreeNode* r = new TreeNode(preorder[root]);
        r->left = getBinaryTree(begin, begin + p - 1, root + 1, preorder, inorder);
        r->right = getBinaryTree(begin + p + 1, end, root + p + 1, preorder, inorder);

        return r;
    }
};
```
