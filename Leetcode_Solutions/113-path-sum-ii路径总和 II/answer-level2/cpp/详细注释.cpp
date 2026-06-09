### 解题思路

 // 那就的用个 vector 保存一条路径， 路径中放置合适的节点，当节点满足时，就添加到路径中，不满足时就回退此节点，
 // 这其实就是回溯法。
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
 // 那就的用个 vector 保存一条路径， 路径中放置合适的节点，当节点满足时，就添加到路径中，不满足时就回退此节点，
 // 这其实就是回溯法。
class Solution {
        vector<vector<int>> res; // 最终的返回结果。
        vector<int> onePath; // 保存一条路径。
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        backTrack(root, sum);
        return res;
    }

    void backTrack(TreeNode* root, int sum) {
        if (root == NULL) {
            return;
        }
        onePath.push_back(root->val); //不等于空，就先入vector，从底部进，待会从底部出。
        sum = sum - root->val;  // 此节点 添加后，减去此节点的值。
        if (root->left == NULL && root->right == NULL) { //说明时叶子节点
            if (sum == 0) { // sum已经减去了 root->val, 看此叶子节点是否满足路径上的最后一个，是则说明此路径已经找到，将路径添加到结果中。
                res.push_back(onePath); // Pathsum问题就是在遍历到叶节点时，路径最长时，将需要的路径保存下来。
                // return;// 这里添加完后如果return的话，则会跳过后面的pop_back操作而出错。要保存的时所有路径。
            }
        }
        // 如果发现 root不是叶子节点，那就的看左右子树是不是满足
        backTrack(root->left, sum);
        backTrack(root->right, sum);

        // 需要回溯: 因为要的是所有路径，从哪个节点进来，就从哪个节点退出去。
        sum = sum + root->val;
        onePath.pop_back();
    }
};
```