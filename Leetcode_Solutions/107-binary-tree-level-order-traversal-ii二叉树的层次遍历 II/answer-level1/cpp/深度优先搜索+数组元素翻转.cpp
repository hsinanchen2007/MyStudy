### 解题思路
1. 按照传统的dfs生成从根到叶子节点的层次遍历结果
2. 将1.的结果进行翻转（逆置）得到最终结果


**代码易懂**

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
    vector<vector<int>> ans;

    void reverse(vector<vector<int>>& ans){
        int len = ans.size()-1;
        int mid = len / 2;
        int i = 0;
        while(i<=mid){
            ans[i].swap(ans[len-i]); 
            i++;
        }
    }

    void dfs(TreeNode* root, int depth){
        if(depth == ans.size())
            ans.emplace_back();
        ans[depth].push_back(root->val);
        if(root->left) dfs(root->left, depth+1);
        if(root->right) dfs(root->right, depth+1);
    }   

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return ans;
        dfs(root, 0);
        reverse(ans);
        return ans;
    }
};
```