### 解题思路
![Screen Shot 2020-01-23 at 10.49.31 PM.png](https://pic.leetcode-cn.com/77260772d2ec3f77e273d85072ba6756d552de2d50144d54ff2dd20d53e86cc7-Screen%20Shot%202020-01-23%20at%2010.49.31%20PM.png)
自上而下的分治解法，一旦发现更深的depth就更新sum和deepest depth

### 代码
```java
class Solution {
  int sum = 0;
  int deepest = 1;
  
  public int deepestLeavesSum(TreeNode root) {
    topDown(root, 1);
    return sum;
  }

  public void topDown(TreeNode node, int curDepth) {
    if (node == null) return;

    if (curDepth == deepest) sum += node.val;
    
    if (curDepth > deepest) {
      sum = 0;
      deepest = curDepth;
      sum += node.val;
    }

    topDown(node.left, curDepth + 1);
    topDown(node.right, curDepth + 1);
  }
}
```