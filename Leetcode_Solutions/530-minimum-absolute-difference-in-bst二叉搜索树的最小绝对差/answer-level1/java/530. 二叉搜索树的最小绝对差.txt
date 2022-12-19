/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/23
 *
 * 解题思路: 使用BST的特性 中序遍历之后等处有序的数组
 *
 */
```
public class leetcode530 {

    Integer min = Integer.MAX_VALUE;
    Integer pre = null;
    Integer current = null;
    public int getMinimumDifference(TreeNode root) {
        InOrder(root);
        return min;
    }

    public void InOrder(TreeNode root){

        if(root == null) return;

        InOrder(root.left);

        if(pre == null){
            pre = root.val;
        }else {
            if(current == null) {
                current = root.val;
            }else{
                pre = current;
                current = root.val;
            }
            if(min > Math.abs(pre - current)){
                min = Math.abs(pre - current);
            }
        }
        InOrder(root.right);
    }

    public static void main(String[] args) {

    }
}

```