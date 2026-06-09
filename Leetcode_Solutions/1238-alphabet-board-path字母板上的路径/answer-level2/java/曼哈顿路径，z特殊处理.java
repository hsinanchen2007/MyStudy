思路：首先转换字母到坐标，接下来就是计算两点间的曼哈顿路径；需要注意的是，Z这一行比较特殊，只有1列，如果前一个字符是z，需要首先移动行，如果当前字符是z，需要首先移动列
对于移动方向的计算，需要以前一个字符的坐标和当前字符的坐标作对比

```
class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder sb = new StringBuilder();
        int preRow = 0;
        int preCol = 0;
        Map<Integer, String> horizontal = new HashMap<>();
        horizontal.put(-1, "U");
        horizontal.put(0, "");
        horizontal.put(1, "D");
        Map<Integer, String> vertical = new HashMap<>();
        vertical.put(-1, "L");
        vertical.put(0, "");
        vertical.put(1, "R");
        for (int k = 0; k < target.length(); k++) {
            char c = target.charAt(k);
            int row = (c - 'a') / 5;
            int col = (c - 'a') % 5;

            int realRow = row;
            int realCol = col;
            int readlPreRow = preRow;

            // 如果前一个或者当前是Z，需要特殊处理
            if (preRow == 5) {
                // 前一个是z，先移动行，保持一致后，行不再需要移动
                for (int i = 0; i < Math.abs(preRow - row); i++) {
                    sb.append("U");
                }
                preRow = 0;
                row = 0;
            }

            if (row == 5) {
                // 当前是z，先移动列，保持一致后，列不需要再移动
                for (int j = 0; j < Math.abs(preCol - col); j++) {
                    sb.append("L");
                }
                col = 0;
                preCol = 0;
            }


            int horizontalRatio = 0;
            if (preRow > row) {
                horizontalRatio = -1;
            } else if (preRow < row) {
                horizontalRatio = 1;
            }

            int verticalRatio = 0;
            if (preCol > col) {
                verticalRatio = -1;
            } else if (preCol < col) {
                verticalRatio = 1;
            }

            for (int i = 0; i < Math.abs(preRow - row); i++) {
                sb.append(horizontal.get(horizontalRatio));
            }
            for (int j = 0; j < Math.abs(preCol - col); j++) {
                sb.append(vertical.get(verticalRatio));
            }


            sb.append("!");
            preRow = realRow;
            preCol = realCol;
        }

        return sb.toString();
    }
}
```
