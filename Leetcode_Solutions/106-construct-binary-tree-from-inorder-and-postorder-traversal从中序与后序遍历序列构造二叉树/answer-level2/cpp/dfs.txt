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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        int insize = inorder.size();
        int postsize = postorder.size();
        TreeNode* root = new TreeNode(postorder[postsize-1]);
        root->left = dfs(0,map[postorder[postsize-1]]-1,postorder,map,postsize-1-(insize-1-map[postorder[postsize-1]])-1);
        root->right = dfs(map[postorder[postsize-1]]+1,insize-1,postorder,map,postsize-2); 
        return root;
    }

    TreeNode* dfs(int start, int end, vector<int>& postorder, map<int,int>& map, int index){
        if(end<start) return NULL;
        TreeNode* res = new TreeNode(postorder[index]);
        res->left = dfs(start, map[postorder[index]]-1, postorder, map, index-(end-map[postorder[index]])-1);
        res->right = dfs(map[postorder[index]]+1, end, postorder, map, index-1);
        return res;
    }
};
```