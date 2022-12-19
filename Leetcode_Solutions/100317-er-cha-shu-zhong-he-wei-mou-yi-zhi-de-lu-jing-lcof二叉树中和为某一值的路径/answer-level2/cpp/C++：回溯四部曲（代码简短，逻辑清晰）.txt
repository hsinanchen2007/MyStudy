**题解：**
* 回溯法

**算法步骤（回溯四部曲）：**
* 1）choose：将 root->val 加入决策track
* 2）进入下一次决策：递归左子树、右子树
* 3）unchoose：将达到叶子节点的 val 移出决策路径
* 4）找到可行解：到达叶子节点，且 sum==root->val 

**代码如下：**
```cpp
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)return {};
        vector<vector<int>> res;
        vector<int> track;
        backtrack(root,sum,res,track);
        return res;
    }

    void backtrack(TreeNode* root,int sum,vector<vector<int>>& res,vector<int> track){
        //1、choose：加入决策路径
        track.push_back(root->val);
        if(sum==root->val&&!root->left&&!root->right)//找到可行解：到达叶子节点且root->val==sum
            res.push_back(track);
        //2、进入下一次决策
        if(root->left)backtrack(root->left,sum-root->val,res,track);
        if(root->right)backtrack(root->right,sum-root->val,res,track);
        //unchoose：移出决策路径
        track.pop_back();
    }
};
```
