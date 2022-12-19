方法：迭代法，用双栈。
先序遍历是：中->左->右，那么翻转先序遍历就是：中->右->左，将其依次加入到helper栈中，再依次弹出，就得到了：左->右->中，也就是后序遍历的结果。
```
public List<Integer> postorder(Node root) {
    List<Integer> res = new ArrayList<>();
    if (root == null) return res;

    Stack<Node> stack = new Stack<>(); // 翻转先序遍历栈
    Stack<Node> helper = new Stack<>(); // 辅助栈，只起到反转的作用
        
    Node node = root;
    stack.push(node);
    while (!stack.isEmpty()) {
        node = stack.pop();
        helper.push(node);
        for (Node n : node.children) { // 此处与先序遍历不同，先序遍历是从右往左加入stack，此处是从左往右加入stack。
            stack.push(n);
        }
    }
    while (!helper.isEmpty()) {
        res.add(helper.pop().val);
    }
    return res;
}
```
