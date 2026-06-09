### 解题思路
关键是查找字符串在trie树中所处的叶子节点的位置

1. insert：searchLeaf找到叶子节点，在后续添加新的节点，注意插入的最后一个节点要打个标识，用于处理有更长的路径insert后search不到；
2. search：searchLeaf找到叶子节点，叶子节点是最后一个节点且路径长度和输入字符串的长度一致；
3. startWith：searchLeaf找到叶子节点，叶子节点的长度和输入字符串的长度一致表示搜到了即可；

算法渣刷leetcode...

### 代码

```java
class Trie {
        private static class Node {
            public char val;
            public Node[] next;
            //表示是某次插入的叶子节点；
            boolean hasIndex = false;

            public Node(char val) {
                this.val = val;
            }
        }

        /***
         * trie树的根节点
         */
        private Node root;

        /**
         * Initialize your data structure here.
         */
        public Trie() {
            root = new Node((char) 0);
        }

        /**
         * Inserts a word into the trie.
         */
        public void insert(String word) {
            if (word == null || word.trim().length() == 0) {
                return;
            }
            char[] chars = word.toCharArray();
            List res = searchLeaf(chars);
            int leafIndex = (int) res.get(0);
            Node leafNode = (Node) res.get(1);

            //已存在路径直接返回
            if (leafIndex == chars.length) {
                leafNode.hasIndex = true;
                return;
            }
            //插入后续节点
            for (int i = leafIndex; i < chars.length; i++) {
                Node node = new Node(chars[i]);
                if (leafNode.next == null) {
                    leafNode.next = new Node[]{node};
                } else {
                    //层级已有节点时，需要扩容合并（仅适合读多写少）
                    Node[] nexts = new Node[leafNode.next.length + 1];
                    System.arraycopy(leafNode.next, 0, nexts, 0, leafNode.next.length);
                    nexts[leafNode.next.length] = node;
                    leafNode.next = nexts;
                }
                leafNode = node;
            }
            leafNode.hasIndex = true;
        }

        /**
         * Returns if the word is in the trie.
         */
        public boolean search(String word) {
            if (word == null || word.trim().length() == 0 || root.next == null) {
                return false;
            }
            char[] chars = word.toCharArray();
            List res = searchLeaf(chars);
            int leafIndex = (int) res.get(0);
            Node leafNode = (Node) res.get(1);
            return leafNode.hasIndex && leafIndex == chars.length;
        }

        /**
         * Returns if there is any word in the trie that starts with the given prefix.
         */
        public boolean startsWith(String prefix) {
            if (prefix == null || prefix.trim().length() == 0 || root.next == null) {
                return false;
            }
            char[] chars = prefix.toCharArray();
            List res = searchLeaf(chars);
            int leafIndex = (int) res.get(0);
            return leafIndex== chars.length;
        }

        /***
         * 搜索字符串在trie树中匹配的叶子节点
         * @param chars 字符串
         * @return [leafIndex, leafNode]
         */
        private List searchLeaf(char[] chars) {
            //已存在路径的叶子节点
            Node leaf = root;
            //叶子节点的索引
            int p = 0;
            Node[] nextNodes = root.next;
            //循环深入查找下一层的节点中是否存在与word路径一致的
            while (nextNodes != null) {
                if (p == chars.length) {
                    break;
                }
                boolean isFind = false;
                for (Node node : nextNodes) {
                    if (chars[p] == node.val) {
                        isFind = true;
                        leaf = node;
                        p++;
                        break;
                    }
                }
                //这一层找到了，继续下一层查找
                if (isFind) {
                    nextNodes = leaf.next;
                } else {
                    nextNodes = null;
                }
            }
            return Arrays.asList(p, leaf);
        }
    }
```