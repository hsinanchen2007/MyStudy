```
代码块
```
class Solution {
   public boolean checkSubTree(TreeNode t1, TreeNode t2) {
    //两层DFS
    if (null != t1) {
      if (compare(t1, t2)) {
        return true;
      } else {
        //剪支，true时不需要在往后走
        if (checkSubTree(t1.left, t2) || checkSubTree(t1.right, t2)) {
          return true;
        }
      }
    }
    return false;
  }

  public boolean compare(TreeNode one, TreeNode two) {
    if (null != one && null != two) {
      if (one.val == two.val) {
        return compare(one.left, two.left) && compare(one.right, two.right);
      }
      return false;
    }
    if (null == one && null == two) {
      return true;
    }

    return false;
  }
}