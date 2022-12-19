### 解题思路
遍历树的思想除了四种遍历之外，也可以考虑下搜索的方式，我认为本题有点像是深搜里面一种重要题型
选与不选问题，因为当前结点下，你要么往左子树去，要么往右子树去，即二者选一个，这样子去搜索即可
f用来记录是否找到答案，如果说已经找到了，就没有必要再去接着搜索了，因为只是判断是否有这样的方案
而已，这也算是唯一的优化了把（PS：因为菜），因为使用了递归的形式A的，所以时间复杂度，有一点高。


### 代码

```cpp
class Solution {
public:
    bool f = false;

//cur记录当前的和，sum为目标和
    void dfs(TreeNode* root,int cur,int sum){
        if(f) return;
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL){
            if(cur + root->val==sum) f = true;
            return;
        }
        dfs(root->left,cur+root->val,sum);
        dfs(root->right,cur+root->val,sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL && sum != 0) return false;
        dfs(root,0,sum);
        return f;     
    }
};
```