C++代码如下，这里只解释一下函数pathSum()，由于题目要求“路径不需要从根结点开始”，也就是说路径可以从二叉树中的任意节点开始，那么我们就需要将二叉树中的所有结点都考虑一遍，可以使用遍历来实现，当然也可以将其改为递归写法，递归可能理解起来没有遍历那么直观，但我们可以通过遍历写法来理解递归写法具体做了哪些工作。
```cpp
class Solution
{
private:
    vector<TreeNode*> vec;

    int findPath(TreeNode *root, int num)
    {
        if (NULL == root)
        {
            return 0;
        }

        int res = 0;
        if (num == root->val)
        {
            res += 1;
        }

        res += findPath(root->left, num - root->val);
        res += findPath(root->right, num - root->val);

        return res;
    }

    // 中序遍历二叉树，将结点保存在vec数组中
    void preOrder(TreeNode *root)
    {
        if (NULL == root)
        {
            return;
        }

        vec.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }

public:
    int pathSum(TreeNode* root, int sum)
    {
        if (NULL == root)
        {
            return 0;
        }

        int res = 0;
        preOrder(root);
        for (auto p : vec)
        {
            res += findPath(p, sum);
        }
        
        return res;
    }
};
```
