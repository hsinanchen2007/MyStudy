### 解题思路
C++递归实现
![图片3.png](https://pic.leetcode-cn.com/c5462c49587f7216d23b564ab0644b2d171e418c25fdf185eac13cf922c12e73-%E5%9B%BE%E7%89%873.png)

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
private:
    int ans = 0;
    int DFS(TreeNode* root){
        if(!root){return 0;}
        int L = DFS(root->left),  R = DFS(root->right);
        ans += abs(L)+abs(R);
        return root->val+L+R-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        DFS(root);
        return ans;
    }
};
```