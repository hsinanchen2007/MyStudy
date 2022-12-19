
将就看看吧，字符串处理其实不难，但就是有些烦琐。

```
class Codec {

    // Encodes a tree to a single string.
    public String serialize(Node root) {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        serialize(root, sb);
        sb.append(']');
        return sb.toString();
    }
    
    private void serialize(Node node, StringBuilder sb) {
        if (node == null)
            return;
        
        sb.append(node.val);
        
        if (node.children == null)
            return;
        
        sb.append('[');
        for (Node child: node.children) {
            serialize(child, sb);
            sb.append(',');
        }
        if (sb.charAt(sb.length()-1) == ',')
            sb.deleteCharAt(sb.length()-1);
        sb.append(']');
    }

    
    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        StringBuilder sb = new StringBuilder(data);
        return deserialize(sb, 1);
    }
    
    private Node deserialize(StringBuilder sb, int start) {        
        int i = start;
        char c = sb.charAt(i++);
        if (c == ']')
            return null;
        
        boolean negative = false;
        if (c == '-') {
            negative = true;
            c = sb.charAt(i++);
        }
        int value = c - '0';
        c = sb.charAt(i++);
        while ('0' <= c && c <= '9') {
            value = 10 * value + (c - '0');
            c = sb.charAt(i++);
        }
        if (negative)
            value = -value;
        
        Node node = new Node(value, null);
        
        if (c == '[') {
            node.children = new LinkedList<Node>();
            Node child = deserialize(sb, i);
            while (child != null) {
                node.children.add(child);
                child = deserialize(sb, i);
            }
            sb.delete(i-1, i+1);
            c = sb.charAt(i-1);
        }
        
        if (c == ',')
            sb.delete(start, i);
        else if (c == ']')
            sb.delete(start, i-1);
        
        return node;
    }
}
```

运行效果还算理想：
![效率.JPG](https://pic.leetcode-cn.com/2a2d66439e7290f6e3abe1f8bf4035b7ceb5345280c78f29cea47b4b08e24046-%E6%95%88%E7%8E%87.JPG)

但当我好奇地想看看运行速度极快的大神是怎么写的，打开之后我惊了：
![N叉树序列化_LI.jpg](https://pic.leetcode-cn.com/8c38153bed8711786aaaf2d3d6d5728c229e45684beedbdf47fa9bc96deaaf6a-N%E5%8F%89%E6%A0%91%E5%BA%8F%E5%88%97%E5%8C%96_LI.jpg)

这是人干的事儿吗？