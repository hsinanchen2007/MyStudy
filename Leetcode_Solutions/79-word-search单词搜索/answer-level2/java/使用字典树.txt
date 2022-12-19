
```java []
public  class Solution2 {

        public boolean exist(char[][] board, String word) {
            if (board == null || board.length == 0 || word == null || word.length() == 0) return false;

            Trie trie = new Trie();
            trie.insert(word);

            int rowLength = board.length;
            int colLength = board[0].length;
            boolean[][] marked = new boolean[rowLength][colLength];
            for (int i = 0; i < rowLength; i++) {
                for (int j = 0; j < colLength; j++) {
                    if (search(board, rowLength, colLength, i, j, marked, trie.root)) {
                        return true;
                    }
                }
            }
            return false;
        }

        private boolean search(char[][] board, int rowLength, int colLength, int row, int col, boolean[][] marked, TrieNode node) {
            if (row < 0 || col < 0 || row >= rowLength || col >= colLength || marked[row][col]) return false;

            if (!node.containsKey(board[row][col])) return false;

            node = node.getNode(board[row][col]);

            if (node.isEnd()) return true;

            marked[row][col] = true;
            if (search(board, rowLength, colLength, row + 1, col, marked, node)) return true;
            if (search(board, rowLength, colLength, row - 1, col, marked, node)) return true;
            if (search(board, rowLength, colLength, row, col + 1, marked, node)) return true;
            if (search(board, rowLength, colLength, row, col - 1, marked, node)) return true;
            marked[row][col] = false;
            return false;
        }

        private class Trie {
            TrieNode root = new TrieNode();

            private void insert(String word) {
                TrieNode node = this.root;
                for (char ch : word.toCharArray()) {
                    if (!node.containsKey(ch)) {
                        node.put(ch, new TrieNode());
                    }
                    node = node.getNode(ch);
                }
                node.setEnd();
            }
        }

        private class TrieNode {
            private TrieNode[] nodes = new TrieNode[58];
            private boolean isEnd;

            boolean containsKey(char ch) {
                return nodes[ch - 'A'] != null;
            }

            TrieNode getNode(char ch) {
                return nodes[ch - 'A'];
            }

            void put(char ch, TrieNode node) {
                nodes[ch - 'A'] = node;
            }

            void setEnd() {
                isEnd = true;
            }

            public boolean isEnd() {
                return isEnd;
            }
        }
    }


```
