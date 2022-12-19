### 解题思路
首先前序遍历二叉树，为所有结点计数；

依赖map会自动排序的能力

计数结束后，如果计数器总数只有1，那么说明所有结点都相同，第二小的节点不存在；
如果计数器总数大于1，输出计数器第二个键值即可。

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
    map<int, int> counter;
    void cou(TreeNode* root)
    {
        if (root == NULL)
            return ;
        else
        {
            counter[root->val] += 1;
            cou(root->left);
            cou(root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        cou(root);

        int ans = 0;
        if (counter.size() == 1)
            ans = -1;
        else
        {
            int i = 1;
            for (auto n:counter)
            {
                if (i == 2)
                {
                    ans = n.first;
                    break;
                }
                i++;
            }
        }

        return ans;
    }
};
```