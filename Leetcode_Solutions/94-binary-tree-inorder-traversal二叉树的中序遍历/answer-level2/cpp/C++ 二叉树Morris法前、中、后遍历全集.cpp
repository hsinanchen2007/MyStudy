# 思路
Morris遍历是利用叶子节点的空指针指向上层节点的方法来进行二叉树遍历，
可以实现非递归的`O(1)`空间复杂度`O(n)`的时间复杂度对树进行遍历，非常经典
前序和中序实现比较简单，且代码仅有两行区别
后序遍历稍微复杂些，需要进行一些逆序操作

我仔细研究了下该算法，总结Morris的算法核心就是**左顾右盼**
**左顾：** 看左子树是否为空，若不为空，判断左子树的最右节点右指针是否指向自己
**右盼：** 左边都处理了，就可以右移了

**前序遍历**：左顾的时候发现其左子树为空或者其最右节点右指针**没有**指向自己，则收集该点的值
**中序遍历**：左顾的时候发现其左子树为空或者其最右节点右指针**有**指向自己，则收集该点的值
**后序遍历**：左顾的时候发现其左子树为空或者其最右节点右指针**有**指向自己，则逆序遍历其左子树的右边界节点

具体的细节可以看代码与网上的讲解品味一下其中精巧之处。
代码如下：

**二叉树前序遍历**
```
class Solution {
public:
    TreeNode* getLeftMostRight(TreeNode* root) {
        auto node = root->left;
        while (node != NULL && node->right != NULL && node->right != root) {
            node = node->right;
        }
        return node;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left == NULL) {
                res.push_back(root->val);
                root = root->right;
            } else {
                auto node = getLeftMostRight(root);
                if (node->right == root) {
                    node->right = NULL;
                    root = root->right;
                } else {
                    res.push_back(root->val);
                    node->right = root;
                    root = root->left;
                }
            }
        }
        return res;
    }
};
```

**二叉树中序遍历**
```
class Solution {
public:
    TreeNode* getLeftMostRight(TreeNode* root) {
        auto node = root->left;
        while (node != NULL && node->right != NULL && node->right != root) {
            node = node->right;
        }
        return node;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left == NULL) {
                res.push_back(root->val);
                root = root->right;
            } else {
                auto node = getLeftMostRight(root);
                if (node->right == root) {
                    node->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                } else {
                    node->right = root;
                    root = root->left;
                }
            }
        }
        return res;
    }
};
```

**二叉树后序遍历**
```
class Solution {
public:
    TreeNode* getLeftMostRight(TreeNode* root) {
        auto node = root->left;
        while (node != NULL && node->right != NULL && node->right != root) {
            node = node->right;
        }
        return node;
    }
    TreeNode* reverseRight(TreeNode* root) {
        auto prev = root;
        auto curr = prev->right;
        prev->right = NULL;
        while (curr != NULL) {
            auto temp = curr->right;
            curr->right = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    void printEdge(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        auto tail = reverseRight(root);
        auto node = tail;
        while (node != NULL) {
            res.push_back(node->val);
            node = node->right;
        }
        reverseRight(tail);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        auto head = root;
        vector<int> res;
        while (root) {
            if (root->left == NULL) {
                root = root->right;
            } else {
                auto node = getLeftMostRight(root);
                if (node->right == root) {
                    node->right = NULL;
                    printEdge(root->left, res);
                    root = root->right;
                } else {
                    node->right = root;
                    root = root->left;
                }
            }
        }
        printEdge(head, res);
        return res;
    }
};
```
