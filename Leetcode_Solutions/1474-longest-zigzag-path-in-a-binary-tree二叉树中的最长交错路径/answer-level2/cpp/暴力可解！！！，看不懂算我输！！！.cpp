### 解题思路
暴力可解，使用unordered_map来进行一个访问计数，可过

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
    int max1=1;
    unordered_map<TreeNode*,int> mp;
    void preorder1(TreeNode* root,int temp,int flag)
    {
        if(mp.find(root)!=mp.end())
        return;
        if(root)
        {
            mp[root]=1;
            ++temp;
            if(temp>max1)
                max1=temp;
            if(flag==1)
                preorder1(root->right,temp,2);
            else
                preorder1(root->left,temp,1);
        }
    }
    void bianli(TreeNode* root,int temp)
    {
        if(root)
        {
            preorder1(root->left,1,1);
            preorder1(root->right,1,2);
            bianli(root->left,0);
            bianli(root->right,0);
        }
    }
    int longestZigZag(TreeNode* root) {
        bianli(root,0);
        return max1-1;
    }
};
```