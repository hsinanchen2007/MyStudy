用一个哈希表`maxpath_memo`记录以某个节点为根的子树的最小路经，当哈希表中存在值时，直接返回，减少递归次数

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
    int sum = std::numeric_limits<int>::min();
    int maxPathSum(TreeNode* root)
    {
        map<TreeNode*, int> maxpath_memo;
        //dynamix pragramming with memoization
        memoMaxPathSum(root, maxpath_memo);
        return sum;
    }

    /**
    * @name     memoMaxPathSum
    * @brief    dfs with memoization
    *
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-27 12:56:38
    * @return
    *
    **/
    int memoMaxPathSum(TreeNode* node, map<TreeNode*, int>& memo)
    {
        if (node == NULL) {
            return 0;
        }

        if (memo.find(node)!=memo.end()){
            return memo.at(node);
        }

        int left_path = memoMaxPathSum(node->left, memo);
        int right_path = memoMaxPathSum(node->right, memo);

        int x= max(node->val, max(node->val + left_path, max(node->val + right_path, max(node->val + left_path + right_path, node->val))));
        sum = max(sum, x);

        int max_path = node->val + max(left_path, max(right_path, 0));
        memo[node] = max_path;

        return max_path;
    }
};
```


