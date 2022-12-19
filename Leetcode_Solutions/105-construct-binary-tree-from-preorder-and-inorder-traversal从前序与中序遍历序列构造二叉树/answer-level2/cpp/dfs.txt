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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        TreeNode* res = new TreeNode(preorder[0]);
        res->left = dfs(0,map[preorder[0]]-1,1, preorder,map);
        res->right = dfs(map[preorder[0]]+1,preorder.size()-1,map[preorder[0]]+1,preorder,map);
        return res;
    }
    
    TreeNode* dfs(int start, int end, int index, vector<int>& preorder, map<int,int>& map){
        if(index>=preorder.size()) return NULL;
        if(end<start) return NULL;
        TreeNode* a=new TreeNode(preorder[index]);
        a->left = dfs(start,map[preorder[index]]-1,index+1,preorder, map);
        a->right = dfs(map[preorder[index]]+1,end,map[preorder[index]]+1+index-start,preorder, map);
        return a;
    }
};
```