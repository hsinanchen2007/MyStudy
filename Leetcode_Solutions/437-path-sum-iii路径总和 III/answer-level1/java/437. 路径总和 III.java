
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/10
 *
 * 解题思路: 中序遍历过程中 以当前节点为根节点再次进行中序遍历求路径长度和，count 记录路径和为sum的次数
 */

```
public class leetcode437 {

    int count = 0;
    int res = 0;
    public int pathSum(TreeNode root, int sum) {

        if(root == null){
            return count;
        }

        count = 0;
        res += pathSumExe(root,sum);
        System.out.println(root.val + " ");

        pathSum(root.left,sum);
        pathSum(root.right,sum);

        return res;
    }

    public int pathSumExe(TreeNode root, int sum){
        if(root == null){
            return count;
        }

        if(sum - root.val == 0){
            //输出路径
            count++;
        }

        pathSumExe(root.left,sum - root.val);
        pathSumExe(root.right,sum - root.val);

        return count;
    }

    public static void main(String[] args) {
        TreeNode a = new TreeNode(7);
        TreeNode b = new TreeNode(1);
        TreeNode d = new TreeNode(2);
        TreeNode e = new TreeNode(3);
        TreeNode f = new TreeNode(4);
        TreeNode g = new TreeNode(5);

        a.left = b;
        a.right= d;
        b.left = e;
        b.right= f;
        e.left = g;

        leetcode437 leetcode437 = new leetcode437();
        leetcode437.pathSum(a,8);
    }
}
```