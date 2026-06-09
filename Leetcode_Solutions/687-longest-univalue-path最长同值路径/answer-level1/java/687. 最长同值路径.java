/**
 * @Project
 * @Author 
 * @Email 2399144252@qq.com
 * @Date 2019/10/6
 *
 * 解题思路: 官方题解很给力, 定义maxLength()返回左右子树中相等节点最长的长度,在过程总使用res记录最长的路径长度,不断更新
 *
 * 注意: 此算法从叶子结点开始进行处理 因此需要使用递归进行压栈
 *
 */
```
public class leetcode687 {

    int res;
    public int longestUnivaluePath(TreeNode root) {

        res = 0;
        maxLength(root);
        return res;

    }
    //返回左右子树中相等节点距离最长的值
    public int maxLength(TreeNode root){
        if(root == null) return 0;
        //递归压栈
        int left = maxLength(root.left);
        int right = maxLength(root.right);

        //叶子节点进行处理
        int leftLength = 0;
        int rightLength = 0;
        //左子树 与根节点相同再加入
        if(root.left != null && root.left.val == root.val){
            leftLength = left + 1;
        }

        //右子树 与根节点相同再加入
        if(root.right != null && root.right.val == root.val){
            rightLength = right + 1;
        }

        //判断当前的相等的最长的节点长度
        res = Math.max(res,rightLength+leftLength);
        //返回左右子树中最大的那个子树
        return Math.max(leftLength,rightLength);
    }

    public static void main(String[] args) {

    }
}
```
