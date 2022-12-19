### 解题思路
总体思路：
左子相同搜左子树，返回左子树第二小的值（最小值是左子树根节点）然后和右子相比取最小值，然后返回，这个值肯定是第二小的，最小的是根节点
右子相同搜右子，然后同上
两个都一样，两边都继续搜

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
//总体思路：
//左子相同搜左子树，返回左子树第二小的值（最小值是左子树根节点）然后和右子相比取最小值，然后返回，这个值肯定是第二小的，最小的是根节点
//右子相同搜右子，然后同上
//两个都一样，两边都继续搜
//可以用这个函数返回以root为根的第二小的数

    int findSecondMinimumValue(TreeNode* root) {
    //考虑边界
        if(root == NULL) return -1;
        if(root->left ==  NULL) return -1;
        int leftval = root->left->val;
        int rightval = root->right->val;
//如果左子值一样，那么继续搜左子树的第二小值，第一小值是leftval
        if(root->val == leftval) leftval = findSecondMinimumValue(root->left);
//如果右子值一样，那么继续搜右子树的第二小值
        if(root->val == rightval) rightval = findSecondMinimumValue(root->right);
 //如果两子值都一样，那么两个都会继续搜
 //此时就不用分类讨论了，反正搜的是左子树的第二小值和右子结点取个最小值就是以root为根的第二小值了（最小值是root->val,root->left->v）
 //如果搜的是右子树也是一个道理
        if(leftval != -1 && rightval != -1)
          return min(leftval,rightval);
//如果右子相同，搜右树，右树为空，直接返回第二小值左子（而不用搜左子树的原因是左子树所有结点的值肯定都大于左子树根节点的值）
        if(leftval != -1) return leftval;
        return rightval;
    }
};
```