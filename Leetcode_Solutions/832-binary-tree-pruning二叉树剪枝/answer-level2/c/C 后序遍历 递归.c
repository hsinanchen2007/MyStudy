### 思路
根据题目描述，可想到此题适合深度优先搜索（DFS)，使用后序遍历。

以此思路往下分析题目要求的剪枝情况可以转述为：
> 当一个节点的值为0且以该节点为根的树的左、右子树均满足剪枝条件时，则剪掉以该节点为根的树。

结合后序遍历流程可想到实际上是逐步剪去值为0的叶子节点。


### 实现

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* pruneTree(struct TreeNode* root){

    if(root -> left)
        root -> left = pruneTree(root -> left);
    
    if(root -> right)
        root -> right = pruneTree(root -> right);
        
    //当节点的左子树为空 右子树为空 且自身值为0的情况下 剪去以该节点为根的树
    return (!root -> left && !root -> right && root -> val == 0) ? NULL : root;
}
```

### 复杂度分析
- 时间复杂度：O(N) ， N为节点数。
- 空间复杂度：O(H) ， H为数的高度，递归栈的深度


### 提交记录
- 执行用时：0ms
- 内存消耗：5.9MB 

<br>
##### Tips
> 本题解为个人做题的一点心得。受限于本人的水平，可能不是最优解，仅供大家参考。  
随着测试用例的增加，可能一段时间后无法AC，或者本身有错误，或是有更好的解法，或是有任何疑问，意见和建议的话，希望大家留言交流，非常感谢！