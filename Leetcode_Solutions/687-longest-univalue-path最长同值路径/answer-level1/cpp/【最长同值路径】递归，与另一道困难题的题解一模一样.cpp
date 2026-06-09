### 思路
1. 先看一个最简单的二叉树 abc，a 是根节点，bc 是左右子节点，a 的上方还有父节点 r 。  

2. 假设数值相同，不考虑长短，所有可能的路径情况：  
```
    r
    |
    a
   / \
  b   c
```
情况 1： b - a - c
情况 2： b - a - r
情况 3： c - a - r

3. 如果我们能够实现一个函数，传入 a ，得到是选 b 还是 c ，返回长度给 r ，那么就能计算情况 2 和 3 。

4. 如果我们能够实现一个函数，传入 b/c ，不管他们的子节点情况如何，都能得到其子节点中最长同值路径长度，那么我们就能计算出 a 应该选 b 还是 c 了。

5. 幸运的是，他们可以是同一个函数。

### 实现
1. 设计一个递归函数

2. 递归函数的返回值
    21. 我们希望这个函数能够得到：从 `node` 节点开始，向下出发，最长的同值路径长度
    22. 因为路径的一个方向是通向 `node` 的父节点，所以另一个方向只能从 `node` 的左或右节点中选择至多一个

3.  递归函数的出口
    31. 如果 `node` 为空，返回 0

4.  递归函数的逻辑
    41. 当我们递归调用 `node->left` 和 `node->right` 时，就可以得到左/右子树与其数值相同节点的长度
    42. 只需要判断左/右子树的数值与根节点的数值是否相同，不相同的话就舍弃，相同的话长度就加一
    43. 那么与 `node` 值相同的路径长度就是左/右两条路中较长的

5. 递归函数只能取得 `node` 的同值路径长度，这里还有一些其他情况需要考虑
    51. 如果最长的路径是由一个其他数值的子节点开始向下出发的情况，在递归中间因为数值不同被舍弃了
    52. 是由一个子节点，向左右两个方向同时向下出发的情况（情况 1）

6. 在递归函数的参数中使用一个引用变量，记录全局最大值
    61. 当计算出一个节点的返回值时，将以这个节点，连接左右两边的路径长度，更新到全局最大值
    62. 然后再返回

7. 这个全局最大值包含了以上所有情况，就是题目的答案

### 答题
```C++
int help(TreeNode* node, int &ans)
{
    if (node == nullptr) return 0;

    int left = help(node->left, ans);
    int right = help(node->right, ans);

    left = (node->left != nullptr && node->val == node->left->val) ? left + 1 : 0;
    right = (node->right != nullptr && node->val == node->right->val) ? right + 1 : 0;

    ans = max(ans, left + right);
    return max(left, right);
}

int longestUnivaluePath(TreeNode* root)
{
    int ans = 0;
    help(root, ans);
    return ans;
}
```

### 链接
一个套路，解决下面这道困难题。  
有兴趣可以看看。  

[124.二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/)  


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

