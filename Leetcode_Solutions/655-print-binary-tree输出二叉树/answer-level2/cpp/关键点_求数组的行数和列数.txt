### 解题思路

根据题意可知，(1)数组的行数即树的高度
            (2)列数即为(2^height)-1。
            (3)填充数字时，动态维护l与r的值即可，每次都放在mid位置


       

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
    int getHeight(TreeNode* root)
    {
        if(root)
        {
            return max(getHeight(root->left),getHeight(root->right))+1;
        }
        return 0;
    }
    void fill(TreeNode* root,vector<vector<string>>& res,int l,int r,int hight)
    {
        if(root)
        {
            int mid=(l+r)/2;
            res[hight][mid]=to_string(root->val);
            fill(root->left,res,l,mid-1,hight+1);
            fill(root->right,res,mid+1,r,hight+1);
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int m=getHeight(root);
        int n=pow(2,m);
        vector<vector<string>> res(m,vector<string>(n-1,""));
        fill(root,res,0,n-1,0);
        return res;
    }
};
```