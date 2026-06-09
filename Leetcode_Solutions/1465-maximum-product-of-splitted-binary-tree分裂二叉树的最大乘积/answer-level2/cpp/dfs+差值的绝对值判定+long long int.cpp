### 解题思路
1. 通过后序遍历，对于每个节点，记录下其与子树的数值之和
2. 要得到最大乘积，若sum=x[i]+y[i],则x[i]与y[i]差值的绝对值必然最小（均值不等式可以说明），通过sum-2*x[i]的绝对值可以判定当前方案是否需要更新，得出最优res，(sum-res)与res的乘积即为最大乘积
3. res需定义为long long int，否则通过不了最后一个测试用例

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
    int dfs(TreeNode* root,vector<int>& t){
        if(root==NULL)
            return 0;
        else{
            int all=dfs(root->left,t)+dfs(root->right,t)+root->val;
            t.push_back(all);
            return all;
        }
    }
    int deal(int sum,int x){
        if(sum-2*x<0)
            return 2*x-sum;
        else
            return sum-2*x;
    }
    int maxProduct(TreeNode* root) {
        vector<int> t;
        int sum=dfs(root,t);
        long long int res=t[0];
        for(int i=0;i<t.size();i++)
            if(deal(sum,t[i])<deal(sum,res))
                res=t[i];
        res=res*(sum-res);
        return res%(1000000000+7);
    }
};
```