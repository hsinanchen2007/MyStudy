### 解题思路
  每个节点都有可能作为最长的中节点，因此就去找这个节点的左节点和右节点最长的长度。
  题目的要求是两个节点之间的最长长度，而我们已经找到每个节点返回来的最长长度。因此就只要在上一步的步骤中去寻找这个左右节点长度和的最大值就行了。具体看代码。

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
    int diameterOfBinaryTree(TreeNode* root) {
        //寻找最大值
        int maxn = 0;
        dfs(root , maxn);
        return maxn;
    }
    //用来找该节点的最大长度
    int dfs(TreeNode* root , int& maxn){
        if(root == NULL)return 0;
        //左节点的最大长度
        int l = dfs(root -> left , maxn);
        l += root -> left == NULL ? 0 : 1;
        //右节点的最大长度
        int r = dfs(root -> right , maxn);
        r += root -> right == NULL ? 0 : 1;
        //对于题目本身的答案就是，左节点和右节点的最大长度相加就是这个中节点所连接的最大长度。因此每个节点都要去判断
        maxn = max(maxn , l + r);
        //返回最大长度
        return max(l , r);
    }
};
```