> 思路：
> 第一种方法：递归，二叉搜索树的右值大于左值，所以肯定是以 [left, n-1] [n+1, right] 区间为左右分段
> 第二种：动态规划，由于是二叉搜索树，所以只需要一直在其右节点插入，原来的右节点作为其左节点。

```java
/**
 * 第一种方法
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public List<TreeNode> generateTrees(int n) {
    List<TreeNode> result = new ArrayList<>();
    return n < 1 ? result : handler(1, n);
  }
  private List<TreeNode> handler(int start, int end) {
    List<TreeNode> res = new ArrayList<>();
    if (start > end) {
      res.add(null);
      return res;
    }
    for (int i = start; i <= end; i++) {
      List<TreeNode> left = handler(start, i - 1);
      List<TreeNode> right = handler(i + 1, end);
      for (TreeNode l : left) {
        for (TreeNode r : right) {
          TreeNode node = new TreeNode(i);
          node.left = l;
          node.right = r;
          res.add(node);
        }
      }
    }
    return res;
  }
}

/**
 * 第二种方法
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public List<TreeNode> generateTrees(int n) {
    List<TreeNode> result = new LinkedList<>();
    if (n < 1) return result;
    
    result.add(new TreeNode(1));

    for (int i = 2; i <= n; i++) {
      List<TreeNode> resultTmp = new LinkedList<>();
      for (TreeNode x : result) {
        TreeNode r = new TreeNode(i);
        r.left = x;
        resultTmp.add(r);
        TreeNode t1 = treeCopy(x), t2 = t1, r1 = new TreeNode(i);
        while (t2 != null) {
          TreeNode t3 = t2.right;
          t2.right = r1;
          r1.left = t3;
          resultTmp.add(treeCopy(t1));
          t2.right = t3;
          r1.left = null;
          t2 = t2.right;
        }
      }
      result = resultTmp;
    }
    return result;
  }

  private TreeNode treeCopy(TreeNode root) {
    if (root == null) return null;
    TreeNode tmp = new TreeNode(root.val);
    tmp.left = treeCopy(root.left);
    tmp.right = treeCopy(root.right);
    return tmp;
  }
}
```