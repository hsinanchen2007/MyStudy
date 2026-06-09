### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/9a9276f4958de813db47822cfa325a833fe392eb6d607bb02e72643d7b12b834-%E6%8D%95%E8%8E%B7.PNG)
以当前节点为curr，递归遍历：
所有满足sum和的路径其要么从curr出发（curr作为根节点）；要么对curr的左、右子树递归调用。
（1）第一种情况->以curr为路径根节点
   这种情况直接采用一次DFS，先判断curr节点是否与target值一致，若是则sum++;然后对左、右子树更新target(target-curr->val)再分别递归调用（前序遍历）；
（2）第二种情况->不以curr为路径根节点
   这种情况再采用一次DFS，分别DFS左、右子树，计算满足路径和的数量，然后与第一种情况相加，即为最终结果。

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
    int pathSum(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        return DFS(root,sum);
        
    }

    int solve(TreeNode* curr, int target)
    {
        int ans=0;
        if(curr==NULL) return 0;
        if(curr->val == target) ans++;
        ans+=solve(curr->left, target-curr->val);
        ans+=solve(curr->right,target-curr->val);
        return ans;
    }

    int DFS(TreeNode* curr, int target)
    {
        int ans=0;
        if(curr==NULL) return 0;
        ans+= solve(curr,target);
        ans+=DFS(curr->left,target);
        ans+=DFS(curr->right,target);
        return ans;
    }
};
```