### 解题思路
本题是  [路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)  的升级版本， 本题没有要求计算必须从根节点开始， 叶子节点结束。
顺着 路径总和 II 的思路， 可以选择对每一个节点执行类似于 路径总和 II 的操作， 即将每一个节点看作根节点（这是一个树的先序递归遍历）求： 从本根节点开始的包括根节点的， 路径和为 sum 的节点个数（这是另一层递归， 路径总和 II 的代码稍作改动即可） 

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
    // 寻找以 root 为跟节点的子树， 路径和为 sum 的路径条数（ root 不需要在 路径中）
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        int ret = 0;
        if(root -> val == sum)
            ret++;
        // 以 root 为起始节点的, 从 root 开始计算和为 sum 的路径个数, 这里没有写成 ret += includeRootPathSum(root, sum); 而是代入得左右子树， 主要是因为要避免 root 就是解， 从而产生重复答案的情况， 例如 [1], 1， 如果直接带入根节点循环， 会得到 2 的结果。
        ret += includeRootPathSum(root -> left, sum - root -> val);
        ret += includeRootPathSum(root -> right, sum - root -> val);
        // 继续将每个节点当作根节点， 求从根节点开始和为 sum 的路径条数
        ret += pathSum(root -> left, sum);
        ret += pathSum(root -> right, sum);
        return ret;

    }
    // 寻找以 root 为起始节点的， 从 root 开始计算并且路径上的节点和为 sum 的路径条数
    int includeRootPathSum(TreeNode* root, int sum){
        if(root == NULL) // 不需要是叶子节点， 所以此处是直接是 root == NULL 就直接返回 0
            return 0;
        int ret = 0;
        if(root -> val == sum)// 此处就不能直接返回， 需要一直遍历到叶子节点， 如果后续还存在 0 或者 负数(如 -5， 5, 那么再加上后两个元素， 也是满满足题意的)， 
            ret++;
        ret += includeRootPathSum(root -> left, sum - root -> val);
        ret += includeRootPathSum(root -> right, sum - root -> val);
        return ret;
    }
};

```