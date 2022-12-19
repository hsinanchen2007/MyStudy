### 解题思路
    打卡学习 ~ ~ ~
### 代码

```cpp
class Solution {
public:
    //获取树的高度
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
    //填充 二维数组res
    void fill(TreeNode* root,vector<vector<string>>& res,int depth,int l,int r){
        if(!root) return ;
        int mid = l + (r - l) / 2;
        res[depth][mid] = to_string(root->val);
        //递归填充
        fill(root->left,res,depth + 1,l,mid - 1);
        fill(root->right,res,depth + 1,mid + 1,r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int w = (1 << h) - 1;   //res数组的列宽 = 2^h - 1
        vector<vector<string>> res(h,vector<string>(w,""));
        fill(root,res,0,0,w - 1);
        return res;
    }
};
```