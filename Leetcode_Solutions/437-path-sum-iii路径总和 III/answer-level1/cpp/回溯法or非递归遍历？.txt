1. 一开始我在想用非递归遍历这个数组，然后维护到每个节点的路径和的字典。但是由于每个节点需要维护一个额外数据结构，空间复杂度到了o(nlgn),难以优化到o(lgn),于是放弃。
2. 还是递归回溯能提供o(n)时间复杂度和o(lgn)的空间复杂度。
```
class Solution {
private:
    int ans;
    unordered_map<int,int> s; //为了求数组中连续和的时间复杂度达到o(1)，空间换时间
public:
    void dfs(TreeNode* root,int sum,int count)
    {
        if(root == nullptr)
            return;
        count += root->val;
        ans += s[count-sum]; 
        s[count]++;//更新s
        dfs(root->left,sum,count);
        dfs(root->right,sum,count);
        s[count]--;//恢复s
        return;
    }
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        s[0] = 1;
        dfs(root,sum,0);
        return ans;
    }
};
```
