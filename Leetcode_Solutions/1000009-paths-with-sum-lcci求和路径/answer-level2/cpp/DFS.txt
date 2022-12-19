### 解题思路
https://www.***.org/count-all-k-sum-paths-in-a-binary-tree/
Geek上看到的解法，加了一点自己的理解注释，如有错误，还请指正！

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
    void count_path(TreeNode* root, int path_sum, int& count, int target_sum, unordered_map<int,int>& p){
        if(root){
            if(path_sum+root->val==target_sum)
                count++;

            count+=p[path_sum+root->val-target_sum];//如果和当前值相差k的位置A的标记是1，那么也加上，因为存在从A节点之后到达当前root的一个新的和值为k的路径

            p[path_sum+root->val]++;//进入决策点root
            count_path(root->left, path_sum+root->val, count, target_sum, p);
            count_path(root->right, path_sum+root->val, count, target_sum, p);
            p[path_sum+root->val]--;//出决策点root    
        }
        
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        int path_sum = 0;
        int count = 0;
        unordered_map<int, int>p;
        count_path(root, path_sum, count, sum,p);
        return count;
    }
};
```