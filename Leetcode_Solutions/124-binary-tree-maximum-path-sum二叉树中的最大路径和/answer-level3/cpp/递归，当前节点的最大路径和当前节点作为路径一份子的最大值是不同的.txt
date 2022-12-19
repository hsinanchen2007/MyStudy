### 解题思路
一个节点所有的路径  和  一个节点作为路径中一份子 所构成的路径 是不一样的！
在计算全局最大值和返回当前节点最大值时要注意区别！

一个 根，左，右 的路径情况有（根，左+根，根+右，左+根+右）
但是该根作为其父亲的孩子时，其max 应该为 max（根，左+根，根+右）.如果包含左+根+右，则加上其父亲就构不成路径了

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
    //一个 根，左，右 的路径情况有（根，左+根，根+右，左+根+右）
    //但是该根作为其父亲的孩子时，其max 应该为 max（根，左+根，根+右）.如果包含左+根+右，则加上其父亲就构不成路径了
    int maxPathSum(TreeNode* root) {
        long long gMax = LLONG_MIN;
        maxPathSumCore(root, gMax);
        return gMax;
    }

    int maxPathSumCore(TreeNode* root, long long& gMax){
        if(root==nullptr) return 0;
        int curVal = root->val;
        int leftMax = maxPathSumCore(root->left, gMax);
        int rightMax = maxPathSumCore(root->right, gMax);
        long long curMax = max(curVal, max(curVal+leftMax, max(curVal+rightMax, curVal+leftMax+rightMax)));
        if(curMax>gMax) gMax = curMax;
        return max(curVal, max(curVal+leftMax, curVal+rightMax));
    }
};
```