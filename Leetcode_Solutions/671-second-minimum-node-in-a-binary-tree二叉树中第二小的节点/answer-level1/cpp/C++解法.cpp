### 解题思路

遍历树,如果当前节点值大于root值,更新第二小值(使用最小值初始化),此分支无需再遍历;最后比较第二小值与最小值即完成.

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
    void travelTree(TreeNode *node, int min_val, int *second_val)
    {
        if (node != NULL)
        {
            if (node->val > min_val)
            {
                if (min_val == *second_val)
                {
                    *second_val = node->val;
                }
                else
                {
                    *second_val = std::min(*second_val, node->val);
                }
                return;
            }
            travelTree(node->left, min_val, second_val);
            travelTree(node->right, min_val, second_val);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL)
            return -1;
        int min_val = root->val;
        int second_val = min_val;
        
        travelTree(root, min_val, &second_val);
        if (second_val == min_val)
            return -1;
        else
            return second_val;
    }
};
```