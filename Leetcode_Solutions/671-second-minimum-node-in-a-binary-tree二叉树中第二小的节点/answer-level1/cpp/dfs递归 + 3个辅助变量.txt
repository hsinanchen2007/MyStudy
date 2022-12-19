dfs先序遍历树 + 3个辅助变量
- fir, sec表示遍历到目前为止第1和第2小的数
- secIsChange表示第2小的数是否发生了变化，因为存在INT_MAX的值的测试样例情况

但是我这里没有利用到题目给的条件：
- 每个节点仅有`0`个或`2`个节点数；
- 如果一个节点有`2`个节点数，那么这个节点的值不大于它子节点的值。

算是个比较通用的解法？或者很蠢的解法

```
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
private:
    int fir = INT_MAX;
    int sec = INT_MAX;
    int secIsChange = false;

    void dfs(TreeNode* root)
    {
        if (!root)  return;
        if ((root->val > fir && root->val < sec) || root->val == INT_MAX)  { sec = root->val;  secIsChange = true;}
        else if (root->val < fir)                                          { fir = root->val;  }
        dfs(root->left);
        dfs(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) 
    {
        dfs(root);

        return secIsChange?sec:-1;
    }
};
```
