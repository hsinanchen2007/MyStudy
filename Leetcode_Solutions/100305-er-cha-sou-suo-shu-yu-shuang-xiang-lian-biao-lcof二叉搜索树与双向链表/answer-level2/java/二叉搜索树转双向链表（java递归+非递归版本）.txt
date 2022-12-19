递归版本：
    改写中序遍历，遍历过程中使用一全局变脸pre存储其前一个结点,当遍历该结点时，只需该节点的前驱(left)指向pre，pre的后继指向该节点。对于头结点应特殊处理。
```
    public Node pre;
    public Node head, tail;
    public void process(Node root){
        if(root == null){
            return;
        }
        process(root.left);
        root.left = pre;
        if(pre == null){
            head = root;
        }else{
            pre.right = root;
        }
        pre = root;
        tail = root;
        process(root.right);
    }
    public Node treeToDoublyList(Node root) {
        if(root == null){
            return null;
        }
        process(root);
        tail.right = head;
        head.left = tail;
        return head;
    }
```
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
38.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户



非递归版本：
    改写中序遍历的非递归。不在需要使用全局变量了。
```
    public Node treeToDoublyList(Node root) {
        if(root == null){
            return null;
        }
         Stack<Node> stack = new Stack<>();
         Node current = root;
         Node pre = null, head = null, tail = null;
         while(!stack.isEmpty() || current != null) {
             while(current != null) {
                 stack.push(current);
                 current = current.left;
             }
             current = stack.pop();
             tail = current;
             if(pre == null) {//处理头结点
                 head = current;
             }else {
                 pre.right = current;
                 current.left = pre;
             }
            pre = current;
            current = current.right;
         }
         tail.right = head;
         head.left = tail;
         return head;
    }
```
执行用时 :
2 ms
, 在所有 Java 提交中击败了
13.01%
的用户
内存消耗 :
38.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户
