### 解题思路
执行用时 :4 ms , 在所有 C++ 提交中击败了 94.71% 的用户
内存消耗 :19 MB, 在所有 C++ 提交中击败了 100.00% 的用户
特殊情况：
root == NULL return true;
root只有一个节点 return true;
层次遍历：
对每层的结果放在res；数组中，然后在对每层遍历之后，将结果进行回文判断
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        queue<TreeNode*> list;
        int len = 0,len1=0;
        TreeNode* p;
        vector<int> res;
        list.push(root->left);
        list.push(root->right);
        while(!list.empty())
        {
            res.clear();
            len = list.size();
            for(int i=0;i<len;i++)
            {
                p = list.front();
                list.pop();
                if(p == NULL)
                    res.push_back(-1);
                else
                {
                    res.push_back(p->val);
                    list.push(p->left);
                    list.push(p->right);
                }

            }
            len1 = res.size();
            for(int i=0;i<(len1/2);i++)
            {
                if(res[i] != res[len1 - 1 - i]) 
                    return false;
            }

        }
        return true;
    }
};
```