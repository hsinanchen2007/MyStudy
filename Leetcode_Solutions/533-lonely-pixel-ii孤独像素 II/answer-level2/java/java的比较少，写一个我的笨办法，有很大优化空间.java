执行用时 :56 ms, 在所有 Java 提交中击败了11.11%的用户

内存消耗 :42 MB, 在所有 Java 提交中击败了100.00%的用户

1、用HashMap分别将每行的字符串记录下来
2、用HashMap分别将每行和每列的黑色元素数量记录下来，方便后边比较判断
3、将所有黑色B的位置入Queue，每次出队时做判断，不符合任何一个条件就结束，继续判断队列中下一个。

```
class Solution {
    public int findBlackPixel(char[][] picture, int N) {
        if (picture == null || picture.length == 0 || picture[0].length == 0) {
            return 0;
        }
        int result = 0;
        HashMap<Integer, String> lineStr = new HashMap<>();
        HashMap<Integer, Integer> lineBlackCount = new HashMap<>();
        Queue<Pix> queue = new LinkedList<>();
        for (int line = 0; line < picture.length; line++) {
            StringBuilder sb = new StringBuilder();
            int bCount = 0;
            for (int lie = 0; lie < picture[0].length; lie++) {
                sb.append(picture[line][lie]);
                if (picture[line][lie] == 'B') {
                    // 所有的'B'的位置入队
                    queue.offer(new Pix(line, lie));
                    bCount++;
                }
            }
            // 将行号与每行的String记录
            lineStr.put(line, sb.toString());
            // 将行号和每行的黑色数量记录
            lineBlackCount.put(line, bCount);
        }
        HashMap<Integer, Integer> lieBlackCount = new HashMap<>();
        for (int lie = 0; lie < picture[0].length; lie++) {
            int bCount = 0;
            for (char[] element : picture) {
                if (element[lie] == 'B') {
                    bCount++;
                }
            }
            // 将列号和每列的黑色数量记录
            lieBlackCount.put(lie, bCount);
        }

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int each = 0; each < size; each++) {
                // 每次出队
                Pix cur = queue.poll();
                int px = cur.px;
                int py = cur.py;
                boolean flag = false;
                // 如果列的黑色数量不是N或者行的黑色数量不是N，标记位置为true
                if (lieBlackCount.get(py) != N || N != lineBlackCount.get(px)) {
                    flag = true;
                }

                for (int hang = 0; hang < picture.length; hang++) {
                    if (hang == px) {
                        continue;
                    }
                    // 对于px py 这个元素对应改行，如果px该行的String与其他行的String不一样，则标志位置为true
                    if (picture[hang][py] == 'B') {
                        if (!lineStr.get(px).equals(lineStr.get(hang))) {
                            flag = true;
                        }
                    }
                }
                // 标志位为true，就是说肯定有某个条件不满足，则继续查找队列中下一个，否则结果++
                if (flag) {
                    continue;
                }
                result++;
            }
        }
        return result;
    }
}

// 记录每个B的坐标
class Pix {
    int px;

    int py;

    Pix(int pix, int piy) {
        px = pix;
        py = piy;
    }
}
```


