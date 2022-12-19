/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 *
 * 解题思路: 求出最小值 次小值 在进行整数类型的最大值最小值比较的时候 可以使用long 类型来简化边界操作
 *
 * long 类型和 int 类型可以直接比较大小
 *
 */
```
public class leetcode671 {
    long min1 = 2147483647L + 1;
    long min2 = 2147483647L + 1;
    public int findSecondMinimumValue(TreeNode root) {
        Order(root);
        return  min2==2147483648L?-1:(int)min2;
    }

    public void Order(TreeNode root){

        if(root == null){
            return;
        }

       if(root.val < min1){
            min2 = min1;
            min1 = root.val;
        }else if(root.val > min1 && root.val < min2){
            min2 = root.val;
        }

        Order(root.left);
        Order(root.right);
    }

    public static void main(String[] args) {
        long a = 2147483647L + 1;

        if(a > 2147483647){
            int c = 0;
        }
    }
}

```