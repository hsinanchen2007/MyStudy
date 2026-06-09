### 解题思路
使用队列进行层次遍历，如果节点的值是偶数，将其子节点的子节点的值加起来。

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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> tq;
        tq.push(root);
        while(!tq.empty())
        {
            TreeNode* p = tq.front();
            if(p->left)
            {
                tq.push(p->left);
                if(p->val % 2 == 0)
                {
                    if(p->left->left)
                    {
                        ans += p->left->left->val;
                    }
                    if(p->left->right)
                    {
                        ans += p->left->right->val;
                    }
                }
            }
            if(p->right)
            {
                tq.push(p->right);
                if(p->val % 2 == 0)
                {
                    if(p->right->left)
                    {
                        ans += p->right->left->val;
                    }
                    if(p->right->right)
                    {
                        ans += p->right->right->val;
                    }
                }
            }
            tq.pop();
        }
        return ans;
    }
};
```

### 复杂度分析
时间复杂度：$O(N)$，其中 $N$ 是该二叉树的节点数。
空间复杂度：$O(N)$，队列 `tq`。