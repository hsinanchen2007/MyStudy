
```java
class Trie {

    private class Node {
        // 同级的下一个
        private Node peerNext;
        // 下一个子节点
        private Node childNext;
        // 当前节点的字符
        private Character currChar;
        // 到当前节点为止是否已经是一个完整的单词
        private boolean isIntact;

        public Node() {
            this.peerNext = null;
            this.childNext = null;
            this.currChar = null;
            this.isIntact = false;
        }

        public Node(Node peerNext, Node childNext, Character currChar, boolean isIntact) {
            this.peerNext = peerNext;
            this.childNext = childNext;
            this.currChar = currChar;
            this.isIntact = isIntact;
        }

        public void setIntact(boolean intact) {
            isIntact = intact;
        }

        public void setCurrChar(Character currChar) {
            this.currChar = currChar;
        }
    }

    private Node root;

    /**
     * Initialize your data structure here.
     */
    public Trie() {
        super();
        root = new Node();
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        char[] arr = word.toCharArray();

        Node currNode = root;
        for (char c : arr) {
            if (currNode.childNext == null) {
                currNode = currNode.childNext = new Node();
            } else {
                currNode = currNode.childNext;
            }

            if (currNode.currChar == null) {
                currNode.setCurrChar(c);
                continue;
            }
            Node tempNode = this.findPeerNode(currNode, c);
            if (tempNode != null) {
                // 已有直接进入下一个
                currNode = tempNode;
            } else {
                // 没有需要新建
                currNode = currNode.peerNext = new Node(currNode.peerNext, null, c, false);
            }
        }
        // 循环结束，这个word已经完整
        currNode.setIntact(true);
    }

    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        char[] arr = word.toCharArray();
        Node currNode = root;
        for (char c : arr) {
            currNode = currNode.childNext;
            if (currNode == null) {
                return false;
            }
            currNode = this.findPeerNode(currNode, c);
            if (currNode == null) {
                return false;
            }
        }
        // 返回是否完整
        return currNode.isIntact;

    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        char[] arr = prefix.toCharArray();
        Node currNode = root;
        for (char c : arr) {
            currNode = currNode.childNext;
            if (currNode == null) {
                return false;
            }
            currNode = this.findPeerNode(currNode, c);
            if (currNode == null) {
                return false;
            }
        }
        return true;
    }

    private Node findPeerNode(Node currNode, char c) {
        Node temp = currNode;
        do {
            if (temp.currChar == c) {
                return temp;
            }
        } while ((temp = temp.peerNext) != null);
        return null;
    }


}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
```