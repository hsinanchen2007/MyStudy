**思路: 单纯DFS超时了, 只能用字典树来剪枝, 一旦前缀不存在直接返回**

# Trie
```
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode trie = new TrieNode();
        Set<String> result = new HashSet<>();
        for (String i : words) {
            trie.insert(i);
        }
        int rows = board.length;
        int cols = board[0].length;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                buildTrie(board, i, j, "", result, trie);
            }
        }
        return new LinkedList<String>(result);
    }
    void buildTrie(char[][] board, int i, int j, String str, Set<String> result, TrieNode trie) {
        if (i < 0 || i == board.length || j < 0 || j == board[0].length) return;
        if (board[i][j] == '@' || !trie.startWith(str)) return;

        str += board[i][j];
        if (trie.contains(str)) {
            result.add(str);
        }
        
        char tmp = board[i][j];
        board[i][j] = '@';
        buildTrie(board, i + 1, j, str, result, trie);
        buildTrie(board, i - 1, j, str, result, trie);
        buildTrie(board, i, j - 1, str, result, trie);
        buildTrie(board, i, j + 1, str, result, trie);
        board[i][j] = tmp;
    }
}

class TrieNode {
    private boolean isEndOfWord = false;
    private final int ALPHABET_SIZE = 26;
    TrieNode[] children = new TrieNode[ALPHABET_SIZE];
    TrieNode() {
        Arrays.fill(children, null);
    }
    void insert(String str) {
        if (str == null) {
            return;
        }
        TrieNode tmp = this;
        for (char i : str.toCharArray()) {
            if (tmp.children[i - 'a'] == null) {
                tmp.children[i - 'a'] = new TrieNode();
            }
            tmp = tmp.children[i - 'a'];
        }
        tmp.isEndOfWord = true;
    }
    boolean contains(String str) {
        if (str == null) {
            return false;
        }
        TrieNode tmp = this;
        for (int i : str.toCharArray()) {
            if (tmp.children[i - 'a'] == null) {
                return false;
            }
            tmp = tmp.children[i - 'a'];
        }
        return tmp.isEndOfWord;
    }
    boolean startWith(String str) {
        if (str == null) {
            return true;
        }
        TrieNode tmp = this;
        for (char i  : str.toCharArray()) {
            if (tmp.children[i - 'a'] == null) {
                return false;
            }
            tmp = tmp.children[i - 'a'];
        }
        return true;
    }
}
```