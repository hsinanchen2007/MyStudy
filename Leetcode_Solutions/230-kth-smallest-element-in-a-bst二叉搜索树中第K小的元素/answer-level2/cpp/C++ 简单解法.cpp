> 思路描述：根据二叉搜索树的特性，中序遍历是递增的。

```C++
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
private:
    int count = 0;
    int ans = 0;
public:
    void dfs(TreeNode* root, int k){
        if(root == NULL) return;
        kthSmallest(root->left, k);
        count ++;
        if(count == k) ans = root->val;
        kthSmallest(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};
```

> 迭代写法，用栈实现

```C++
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        int ans, count = 0;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            count ++;
            if(count == k) return cur->val;
            cur = cur->right;
        }
        return 0;
    }
};
```

> 分治法，首先需要知道左子树节点数目n
>
> 如果 n = k - 1，那么当前根节点即为答案
>
> 如果 n < k - 1，那么第k小的数一定在右子树中，反之一定在左子树中
>
> 但是其实对于整体性能的提升没有很明显，因为首先需要遍历整个左子树，其实也是一样的，只是这个思路很好。