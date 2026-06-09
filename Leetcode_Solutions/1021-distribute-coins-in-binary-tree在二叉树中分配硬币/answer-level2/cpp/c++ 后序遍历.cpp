### 解题思路
很多题目都可以用“状态记录法”来解决，发现这个方法好像还挺好用。

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
// 状态
struct Node{
    int node_num;
    int coin_num;
    Node(int a, int b):node_num(a), coin_num(b){}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

    Node dfs(TreeNode *root, int &ans){
        if(root == nullptr) return Node{0, 0};
        Node left = dfs(root->left, ans);
        Node right = dfs(root->right, ans);
        ans += abs(left.node_num - left.coin_num);
        ans += abs(right.node_num - right.coin_num);
        return Node{left.node_num+right.node_num+1, left.coin_num+right.coin_num+root->val};
    }
};
```