1、常规思路，定义一个字典树，通过深度优先求解，通过match、visited剪枝
```java
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        Trie trie = new Trie();
        for (String word : words) {
            trie.insert(word);
        }

        Set<String> result = new HashSet<>();
        boolean[][] visited = new boolean[board.length][board[0].length];
        List<Character> currWord = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                findWordsHelper(board, i, j, currWord, visited, trie, result);
            }
        }
        return new ArrayList<>(result);
    }

    private void findWordsHelper(char[][] board, int i, int j, List<Character> currWord, boolean[][] visited, Trie trie, Set<String> result) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || visited[i][j]) return;
        visited[i][j] = true;
        currWord.add(board[i][j]);

        int match = trie.match(currWord);
        if (match == 0) {
            result.add(toString(currWord));
        }
        if (match >= 0) {
            findWordsHelper(board, i - 1, j, currWord, visited, trie, result);
            findWordsHelper(board, i + 1, j, currWord, visited, trie, result);
            findWordsHelper(board, i, j - 1, currWord, visited, trie, result);
            findWordsHelper(board, i, j + 1, currWord, visited, trie, result);
        }
        currWord.remove(currWord.size() - 1);
        visited[i][j] = false;
    }

    private String toString(List<Character> word) {
        char[] value = new char[word.size()];
        for (int i = 0; i < word.size(); i++) {
            value[i] = word.get(i);
        }
        return new String(value);
    }
}

class Trie {
    private Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = index(word.charAt(i));
            if (node.children[index] == null) {
                node.children[index] = new Node();
            }
            node = node.children[index];
        }
        node.end = true;
    }

    // -1,0,1
    public int match(List<Character> word) {
        Node node = root;
        for (Character ch : word) {
            if ((node = node.children[index(ch.charValue())]) == null) return -1;
        }
        return node.end ? 0 : 1;
    }

    private int index(char ch) {
        return ch - 'a';
    }

    private static class Node {
        Node[] children;
        boolean end = false;

        Node() {
            this.children = new Node[26];
        }
    }
}
```

2、简单优化：
   重定义Trie节点，将字典树合进主方法，改写match方法减少循环，去除currWord参数，减少word拼接带来的开销
   通过对board[i][j]重新赋值，去除visited参数，节约空间
```java
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode trieNode = createTrie(words);
        Set<String> result = new HashSet<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                findWordsHelper(board, i, j, trieNode, result);
            }
        }
        return new ArrayList<>(result);
    }

    private void findWordsHelper(char[][] board, int i, int j, TrieNode trieNode, Set<String> result) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] == Character.MIN_VALUE) return;
        char currVal = board[i][j];
        board[i][j] = Character.MIN_VALUE;

        trieNode = trieNode.next[index(currVal)];
        if (trieNode != null) {
            if (trieNode.word != null) {
                result.add(trieNode.word);
            }

            findWordsHelper(board, i - 1, j, trieNode, result);
            findWordsHelper(board, i + 1, j, trieNode, result);
            findWordsHelper(board, i, j - 1, trieNode, result);
            findWordsHelper(board, i, j + 1, trieNode, result);
        }
        board[i][j] = currVal;
    }

    private TrieNode createTrie(String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode node = root;
            for (int i = 0; i < word.length(); i++) {
                int index = index(word.charAt(i));
                if (node.next[index] == null) {
                    node.next[index] = new TrieNode();
                }
                node = node.next[index];
            }
            node.word = word;
        }
        return root;
    }

    private int index(char ch) {
        return ch - 'a';
    }

    private static class TrieNode {
        TrieNode[] next = new TrieNode[26];
        String word;
    }
}
```
