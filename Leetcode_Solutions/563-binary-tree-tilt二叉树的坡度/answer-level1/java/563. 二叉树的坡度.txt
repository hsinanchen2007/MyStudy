/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/24
 * 
 * 解题思路:后续遍历的灵活使用 sum:加上记录每一个根节点的的坡度 function findTiltExe:先序遍历 返回当前节点所在的树的所有节点的和 左子树+右子树+根节点==(根节点+左子树 + 根节点 +右子树)-根节点
 * 
 */

```
public class leetcode563 {

    int sum = 0;
    public int findTilt(TreeNode root) {


        findTiltExe(root);
        return sum;
    }

    public int findTiltExe(TreeNode root){
        if(root == null) return 0;

        int l = findTiltExe(root.left) + root.val;
        int r = findTiltExe(root.right) + root.val;

        sum += Math.abs(l - r);

        return l + r - root.val;

    }

    public static void main(String[] args) {

    }
}
```