### 方法一：递归

**思路**：
与二叉树一致，与先续遍历一致（节点值加入到链表中的时机不同）。

``` java
public List<Integer> postorder(Node root) {

    List<Integer> list = new LinkedList<>();
    helper(root, list);

    return list;
}

public void helper(Node node, List<Integer> res) {
    if (node == null) return;

    // res.add(node.val); //先序遍历添加时机
    for (Node child : node.children) {
        helper(child, res);
    }
    res.add(node.val); //后序遍历添加时机
}
```

**复杂度：**
时间复杂度：O(N)
空间复杂度：O(N)


### 方法二：迭代（使用栈）

后续遍历的逻辑是：当遍历到当前节点`curr`时，首先读取其子节点，然后再读取当前节点。（所以使用递归的方式逻辑很清晰）

那么如果反过来，先读取当前节点`curr`，然后再读取其子节点，也就是意味着结果的顺序与后续遍历相反。
看程序：

``` java
public List<Integer> postorder(Node root) {
    List<Integer> list = new LinkedList<>();

    Stack<Node> stack = new Stack<>();
    stack.push(root);

    while (!stack.isEmpty()) {
        Node pop = stack.pop();

        list.add(pop.val); // 首先访问当前节点

        // 将子节点加入栈
        for(Node child : pop.children) {
            stack.push(child); 
        }
    }
    // 最终将结果反转
    Collections.reverse(list);
    return list;
}
```

**复杂度：**
时间复杂度：O(N)
空间复杂度：O(N)