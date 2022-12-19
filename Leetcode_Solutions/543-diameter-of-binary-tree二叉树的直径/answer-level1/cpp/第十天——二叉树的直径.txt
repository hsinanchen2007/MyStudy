### 解题思路

题意等价于求每个节点的左右子树最大深度之和的最大值。

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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        MaxDepthOfLR(root);
        return diameter;
    }
    pair<int, int> MaxDepthOfLR(TreeNode* root){ //返回左右子树的深度最大值
        pair<int, int> result;
        pair<int, int> tmp;        

        if(!root) return {-1, -1};	//如果设为{0， 0}，会多出连接两个空指针的边
        tmp = MaxDepthOfLR(root->left);
        result.first = max(tmp.first, tmp.second) + 1;
        tmp = MaxDepthOfLR(root->right);
        result.second = max(tmp.first, tmp.second) + 1;

        diameter = (result.first+result.second > diameter)?(result.first+result.second):diameter;
        return result;
    }
};
```



