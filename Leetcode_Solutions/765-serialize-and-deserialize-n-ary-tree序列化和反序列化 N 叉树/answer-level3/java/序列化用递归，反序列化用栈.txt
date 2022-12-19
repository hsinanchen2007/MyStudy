### 解题思路
1.N叉树的生成方式是深度优先生成，所以用个栈来存储节点。
2.每个字符不是数字的时候，生成新的节点，入栈，如果遇见结束字符是，则表示当前节点结束遍历，需要出栈。那么出栈后的栈顶节点就是当前节点的父节点（只要字符串合法，就不可能空指针）。
3.节点加入父节点的孩子列表中。

序列化比较容易理解，这里就不细说了。
反序列化过程类似536题

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {

    private static final char CHILDREN_START = '[';// 孩子的开始符号
    private static final char CHILDREN_END = ']';// 孩子的结束符号

    // Encodes a tree to a single string.
    public String serialize(Node root) {
        if (root == null){
            return null;
        }
        StringBuilder data = new StringBuilder();
        nTreeSerializeToString(root,data);
        return data.toString().substring(1,data.length() - 1);
    }

    private void nTreeSerializeToString(Node node,StringBuilder data){
        // 下一层开始的条件
        data.append(CHILDREN_START);
        data.append(node.val);
        if (node.children != null){
            for (Node child : node.children){
                // 进入下一层
                nTreeSerializeToString(child,data);
            }
        }
        // 回到本层，结束
        data.append(CHILDREN_END);
    }

    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if (data == null){
            return null;
        }
        int index = data.indexOf(CHILDREN_START);
        if (index == -1){
            return new Node(Integer.parseInt(data),new ArrayList<>());
        }
        // 按照上面的序列化模式，不会出现没有分隔符的情况
        Node root = new Node(Integer.parseInt(data.substring(0,index)),new ArrayList<>());
        Deque<Node> stack = new LinkedList<>();
        stack.push(root);
        StringBuilder value = new StringBuilder();
        for (int i = index + 1; i < data.length();i++){
            char c = data.charAt(i);
            if (c >= '0' && c <= '9'){
                value.append(c);
            }else {
                // 新节点生成
                if (value.length() > 0){
                    Node newNode = new Node(Integer.parseInt(value.toString()),new ArrayList<>());
                    value.setLength(0);
                    stack.push(newNode);
                }
                if (c == CHILDREN_END){
                    // 结束标识，出栈
                    Node node = stack.pop();
                    Node parent = stack.peek();
                    parent.children.add(node);
                }
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```