树的子节点用LinkedList存储，然后插入和比较都是使用的递归，效率奇低，切记不要模仿！
应该用数组存储，然后根据字符串的范围可以定下数组范围，查询会快多了
```
class Trie {

    // Trie数是多叉数，所以节点指向多个子节点
    private class Node {
        private char c;
        private LinkedList<Node> children;

        private boolean end;

        Node(char c) {
            this.c = c;
            children = new LinkedList<>();
        }
    }

    private Node root;

    public Trie() {
        root = new Node('/');
    }

    public void insert(String word) {
        insert(root, root.children, word.toCharArray(), 0);
    }

    public boolean search(String word) {
        return cmp(root, root.children, word.toCharArray(), 0) == 0;
    }

    public boolean startsWith(String prefix) {
        int cmp = cmp(root, root.children, prefix.toCharArray(), 0);
        return cmp == 1 || cmp == 0;
    }

    private void insert(Node parent, LinkedList<Node> children, char[] chars, int index) {

        if (children.size() == 0 && index == chars.length) {
            // 全匹配的情况，不用插入
            return;
        } else if (children.size() > 0 && index == chars.length) {
            // 原字符串是前缀的情况，不用插入，但是要标记它也是个参考值
            parent.end = true;
            return;
        } else if (children.size() == 0 && index < chars.length) {
            // Trie路径字符串是原字符串的前缀，把原字符串后面字符插入
            Node tmp = parent;
            for (int i = index; i < chars.length; i++) {
                Node node = new Node(chars[i]);
                tmp.children.add(node);
                tmp = node;
            }
            tmp.end = true;
            return;
        }

        boolean find = false;
        char cmpC = chars[index];
        for (Node child : children) { // 将这一层的节点依次跟当前对应index的字符进行比较
            if (child.c == cmpC) { // 相等的话，递归子节点和下个index
                find = true;
                insert(child, child.children, chars, ++index);
            }
        }
        if (find) {
            return;
        }
        Node tmp = parent; // 没有子节点与此index的字符匹配中的情况，添加到parent的子节点
        for (int i = index; i < chars.length; i++) {
            Node node = new Node(chars[i]);
            tmp.children.add(node);
            tmp = node;
        }
        tmp.end = true;
    }


    /**
     * 比较字符串和Tire数，返回匹配的情况
     *
     * @param children
     * @param chars
     * @param index
     * @return -1为没匹配，0为匹配，1为搜索字符串为前缀，2为搜索字符串包含参考值
     */
    private int cmp(Node parent, LinkedList<Node> children, char[] chars, int index) {
        if (children.size() == 0 && index == chars.length) {
            // 全匹配的情况
            return 0;
        } else if (children.size() > 0 && index == chars.length) {
            // 原字符串是前缀的情况，这时需要看看parent是不是结束的点
            return parent.end ? 0 : 1;
        } else if (children.size() == 0 && index < chars.length) {
            // Trie路径字符串是原字符串的前缀
            return 2;
        }
        int cmp = -1;
        char cmpC = chars[index];
        for (Node child : children) { // 将这一层的节点依次跟当前对应index的字符进行比较
            if (child.c == cmpC) { // 相等的话，递归子节点和下个index
                cmp = cmp(child, child.children, chars, ++index);
            }
        }
        return cmp;
    }

}
```