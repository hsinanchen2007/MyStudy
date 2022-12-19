### 解题思路
把每层的指针压入下一个要处理的vector里
![image.png](https://pic.leetcode-cn.com/d56fe8c48417c15479784ff5fe2a4eb275becd90f798b936ae66daa86c657205-image.png)

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
    vector<TreeNode*> Getv2(vector<TreeNode*> &vt, vector<vector<int>> &v2)
    {
        vector<TreeNode*> ret;
        vector<int> v1;
        for (auto tn : vt) {
            if (tn->left!=NULL) {
                ret.push_back(tn->left);
            }
            if (tn->right!=NULL) {
                ret.push_back(tn->right);
            }
            v1.push_back(tn->val);
        }
        
        v2.push_back(v1);
        return ret;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v2;
        if (root == NULL) {
            return v2;
        }

        vector<TreeNode*> vt;
        vt.push_back(root);
        while (vt.size() != 0) {
            vt = Getv2(vt, v2);
        }
        
        return v2;
    }
};
```