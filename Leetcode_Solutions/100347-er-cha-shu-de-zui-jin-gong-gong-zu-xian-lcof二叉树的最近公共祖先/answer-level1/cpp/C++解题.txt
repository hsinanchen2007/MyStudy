### 解题思路
只想到笨方法。
1、首先分别找到p、q的最短路径，从下往上排序。
例如 root = [3,5,1,6,2,0,8,null,null,7,4]，找7，列表为7 2 5 3

2、再从两个队列中找到队列中最靠前相等的node

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
    bool mFind = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1; 
        vector<TreeNode*> v2;
        mFind = false;
        find(root, p, v1);
        mFind = false;
        find(root, q, v2);

        for (int i = 0; i < v1.size(); i++)
        {
            for (int j = 0; j < v2.size(); j++)
            {
                if (v1[i]->val == v2[j]->val)
                {
                    return v1[i];
                }
            }
        }

        return root;
    }

    void find(TreeNode* node, TreeNode* n, vector<TreeNode*> &v)
    {
        if (node != NULL && !mFind)
        {
            if (node->val == n->val)
                mFind = true;
           
            find(node->left, n, v);
            find(node->right, n, v);

            if (mFind)
                v.push_back(node);
        }
    }
};
```