![微信图片_20191123221245.png](https://pic.leetcode-cn.com/7d7f3719f6487284dcd48c8938823e97208a26537e1352909d94518a8a97e393-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191123221245.png)

```
class Solution {
public:
    int res;
    int sumNumbers(TreeNode* root) {
        if(root== nullptr)
            return 0;
        return dfs(root,0);
    }
    int dfs(TreeNode* root,int sum){
        if(!root->left&&!root->right){
            sum=root->val+sum*10;
            res+=sum;
        }
        if(root->left){
            sum=root->val+sum*10;
            dfs(root->left,sum);
            sum=(sum-root->val)/10;
        }
        if(root->right){
            sum=root->val+sum*10;
            dfs(root->right,sum);
            sum=(sum-root->val)/10;
        }
        return res;
    }
};
```
