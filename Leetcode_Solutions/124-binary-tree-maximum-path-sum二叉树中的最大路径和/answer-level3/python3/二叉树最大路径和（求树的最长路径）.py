### 题意：

实际，这个考点就是求树上权值和最大的一条路径。

分析一下，假如得到在u点为根的子树里(**除了**下面红色的情况的)权值和最大的路径为**sum(u)**, 那么往下分析：


![图片.png](https://pic.leetcode-cn.com/bc8665aded704a30690dfdca8e9b3e5aec470a031701b223f02e11add8555bc0-%E5%9B%BE%E7%89%87.png)

sum(u)= max(u.val , u.val + sum(u.right), u.val + sum(u.left))

而最终的答案再把上面红色的情况考虑进去:

ans = max(sum(u), **u.val + sum(u.right)+sum(u.left)** )= max(u.val , **u.val + sum(u.right)+sum(u.left)**, u.val + sum(u.right), u.val + sum(u.left)))

### 代码:

c++
```c++
class Solution {
public:
    int ans;
    int dfs(TreeNode* root, int & ans){
        if(root==NULL) return 0;
        int left = max(dfs(root->left, ans), 0);
        int right = max(dfs(root->right, ans), 0);
        ans = max(ans, root->val+left+right);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        int tmp  = dfs(root,ans);
        return ans;
    }
};
```
python
```py

class Solution:
    def dfs_sum(self, root: TreeNode):
        if root == None: return 0
        val = root.val
        sum_l = max(0, self.dfs_sum(root.left))
        sum_r = max(0, self.dfs_sum(root.right))
        self.ans = max(self.ans, sum_l + sum_r + val)
        return  max(sum_l , sum_r) + val
    
    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = - 1e9
        self.dfs_sum(root)
        return self.ans
```