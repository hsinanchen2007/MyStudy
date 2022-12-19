```java
class Solution {
    private static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private Pair[] board = new Pair[26];
    public String alphabetBoardPath(String target) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < 26; i++) {
            board[i] = new Pair(x, y++);
            if (y == 5) {
                x++;
                y = 0;
            }
        }
        x = 0;
        y = 0;
        Pair pair;
        StringBuilder sb = new StringBuilder();
        for (char c : target.toCharArray()) {
            pair = board[c - 'a'];

            // 向左走
            if (pair.y < y) {
                for (int i = 0; i < y - pair.y; i++) {
                    sb.append("L");
                }
            }
            // 向上走
            if (pair.x < x) {
                for (int i = 0; i < x - pair.x; i++) {
                    sb.append("U");
                }
            }
            // 向下走
            if (pair.x > x) {
                for (int i = 0; i < pair.x - x; i++) {
                    sb.append("D");
                }
            }
            // 向右走
            if (pair.y > y) {
                for (int i = 0; i < pair.y - y; i++) {
                    sb.append("R");
                }
            }

            sb.append("!");
            x = pair.x;
            y = pair.y;
        }
        return sb.toString();
    }

}
```
