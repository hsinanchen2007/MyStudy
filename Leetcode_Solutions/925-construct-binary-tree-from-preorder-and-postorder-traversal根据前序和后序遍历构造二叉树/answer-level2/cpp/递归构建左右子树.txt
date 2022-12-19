### 解题思路

递归。

执行用时 :4 ms

### 代码

```cpp
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return buildTree(pre, post, 0, 0, pre.size());
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& post, int preBegin, int postBegin, int len) {
        if(len == 0)
            return nullptr;
        if(len == 1)
            return new TreeNode(pre[preBegin]);
        int rootVal = pre[preBegin];
        TreeNode *root = new TreeNode(rootVal);
        int leftVal = pre[preBegin + 1];
        int i;
        for(i=postBegin; i<postBegin + len - 1; i++) {
            if(post[i] == leftVal)
                break;
        }
        int leftLen = i - postBegin + 1;
        int rightLen = len - leftLen - 1;
        // cout << leftLen << "," << rightLen << endl;
        TreeNode* left = buildTree(pre, post, preBegin + 1, postBegin, leftLen);
        TreeNode* right = buildTree(pre, post, preBegin + leftLen + 1, postBegin + leftLen, rightLen);
        root->left = left;
        root->right = right;
        return root;
    }
};
```