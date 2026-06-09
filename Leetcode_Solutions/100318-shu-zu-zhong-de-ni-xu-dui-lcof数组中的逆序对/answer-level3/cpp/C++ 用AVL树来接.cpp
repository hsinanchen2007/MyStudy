### 解题思路
核心思路是查找已遍历的比当前数字大的数的个数，这个个数就是当前数字与之前数字所产生的逆序对数量。
在遍历的同时建立一个二叉搜索树，节点中加入一个字段rightcount统计右节点个数，即是比当前节点大的元素个数。
遍历一个新元素时先查找其在二叉树中的位置，如果比树的节点值小，则result += rightcount，并且往左子树继续比较。反之直接往右子树走。找到一个空位插入当前元素到树中。
一开始我是直接用普通的二叉树，但是在1,2,3,4，。。。，9999999的顺序用例时timeout，因此改用AVL树。AVL树效率损失主要在平衡节点上。不过时间复杂度任然是O（nlogn）

### 代码

```cpp
class Solution {
public:
    struct TreeNode
    {
        int val;
        int leftdepth;
        int rightdepth;
        int leftcount;
        int rightcount;
        TreeNode* parent;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : val(val), leftdepth(0), rightdepth(0), leftcount(0), rightcount(0), parent(NULL), left(NULL), right(NULL) {}
    };

    TreeNode* rotateleft(TreeNode* node)
    {
        TreeNode* next = node->right;
        TreeNode* parent = node->parent;
        if (parent)
        {
            if (node == parent->left) parent->left = next;
            else parent->right = next;
        }

        node->right = next->left;
        if (next->left) next->left->parent = node;
        node->rightdepth = next->leftdepth;
        node->rightcount = next->leftcount;
        node->parent = next;

        next->left = node;
        next->leftdepth = max(node->leftdepth, node->rightdepth) + 1;
        next->leftcount = node->leftcount + node->rightcount + 1;
        next->parent = parent;
        return next;
    }

    TreeNode* rotateright(TreeNode* node)
    {
        TreeNode* next = node->left;
        TreeNode* parent = node->parent;
        if (parent)
        {
            if (node == parent->left) parent->left = next;
            else parent->right = next;
        }

        node->left = next->right;
        if (next->right) next->right->parent = node;
        node->leftdepth = next->rightdepth;
        node->leftcount = next->rightcount;
        node->parent = next;

        next->right = node;
        next->rightdepth = max(node->leftdepth, node->rightdepth) + 1;
        next->rightcount = node->leftcount + node->rightcount + 1;
        next->parent = parent;
        return next;
    }

    void adjustnode(TreeNode** root, TreeNode* cur)
    {
        if (cur->left)
        {
            cur->leftdepth = max(cur->left->leftdepth, cur->left->rightdepth) + 1;
            cur->leftcount = cur->left->leftcount + cur->left->rightcount + 1;
        }
        if (cur->right)
        {
            cur->rightdepth = max(cur->right->leftdepth, cur->right->rightdepth) + 1;
            cur->rightcount = cur->right->leftcount + cur->right->rightcount + 1;
        }

        for (int i = 0; i < 2; ++i)
        {
            int diff = cur->leftdepth - cur->rightdepth;
            if (diff > 1)
            {
                cur = rotateright(cur);
            }
            else if (diff < -1)
            {
                cur = rotateleft(cur);
            }
        }

        if (cur->parent == NULL) *root = cur;
        else adjustnode(root, cur->parent);
    }

    int insertnode(TreeNode** root, int val)
    {
        TreeNode* cur = *root;
        int res = 0;
        while (true)
        {
            if (cur->val > val)
            {
                res += cur->rightcount + 1;
                if (!cur->left)
                {
                    cur->left = new TreeNode(val);
                    cur->left->parent = cur;
                    adjustnode(root, cur);
                    break;
                }
                cur = cur->left;
            }
            else
            {
                if (!cur->right)
                {
                    cur->right = new TreeNode(val);
                    cur->right->parent = cur;
                    adjustnode(root, cur);
                    break;
                }
                cur = cur->right;
            }
        }
        return res;
    }

    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        TreeNode* root = new TreeNode(nums[0]);
        int res = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            res += insertnode(&root, nums[i]);
        }
        return res;
    }
};
```