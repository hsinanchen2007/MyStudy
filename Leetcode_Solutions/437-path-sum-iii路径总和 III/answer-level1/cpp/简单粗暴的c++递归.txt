### 解题思路
这道题的关键点：路径，终点不一定是叶子结点；起点不一定是根节点；
所以，我们一开始想到，以每一个结点开始的路径和都有可能是sum;
首先，我们要写一个函数，这个函数是求路径和的，如果路径和=sum，全局变量count++；
然后在通过前序遍历的方式对每个结点的路径都求一遍即可；

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
    int count=0;
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return 0;
        pathSum(root->left,sum);
        pathSumHelper(root,sum);
        pathSum(root->right,sum);

        return count;
    }
    void pathSumHelper(TreeNode* root, int sum) {
        if(root==nullptr) return;
        if(root->val==sum) ++count;
        pathSumHelper(root->left, sum-root->val) ;
        pathSumHelper(root->right, sum-root->val) ;
    }
};
```