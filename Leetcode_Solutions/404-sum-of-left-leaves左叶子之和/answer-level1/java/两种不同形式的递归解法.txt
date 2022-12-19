两个解法都是基于递归的,只是形式不一样.
解法一需要一个全局变量,和一个额外的getSum()函数.这种写法的好处是使代码更加清晰易懂.
解法二则不需要额外的全局变量和函数.
总之两种写法思想都差不多,运行时间都是100%.具体代码分析请看注释.

__解法一__
```java
int res = 0;//存储结果

public int sumOfLeftLeaves(TreeNode root) {
    if(root==null)//root为空直接返回0
        return res;
    getSum(root);//递归函数,求得结果
    return res;
}

public void getSum(TreeNode root) {
    if (root.left != null) {//root.left不能为空
        //root.left为左叶子
        if (root.left.left == null && root.left.right == null)
            res += root.left.val;//结果增加
        else//否则继续递归
            getSum(root.left);
    }
    if (root.right != null)//root.right不能为空
        getSum(root.right);
}
```



__解法二__
```java
public int sumOfLeftLeaves(TreeNode root) {
    if (root == null)//root为空直接返回0
        return 0;
    //left存root的左子树的左叶子之和,right存右子树的左叶子之和
    //若root.left为左叶子,cur存root.left的值
    int left = 0, right = 0, cur = 0;
    //若root.left为左叶子
    if (root.left != null && root.left.left == null && root.left.right == null)
        cur = root.left.val;//存下这片左叶子的值
    else//否则继续递归
        left = sumOfLeftLeaves(root.left);//左子树值
    right = sumOfLeftLeaves(root.right);//右子树值
    return left + right + cur;//返回左子树值(若root.left非左叶子)+右子树值+root.left值(若root.
    left为左叶子)
}
```