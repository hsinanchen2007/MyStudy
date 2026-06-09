### 解题思路
先中序遍历，将遍历结果存到队列，然后返回队列的倒数第K个元素即可   （关注微信公众号'码农黑板报'获取更多题解）
![image.png](https://pic.leetcode-cn.com/126838b02f49cabd6723c9d98e9c3b8edae4da6b0998ed20bd277c1f2818851c-image.png)


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
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        dfs(res, root);
        return res[res.size() - k];
    }

    void dfs(vector<int>& res, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        dfs(res, root->left);
        res.push_back(root->val);
        dfs(res, root->right);
    }
};
```