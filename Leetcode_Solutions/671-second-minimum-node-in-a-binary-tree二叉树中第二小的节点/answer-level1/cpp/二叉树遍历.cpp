### 解题思路
在比最小的那个值大的所有值里面找一个最小的就行了。

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
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
        return -1;
        int ans = max(root->left->val, root->right->val);
        search(root, root->val, ans);
        if(!flag)
        return -1;
        return ans;
    }
    void search(TreeNode* node, int smallest, int &ans)
    {
        if(node == NULL)
        return ;
        if(node->val > smallest)
        {
            ans = min(ans, node->val);
            flag = true;
            return ;
        }
        search(node->left, smallest, ans);
        search(node->right, smallest, ans);
    }
private:
    bool flag = false;
};
```