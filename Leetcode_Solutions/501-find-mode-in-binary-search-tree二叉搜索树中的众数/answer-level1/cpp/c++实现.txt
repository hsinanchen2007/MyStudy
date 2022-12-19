### 解题思路
通过大佬题解 了解二叉搜索树的一个重要特性是中序遍历递增，那么根据这个特性可以很容易的得到一个递增的数组，然后对该数组进行判断即可得出结果
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
    vector<int> vec;
    vector<int> result;
    int max = 0;
    int cur = 0;
    vector<int> findMode(TreeNode* root) {
        LDR(root);
        if(vec.size()==1)
        {
            result.push_back(vec[0]);
        }
        for(int i=1; i<vec.size(); i++)
        {
            if(vec[i]==vec[i-1])
            {
                cur++;
            }
            else{
                cur = 0;
            }
            if(cur == max)
            {
                if(i==1 && cur ==0)
                {
                    result.push_back(vec[0]);
                }
                result.push_back(vec[i]);
            }
            else if(cur >max)
            {
                result.clear();
                max = cur;
                result.push_back(vec[i]);
            }
        }

        return result;
    };
    void LDR(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        LDR(root->left);
        vec.push_back(root->val);
        LDR(root->right);
    }
};
```