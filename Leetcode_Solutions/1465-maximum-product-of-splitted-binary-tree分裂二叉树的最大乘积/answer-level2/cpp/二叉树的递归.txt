### 解题思路
![批注 2020-02-03 132454.png](https://pic.leetcode-cn.com/ec1207bd5a5ee4a31bd518984d2e03a723366e95f95533b45958366311f82539-%E6%89%B9%E6%B3%A8%202020-02-03%20132454.png)
本体的意思就是把一个二叉树的和sum分成2个数a，b且有a+b=sum，并且使a*b最大，易知当这两个数越相近时乘积越大，如果有一个数等于sum/2时a*b最大。
但是又要求a和b都是二叉树的和，先用求出以各个节点为根的子树的和并保存到降序的优先队列中，然后遍历优先队列找到离sum/2最近的一个值k，k*(sum-k)即为答案

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
    const int mod=1e9+7;
    priority_queue<int,vector<int>,less<int> >q;
    int maxProduct(TreeNode* root) {
        int sum=dfs(root);
        int ans,k=INT_MAX;
        while(k>sum/2){
            ans=k;
            k=q.top();
            q.pop();
        }
        if(k==sum/2) return (long long)(k*(sum-k))%mod;
        else return max((long long)ans*(sum-ans),(long long)k*(sum-k))%mod;
    }
    int dfs(TreeNode* root){
        int sum=root->val;
        if(root->left) sum+=dfs(root->left);
        if(root->right) sum+=dfs(root->right);
        q.push(sum);
        return sum;
    }
};
```