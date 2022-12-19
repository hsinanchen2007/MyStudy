![image.png](https://pic.leetcode-cn.com/381eb0c625b075794a3973248a1df539b3be31e371479ea2eaeda1633f82475c-image.png)

### 解题思路
插入和查找的过程使用到了队列，思路类似于 BFS 

### 代码

```java
class TrieNode{
    public  char val;
    public boolean isEnd;
    List<TrieNode> children = new ArrayList<>();
    public TrieNode(){

    }
    public TrieNode(char val, boolean isEnd){
        this.val = val;
        this.isEnd = isEnd;
    }
}

class Trie {

    /** Initialize your data structure here. */
    private TrieNode root;
    public Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        Queue<TrieNode> nodeQueue = new LinkedList<>();
        nodeQueue.offer(root);
        int curPos = 0;
        while (curPos<word.length()){
            TrieNode curNode = nodeQueue.poll();
            boolean alreadyIn = false;
            for(TrieNode node: curNode.children){
                if(node.val==word.charAt(curPos)){
                    if(curPos==word.length()-1)
                        node.isEnd = true;
                    ++curPos;
                    nodeQueue.offer(node);
                    alreadyIn = true;
                    break;
                }
            }
            if(!alreadyIn){
                boolean isEnd = curPos==word.length()-1;
                TrieNode newNode = new TrieNode(word.charAt(curPos), isEnd);
                curNode.children.add(newNode);
                nodeQueue.offer(newNode);
                ++curPos;
            }
        }
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Queue<TrieNode> nodeQueue = new LinkedList<>();
        nodeQueue.offer(root);
        int curPos = 0;
        while (!nodeQueue.isEmpty()&&curPos<word.length()){
            TrieNode curNode = nodeQueue.poll();
            boolean alreadyIn = false;
            for(TrieNode node: curNode.children){
                if(node.val==word.charAt(curPos)){
                    if(curPos==word.length()-1&&node.isEnd!=true)
                        break;
                    alreadyIn = true;
                    nodeQueue.offer(node);
                    ++curPos;
                    break;
                }
            }
            if(!alreadyIn&&curPos!=word.length())  return false;
        }
        return (curPos==word.length());
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Queue<TrieNode> nodeQueue = new LinkedList<>();
        nodeQueue.offer(root);
        int curPos = 0;
        while (!nodeQueue.isEmpty()&&curPos<prefix.length()){
            TrieNode curNode = nodeQueue.poll();
            boolean alreadyIn = false;
            for(TrieNode node: curNode.children){
                if(node.val==prefix.charAt(curPos)){
                    alreadyIn = true;
                    nodeQueue.offer(node);
                    ++curPos;
                    break;
                }
            }
            if(!alreadyIn&&curPos!=prefix.length())  return false;
        }
        return true;
    }
}
```