### 解题思路
二叉搜索树递归：
1）二叉搜索树的特点：每个根节点值>左节点值 &&根节点值<右节点值
2）二叉搜索树遍历：中序遍历是递增遍历

该题是删除值为key的节点，则替代该节点的一定是满足**根节点值>左节点值 &&根节点值<右节点值**
我们依据该特征，DFS向下寻找为key的节点，同时重塑左右分支节点
1）当root->val < key，返回root，同时deleteNode(root->right, key)
2）当root->val > key，返回root，deleteNode(root->left, key)
3）当root->val == key 时，有四种情况

1）被删除节点A是叶子节点，由于无左右分支，该节点也被删除，因此向上返回NULL；
2）被删除节点A左节点B为空，因此返回右节点C（满足二叉搜索树特点）；
3）被删除节点A右节点C为空，因此返回左节点B（满足二叉搜索树特点）；
4）被删除节点A左右节点B C都不为空，因此需要找到最贴近被删除节点的子节点。
以下图为例，假设删除的是5，则最贴近5的是左子节点是4，右节点是6.即找左子节点里面最优的，找右子节点里面最左的
将5和4的值交换，然后从4的左节点3开始删除5，由于5是叶子节点，因此会被直接删除


![image.png](https://pic.leetcode-cn.com/626a6434b444bb41e295d8fbc3810b10830764aaa14561a0ec6914f15450d19b-image.png)




### 代码

```cpp

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }

        if (root->left == nullptr) {
            return root->right;
        }

        if (root->right == nullptr) {
            return root->left;
        }

        TreeNode *node = root->left;
        while (node->right != nullptr) {
            node = node->right;
        }

        swap(root->val, node->val);

        root->left = deleteNode(root->left, node->val);

        return root;
    }
};
```