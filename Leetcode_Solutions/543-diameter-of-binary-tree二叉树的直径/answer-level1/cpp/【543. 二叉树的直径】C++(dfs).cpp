### 解题思路
求直径问题可以转化成求每个结点为根结点的左右子树深度之和(L+R)

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
    // 将问题转化成dfs，递归求各个结点的左右子树深度
    // 最长路径为L+R+1
    int max_road = 1;   //全局变量，维护最长路
    int depth(TreeNode* rt){
        if(rt == NULL)
            return 0;
        int L = depth(rt->left);
        int R = depth(rt->right);
        max_road = max(max_road, L+R+1);
        // cout<<"max road: "<<max_road<<endl;
        return max(L,R)+1; //左右子节点的最大深度+1
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_road-1;
    }
};
```