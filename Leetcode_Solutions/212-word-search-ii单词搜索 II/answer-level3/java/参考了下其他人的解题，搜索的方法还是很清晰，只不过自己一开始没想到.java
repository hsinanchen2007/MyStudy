### 解题思路
参考了下其他人的解题，搜索的方法还是很清晰，只不过自己一开始没想到

### 代码

```java
/*
 * Copyright (c) 2020
 * Author: xiaoweixiang
 */
class Solution {
    public static void main(String[] args) {
        char[][] board = {{'a', 'a'}};
        String[] words = {"aaa"};
        Solution solution = new Solution();
        List<String> list = solution.findWords(board, words);
        list.forEach(s -> System.out.println("s = " + s));
    }

    class Node {
        boolean isWord;
        String s;
        HashMap<Character, Node> children = new HashMap<Character, Node>();
    }

    public List<String> findWords(char[][] board, String[] words) {
        for (String word : words) {
            insert(word);
        }
        int h = board.length;
        int w = board[0].length;
        Set<String> set = new HashSet<>();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                boolean[][] record = new boolean[h][w];
                dfs(i, j, h, w, set, root.children.get(board[i][j]), board,record);
            }
        }
        return new ArrayList<>(set);
    }

    private void dfs(int i, int j, int h, int w, Set<String> set, Node head, char[][] board, boolean[][] record) {
        if (i < 0 || i >= h || j < 0 || j >= w || head == null||record[i][j]) {
            return;
        }
        record[i][j]=true;
        if (head.isWord) set.add(head.s);
        if (i - 1 >= 0) dfs(i - 1, j, h, w, set, head.children.get(board[i - 1][j]), board, record);
        if (j - 1 >= 0) dfs(i, j - 1, h, w, set, head.children.get(board[i][j - 1]), board, record);
        if (j + 1 < w) dfs(i, j + 1, h, w, set, head.children.get(board[i][j + 1]), board, record);
        if (i + 1 < h) dfs(i + 1, j, h, w, set, head.children.get(board[i + 1][j]), board, record);
        record[i][j]=false;
    }

    Node root = new Node();

    private void insert(String s) {
        Node head = root;
        char[] array = s.toCharArray();
        for (char c : array) {
            if (head.children.get(c) == null) {
                head.children.put(c, new Node());
            }
            head = head.children.get(c);
        }
        head.isWord = true;
        head.s = s;
    }
}
```