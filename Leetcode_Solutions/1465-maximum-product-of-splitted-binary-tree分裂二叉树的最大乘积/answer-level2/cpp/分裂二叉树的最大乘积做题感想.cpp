### 解题思路
首先计算二叉树所有节点的总和sum，而后调用getsum（）递归函数遍历所有的左子树和右子树，等价于从原来的二叉树中分割出一个子树，从而实现题目中所说的分裂成两个子二叉树。而后只需计算分割出的子树的节点和A，剩余的部分用最初计算获得总和减去前面算出的节点和（sum-A）即可获得。不断更新全局变量ans的值。
两个陷阱。第一个审题不仔细，忽略了要把结果%1e9+7，从而导致结果错误。第二个陷阱为两个递归函数带来的超时。故采用空间换时间思想，在计算sum的时候，将每一个子树的和保存到map中（findsum），而后在使用getsum查找最大分裂方式的时候，就可以直接使用map进行查找，减少了调用递归函数再进行重复计算所花费的时间
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

    long long int ans = 0;
    long long int MAX = 1e9+7;
    map<TreeNode*, int> findsum;

    int calsum(TreeNode* root)
    {
        if(root == NULL) 
        {
            findsum[root] = 0;
            return 0;
        }
        int sum = root->val + calsum(root->left) + calsum(root->right);
        findsum[root] = sum;
        return sum;
    }

    void getsum(TreeNode* root, int sum)
    {
        if(root == NULL) return;
        long long int newleftsum,newrightsum;
        newleftsum = findsum[root->left];
        newrightsum = sum - newleftsum;
        if(newleftsum * newrightsum >= ans)
        { 
            ans = newleftsum * newrightsum;
        }
            getsum(root->left, sum);

        newrightsum = findsum[root->right];
        newleftsum = sum - newrightsum;
        if(newleftsum * newrightsum >= ans)
        { 
            ans = newleftsum * newrightsum;
        }
           getsum(root->right, sum);
    }

    int maxProduct(TreeNode* root) {
        int sum, res;
        sum = calsum(root);
        getsum(root, sum);
        res = ans % MAX;
        return res;
    }
};
```