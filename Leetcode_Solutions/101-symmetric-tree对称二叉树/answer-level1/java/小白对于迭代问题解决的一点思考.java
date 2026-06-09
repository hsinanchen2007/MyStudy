### 解题思路
要想解决迭代问题,对于新手来说,一味的想用大脑去模拟迭代函数的运作过程无疑是困难得.

真正可能成功的方式,是找出突破点,然后把突破点尽力模拟出来.

比如这个得突破点就是,左子树得左孩子等于右子树得右孩子,左子树的右孩子等于右子树得左孩子.

当你发现了这个规律之后,你只要知道你唯一的要做的就是构建一个可以迭代的函数,其作用只有一个!

就是比较输入的两个值得大小.

于是写入nodel.val==noder.val.

既然有了比较得代码我们唯一要做的就是将比较得对象直接模拟出来.
这就是下面得代码
isSymmetric(noder.right,nodel.left)&&isSymmetric(noder.left,nodel.right)
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 //解题思路就是tree1左等于tree2右,tree1右等于tree2左
 //
class Solution {
    public boolean isSymmetric(TreeNode root) {
           return isSymmetric(root,root);  
    }
    private boolean isSymmetric(TreeNode noder,TreeNode nodel){
        if(noder==null&&nodel==null){return true;}
        if(noder==null||nodel==null){return false;}
                       if
             return  (nodel.val==noder.val)&&isSymmetric(noder.right,nodel.left)&&isSymmetric(noder.left,nodel.right);
                         
    }
}
```