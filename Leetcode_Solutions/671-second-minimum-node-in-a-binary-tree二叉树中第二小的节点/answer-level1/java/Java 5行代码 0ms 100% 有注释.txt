![QQ截图20200324114701.jpg](https://pic.leetcode-cn.com/5b7aaae859c929ed048bfa24bb172090ae40b8958cc1ed89d14661d49e2036b1-QQ%E6%88%AA%E5%9B%BE20200324114701.jpg)

### 主要采取分治的思路，具体如下：

1. 方法执行的结果，是返回以传入节点为root的树中第二小的值
2. 设子节点为`a,b（a.val > b.val）`
3. 对`b`求解的结果和`a`的较小者，就是本次方法的解
    1. 基于题面，`a`已经是以`a`为`root`的树中的最小值
    2. 所以对`b`求解的结果和`a`是唯一能成为第二小的候选值
3. 若`a.val == b.val`，只需分别对`a`，`b`求解，再取较小者即可

### 代码解释如下：

1. 若不存在子节点，返回`-1`，代表没有第二小的数
2. 对比子节点的val，若等于本节点，说明是较小的子节点（或两个子节点相等），递归带入求解
3. 返回子节点结果中，不等于`-1`又较小的一个
    1. 若子节点的结果全是`-1`，说明都没有第二小的数（也就是所有子节点的值都等于自身），也返回`-1`

```
class Solution {
    
    public int findSecondMinimumValue(TreeNode root) {
        if (root.left == null) return -1;
        int left = root.left.val, right = root.right.val;
        if (left == root.val) left = findSecondMinimumValue(root.left);
        if (right == root.val) right = findSecondMinimumValue(root.right);
        return left == -1 ? right : right == -1 ? left : Math.min(left, right);
    }

}
```
