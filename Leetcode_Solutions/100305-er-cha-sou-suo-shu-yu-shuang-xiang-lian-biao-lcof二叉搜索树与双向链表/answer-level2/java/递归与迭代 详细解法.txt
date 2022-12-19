## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


#### 解法1：迭代解法
**【核心思想】**
* 用栈实现中序遍历

**【数据结构】**
* 栈

**【思路】**
* 将树的左子树依次存入stack
* 每次pop出一个Node将其右子树的左子树也依次存入stack
* 饭后做连接操作

**【代码】**
```java
public Node treeToDoublyList(Node root) {
    if(root==null)
        return null;
    Node cur = root;
    Node before = null;
    Node after;
    Node head=null;

    Stack<Node> stack = new Stack<>();
    while (cur != null) {
        stack.add(cur);
        head=cur;
        cur = cur.left;
    }

    while (!stack.isEmpty()) {
        cur = stack.pop();
        Node temp = cur.right;
        while (temp != null) {
            stack.push(temp);
            temp = temp.left;
        }
        if(stack.isEmpty())
            after=head;
        else
            after = stack.peek();
        cur.left = before;
        cur.right = after;
        before = cur;
    }
    head.left=before;
    return head;
}
```


#### 解法2：递归解法
**【核心思想】**
* 用递归实现中序遍历


**【思路】**
* 全局保存头尾指针
* 先递归左子树
* 连接，并更新尾部指针
* 再递归右子树

**【代码】**
```java
Node head = null;
Node tail = null;
public Node treeToDoublyList(Node root) {
    if(root == null)
        return null;
    help(root);
    head.left = tail;
    tail.right = head;
    return head;
}

void help(Node root) {
    if(root == null)
        return;
    help(root.left);
    if(head == null)
        head = root;
    if(tail != null) {
        tail.right = root;
        root.left = tail;
    }
    tail = root;
    help(root.right);
}
```
**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)
