### 解题思路
**参考回答**
参考了精选回答“*三种方法解决树形动态规划问题-从入门级代码到高效树形动态规划代码实现* ”的思路，具体如何得到最优子结构，大家可以详细看看上面的回答，写得很清楚，这里主要针对C++做些补充

**最优子结构**
因为不能连续访问相邻的节点，所以最优子结构为：max(爷爷的钱+孙子的钱，儿子的钱)

**方法补充**
- 第1种方法（暴力递归）：用C++实现会提示超出时间限制
- 第2种方法（记忆+递归）：最关键的地方在于用unordered_map保存每个节点的最高金额，其中将每个节点作为key，将每个节点的最高金额作为value

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
    /*用unordered_map保存每个节点的最高金额*/
    int rob_dp(TreeNode* root,unordered_map<TreeNode*,int>&info)
    {
        if (root==NULL)
        {
            return 0;
        }
        if (info.find(root)!=info.end())  //如果该节点已经计算过，则不用再重复计算
        {
            return info[root];
        }
        int money=root->val;
        if (root->left!=NULL)
        {
            money+=rob_dp(root->left->left,info)+rob_dp(root->left->right,info);
        }
        if (root->right!=NULL)
        {
            money+=rob_dp(root->right->left,info)+rob_dp(root->right->right,info);
        }
        int result=max(money,rob_dp(root->left,info)+rob_dp(root->right,info));
        info.insert(make_pair(root,result));
        return result;
    }
    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode*,int>temp;
        return rob_dp(root,temp);
    }
};
```