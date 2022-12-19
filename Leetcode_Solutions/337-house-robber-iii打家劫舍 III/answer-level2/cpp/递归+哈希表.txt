基本思想：
对于任意节点，如果父节点打劫过，则只能从左右子树开始打劫；
否则，有两个选择：打劫当前节点或不打劫，再从左右子树打劫。
为了减少重复计算，利用哈希表记录节点的打劫情况, m[root][0]记录打劫当前节点时的获利，m[root][1]记录不打劫当前节点时的获利。
时间复杂度O(n)，每个节点遍历一次。
空间复杂度O(n)，递归和哈希表开销。
```
class Solution {
    unordered_map<TreeNode*,vector<int>> m;
public:
    int helper(TreeNode* root,bool isrob) //isrob 记录父节点是否打劫过
    {
        if(root==0)
        return 0;
        if(m.count(root)==0)
        {
            int x1=helper(root->left,false);
            int x2=helper(root->right,false);
            int y1=helper(root->left,true);
            int y2=helper(root->right,true);
            m[root].push_back(x1 + x2);
			m[root].push_back(max(root->val + y1 + y2, x1 + x2));
        }
        if(isrob)
            return m[root][0];
        else
            return m[root][1];
    }
    int rob(TreeNode* root) 
    {
        return helper(root,false);
    }
};
```
