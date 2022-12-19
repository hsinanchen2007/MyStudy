首先序列化二叉树，由于哈希一次的长度跟节点个数成正比，也就是o(n)，需要哈希n次，总的时间复杂度就是o(n^2),我采用哈希两遍的方式，先将序列化后的字符串用一个不同的int数字表示即可，再看int出现的次数，那么每个字符串长度变成了三个int，所以时间复杂度降为o(n)。
```
class Solution {
public:
    unordered_map<string,int> hash;
    unordered_map<int,int> count;
    int cnt = 0;
    vector<TreeNode*> res;

    string dfs(TreeNode* root)
    {
        if(!root) return to_string(hash["#"]);
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        string tree = to_string(root->val) + ',' + left + ',' + right;
        if(!hash.count(tree)) hash[tree] = ++cnt;
        int t = hash[tree];
        count[t]++;
        if(count[t] == 2) res.push_back(root);

        return to_string(t);
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        hash["#"] = cnt;
        dfs(root);
        return res;
    }
};
```
