### 解题思路
从顶至底和从底至顶两种解法。从顶至底相对来讲很直观，每个node判断一遍就可以了。从底至顶需要创建一个计算最大高度的方法，如果left和right相差大于1就返回-1。

### 代码
从顶至底
```
public boolean isBalanced(TreeNode root) {
    if(root == null) return true;
    if(Math.abs(check(root.left)-check(root.right))>1) return false; //判断关键
    return isBalanced(root.left) && isBalanced(root.right);
}

public int check(TreeNode root){
    if(root == null) return 0;
    int longest = Math.max(check(root.left),check(root.right))+1;
    return longest;
}
```




从底至顶
```
public boolean isBalanced(TreeNode root) {
    return recur(root) != -1;
}

private int recur(TreeNode root) {
    if(root == null) return 0;

    int left_value = recur(root.left);
    if(left_value == -1) return -1;

    int right_value = recur(root.right);
    if(right_value == -1) return -1;

    if(Math.abs(left_value-right_value)>1) return -1;
    return Math.max(left_value,right_value)+1;
}
```
