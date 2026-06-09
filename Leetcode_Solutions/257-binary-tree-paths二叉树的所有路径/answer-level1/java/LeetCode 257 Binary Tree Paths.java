# 解法思路（一）
###### 关于递归问题的思考顺序
- 先一头扎进递归的最底层，就最底层的情况进行思考；
- 然后从最底层往上走一层，对这一层的情况进行思考；
- 再往上走一层，就是递归的一般情况；
###### 二叉树的所有路径解法描述
- 如果到了最底，二叉树为空了，返回给上一层一个空线性表；
- 如果在倒数第二层，二叉树为叶子节点，返回包含叶子节点的线性表到上一层；
- 如果二叉树或者有左孩子，或者有右孩子，或者既有左孩子又有右孩子，递归的去其左孩子和右孩子为根的二叉树中找路径；
- 左孩子为根的二叉树的所有路径以线性表的形式返回，右孩子也是一样；
- 把当前根节点加到两个线性表中包含的所有路径的前面；
- 将两个线性表中的所有路径合在一个线性表中返回给上一层；
# 解法实现（一）
###### 时间复杂度
- 好像挺慢的，具体我也算不出来，感觉O(h^2)吧；
###### 空间复杂度
- O(h) 吧感觉；
###### 关键字
`二叉树的所有路径` `二叉树` `递归` `递归的返回值` 
###### 实现细节
- 两个线性表合并的时候，谁合并谁好像是有区别的；
```
package leetcode._257;

import java.util.LinkedList;
import java.util.List;

public class Solution257_1 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<String> binaryTreePaths(TreeNode root) {

        if (root == null) {
            return new LinkedList<String>();
        }

        if (root.left == null && root.right == null) {
            List<String> path = new LinkedList<>();
            path.add(String.valueOf(root.val));
            return path;
        }

        List<String> leftPath = binaryTreePaths(root.left);
        List<String> rightPath = binaryTreePaths(root.right);

        for(int i = 0; i < leftPath.size(); i++) {
            String s = leftPath.remove(i);
            s = root.val + "->" + s;
            leftPath.add(i, s);
        }

        for(int i = 0; i < rightPath.size(); i++) {
            String s = rightPath.remove(i);
            s = root.val + "->" + s;
            rightPath.add(i, s);
        }

        for(String p : rightPath)
            leftPath.add(p);

        return leftPath;
    }

}
```

---

# 解法实现（二）
###### 时间复杂度
- O(n)，n为树中的节点个数；
###### 空间复杂度
- O(h)，h为树的高度；
###### 关键字
`二叉树的所有路径` `二叉树` `递归` `递归的返回值` 
###### 实现细节
- LinkedList 换成了 ArrayList；
- 字符串拼接变成了 StringBuilder；
- 避免了 leftPaht 和 rightPath 的合并；
```
package leetcode._257;

import java.util.ArrayList;
import java.util.List;

public class Solution257_2 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<String> binaryTreePaths(TreeNode root) {

        ArrayList<String> res = new ArrayList<String>();

        if(root == null)
            return res;

        if(root.left == null && root.right == null){
            res.add(Integer.toString(root.val));
            return res;
        }

        List<String> leftPaths = binaryTreePaths(root.left);
        for(String s: leftPaths){
            StringBuilder sb = new StringBuilder(Integer.toString(root.val));
            sb.append("->");
            sb.append(s);
            res.add(sb.toString());
        }

        List<String> rightPaths = binaryTreePaths(root.right);
        for(String s: rightPaths) {
            StringBuilder sb = new StringBuilder(Integer.toString(root.val));
            sb.append("->");
            sb.append(s);
            res.add(sb.toString());
        }

        return res;
    }

}
```
[返回 LeetCode [Java] 目录](https://www.jianshu.com/p/2cc66577f7d7)