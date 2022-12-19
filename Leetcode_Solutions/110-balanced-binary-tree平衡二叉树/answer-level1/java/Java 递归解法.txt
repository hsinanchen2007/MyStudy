Java 递归解法,
![Snipaste_2019-12-27_14-47-25.jpg](https://pic.leetcode-cn.com/9ac56c925a4801b4fded2539ef7dec767d03a3f57b13fba1d4f2d696695505c3-Snipaste_2019-12-27_14-47-25.jpg)


代码
```java
public boolean isBalanced(TreeNode root) {
    return process(root).isBalanced;
}

public ReturnType process(TreeNode node){
    if(node == null){
        return new ReturnType(true,0);
    }
    ReturnType left = process(node.left);
    ReturnType right = process(node.right);
    int height = Math.max(left.height,right.height) +1;
    boolean isBalanced = left.isBalanced && right.isBalanced 
            && Math.abs(left.height-right.height) < 2;
    return new ReturnType(isBalanced,height);

}
class ReturnType{
    boolean isBalanced;
    int height;
    public ReturnType(boolean isBalanced, int height){
        this.isBalanced = isBalanced;
        this.height = height;
    }
}
```
