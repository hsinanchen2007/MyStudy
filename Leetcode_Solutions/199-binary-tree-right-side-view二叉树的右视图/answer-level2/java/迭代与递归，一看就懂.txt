## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


#### 解法1：迭代解法
**【核心思想】**
* 参考题目：《二叉树的层次遍历》
* 借助队列实现层次遍历
* 将每一层最右边一个结点的`val`取出放入`list`即可

**【数据结构】**
* 队列

**【思路】**
* 先将根结点放入队列`queue`中
* 然后遍历`queue`，依次`pop`，将弹出结点的左右子节点依次加入`queue`
* 当`i==queue.size()-1`的时候，就是这一层的最右边一个结点


**【代码】**
```java
 public List<Integer> rightSideView(TreeNode root) {
    if(root==null)
        return new ArrayList<>();
    Queue<TreeNode> queue=new ArrayDeque<>();
    List<Integer> list=new ArrayList<>();
    queue.add(root);
    while(!queue.isEmpty()){
        int len=queue.size();
        for(int i=0;i<len;i++){
            TreeNode temp=queue.poll();
            if(i==len-1)
                list.add(temp.val);
            if(temp.left!=null)
                queue.add(temp.left);
            if(temp.right!=null)
                queue.add(temp.right);
        }
    }
    return list;
}
```
**【备注】**
* 如果在加入到`queue`时**先加入右结点，再加入左结点**，那么可以不用判断`i==queue.size()-1`，直接在`while`的开头就加入`list`

```java
public List<Integer> rightSideView(TreeNode root) {
    if(root==null)
        return new ArrayList<>();
    Queue<TreeNode> queue=new ArrayDeque<>();
    List<Integer> list=new ArrayList<>();
    queue.add(root);
    while(!queue.isEmpty()){
        list.add(queue.peek().val);
        int len=queue.size();
        for(int i=0;i<len;i++){
            TreeNode temp=queue.poll();
            if(temp.right!=null)
                queue.add(temp.right);
            if(temp.left!=null)
                queue.add(temp.left);
        }
    }
    return list;
}
```

#### 解法2：递归解法
**【核心思想】**
* 每一层只有一个结点的`val`需要加入`list`，所以可以用一个变量`level`控制


**【思路】**
* 在调用递归函数时，先调度用右结点，再调用左结点
* 当`level == ans.size()`，即已经遇到了这一层最右边的结点，将其`val`加入`list`即可

**【代码】**
```java
List<Integer> list = new ArrayList<>();
public List<Integer> rightSideView(TreeNode root) {
    help(root, 0);
    return list;
}
void help(TreeNode root, int level) {
    if (root == null)
        return;
    if (level == list.size())
        list.add(root.val);
    help(root.right, level + 1);
    help(root.left, level + 1);
}
```
**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)
