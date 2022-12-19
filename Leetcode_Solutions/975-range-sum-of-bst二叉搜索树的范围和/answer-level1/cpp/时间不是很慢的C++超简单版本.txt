执行用时 :280 ms, 在所有 C++ 提交中击败了26.43%的用户
内存消耗 :41 MB, 在所有 C++ 提交中击败了96.88%的用户
```
class Solution
{
public:
    int sum = 0;//定义全局变量sum
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        search(root, L, R);//进行搜索
        return sum;
    }
    void search(TreeNode *root, int L, int R)
    {
        if (!root)
        {
            return;//如果root为空树，则退出函数
        }
        if (root->val <= R && root->val >= L)//如果root->val在L与R之中即符合条件，则加入sum并且递归对其左右子树继续进行操作
        {
            sum += root->val;
            search(root->left, L, R);
            search(root->right, L, R);
        }
        if (root->val > R)//如果当前值比R大，则只需找左子树即可
        {
            search(root->left, L, R);
        }
        if (root->val < L)//同理，如果当前值比L大，则只需找右子树即可
        {
            search(root->right, L, R);
        }
    }
};
```
