### 解题思路
遍历的时候给节点加一个编号，然后记忆化遍历就好
让后利用a+b=c 推导a=b-c，继而a*b=a*(c-a)
最后遍历一下节点取最大值即可

### 代码

```cpp
typedef long long ll;
const int maxn=5e5+5;
const int mod=1e9+7;
class Solution {
public:
    ll dp[maxn],idx=0,cntSum=0,ans=0,id=0;
    ll sum(TreeNode* root){
        if(root==NULL)return 0;
        return dp[id=idx++]=root->val+sum(root->left)+sum(root->right);
    }
    int maxProduct(TreeNode* root) {
        cntSum=sum(root);
        for(int i=1;i<idx;++i)
            ans=max(ans,(cntSum-dp[i])*dp[i]);
        return ans%mod;
    }
};
```