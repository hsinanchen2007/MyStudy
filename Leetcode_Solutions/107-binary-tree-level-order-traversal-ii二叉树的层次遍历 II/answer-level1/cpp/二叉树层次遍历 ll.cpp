### 解题思路
此处撰写解题思路

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
    vector<vector<int>> aa;
    vector<vector<int>> levelOrderBottom(TreeNode* root,int a=0) {
        
        if(root==NULL)
            return aa;
            if(a>=aa.size())
            aa.push_back(vector<int>{});
            aa[a].push_back(root->val);
       levelOrderBottom(root->left,a+1);
        levelOrderBottom(root->right,a+1);

        return vector<vector<int>>(aa.rbegin(),aa.rend());
    }
    vector<vector<int>>  wasp(vector<vector<int>> aa){
        int len=aa.size();
        int i,j=len;
        vector<vector<int>> a;
        for(i=0;i<len;i++){
             if(i>=a.size())
            a.push_back(vector<int>{});
            a[i]=aa[--j];
        }
        return a;
    }

};
```