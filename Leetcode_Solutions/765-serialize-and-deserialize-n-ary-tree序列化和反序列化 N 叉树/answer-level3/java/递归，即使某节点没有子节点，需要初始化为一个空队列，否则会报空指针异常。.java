### 解题思路
1. 即使某节点没有子节点，需要初始化为一个空队列。否则会报空指针异常。
2. 递归编码为：[1[3[5][6][8]][2][4][7]]
3. 由于最外层有一个[]。所以解码时需要取根节点的子节点。

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
    public String serialize(Node root) {
        if (null == root) {
            return null;
        }
        StringBuffer sb = new StringBuffer();
        sb.append("[");
        sb.append(root.val);

        List<Node> children = root.children;
        if (children != null) {
            for (Node node1 : children) {
                String subString = serialize(node1);
                sb.append(subString);
            }
        }
        sb.append("]");
        return sb.toString();
    }

    //全局指针
    private int index = -1;

    public Node deserialize(String data) {
        if (null == data || data.length() == 0) {
            return null;
        }
        Node node = this._deserialize(data);
        return node.children.get(0);
    }

    // Decodes your encoded data to tree.
    public Node _deserialize(String data) {
        Node node = new Node();
        node.children = new ArrayList<>();
        while (++index < data.length()) {
            char c = data.charAt(index);
            if (c == '[') {
                Node subNode = this._deserialize(data);
                List<Node> children = node.children;
                if (node.children == null) {
                    children = new ArrayList<>();
                }
                children.add(subNode);
                node.children = children;
            } else if (Character.isDigit(c)) {
                int temp = 0;
                while (index < data.length() && Character.isDigit(data.charAt(index))) {
                    temp = temp * 10 + (data.charAt(index) - '0');
                    index++;
                }
                node.val = temp;
                index--;
            } else if (c == ']') {
                break;
            }
        }
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```