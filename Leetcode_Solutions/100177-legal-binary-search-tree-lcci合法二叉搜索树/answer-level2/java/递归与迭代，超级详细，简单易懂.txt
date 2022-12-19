## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)



#### 解法1：迭代解法
**【核心思想】**
* 判断中序遍历是否是**递增**的
* 用栈实现中序遍历

**【数据结构】**
* 栈

**【思路】**
* 将树的左子树依次存入`stack`
* 每次`pop`出一个`TreeNode`，判断其是否大于之前的数
* 将其右子树的左子树也依次存入`stack`


**【代码】**
```java
public boolean isValidBST(TreeNode root) {
    long pre=Long.MIN_VALUE;
    Stack<TreeNode> stack=new Stack<>();
    while (root != null) {
        stack.push(root);
        root=root.left;
    }
    while(!stack.empty()){
        TreeNode temp=stack.pop();
        if(temp.val<=pre)
            return false;
        pre=temp.val;
        if(temp.right!=null){
            TreeNode r=temp.right;
            while(r!=null){
                stack.push(r);
                r=r.left;
            }
        }
    }
    return true;
}
```
**【备注】**
* 这边用`long`的数据类型，是因为有以下一个特殊的测试用例
![在这里插入图片描述](https://pic.leetcode-cn.com/3bcec30ebf220b74aa3cf9f1d8ccd62b28b3c0a9af1406da2711890df8561b24.png)


#### 解法2：递归解法
**【核心思想】**
* 判断中序遍历是否是**递增**的
* 用递归实现中序遍历


**【思路】**
* 全局保存前一个数`pre`和判断指标`flag`
* 先递归左子树
* 判断是否大于`pre`
* 再递归右子树

**【代码】**
```java
long pre;
boolean flag;
public boolean isValidBST(TreeNode root) {
    if (root==null) return true;
    pre = Long.MIN_VALUE;
    flag = true;
    help(root);
    return flag;
}
void help(TreeNode root) {
    if (root == null || !flag) return;
    help(root.left);
    if (root.val > pre)
        pre = root.val;
    else
        flag = false;
    help(root.right);
}
```
**【备注】**
* 这边用`long`的数据类型，是因为有以下一个特殊的测试用例
![在这里插入图片描述](https://pic.leetcode-cn.com/3bcec30ebf220b74aa3cf9f1d8ccd62b28b3c0a9af1406da2711890df8561b24.png)
![微信外logo.png](https://pic.leetcode-cn.com/624bd4f3718342fbf1c5be198f493c630e40dcefc6bffe510a036b345eb7857f-%E5%BE%AE%E4%BF%A1%E5%A4%96logo.png)
