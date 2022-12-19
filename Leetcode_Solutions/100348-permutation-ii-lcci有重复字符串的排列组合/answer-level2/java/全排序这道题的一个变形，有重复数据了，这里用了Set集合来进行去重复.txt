### 解题思路
全排序这道题的一个变形，有重复数据了，这里用了Set集合来进行去重复。其他的思路同全排序。

### 代码

```java
class Solution {
    public String[] permutation(String S) {
       if (null == S || S.trim().length() == 0) {
            return new String[0];
        }

        char[] board = S.toCharArray();
        Set<String> cache = new HashSet<>();
        backTrackWord(board, cache, 0);
        return cache.stream().toArray(String[]::new);
    }

    private void backTrackWord(char[] board, Set<String> cache, int from) {
        if (from >= board.length) {
            cache.add(new String(board));
            return;
        }

        for (int i = from; i < board.length; i++) {
            swap(board, from, i);
            backTrackWord(board, cache, from + 1);
            swap(board, from, i);
        }
    }

    private void swap(char[] board, int from, int i) {
        char tmp = board[i];
        board[i] = board[from];
        board[from] = tmp;
    }
}
```