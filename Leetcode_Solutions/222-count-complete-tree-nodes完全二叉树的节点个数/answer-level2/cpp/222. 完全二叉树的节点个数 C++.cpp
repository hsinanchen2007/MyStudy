### 解题思路


### 代码

```cpp

class Solution {
public:

    //1、二叉树求节点数  时间复杂度 O(N)
    int countNodes(TreeNode* root) {

        if(root == nullptr)
            return 0;

        //本结点 + 左子树节点数 + 右子树节点数
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    //2、完全二叉树求节点数  时间复杂度 O((logN)^2)
    //最左边节点所在层数  level 为node所在层数
    int most_left_level(TreeNode* node, int level)
    {
        if(!node)
            return level - 1;
        
        while(node->left)
        {
            ++level;
            node = node->left;
        }
        return level;
    }

    int bs(TreeNode* node, int level, int h)
    {
        if (level == h) //node为叶子节点
            return 1;
            
        if (most_left_level(node->right, level + 1) == h)
        {
            return (1 << (h - level)) + bs(node->right, level + 1, h);
        }
        else
        {
            return (1 << (h - level - 1)) + bs(node->left, level + 1, h);
        }
    }

    int countNodes(TreeNode* root) {

        if (!root)
            return 0;

        //求树高度 对于完全二叉树 即求最左边节点所在的层数
        int h = most_left_level(root, 1);

        //递归统计树的节点个数
        return bs(root, 1, h);
    }
};
```