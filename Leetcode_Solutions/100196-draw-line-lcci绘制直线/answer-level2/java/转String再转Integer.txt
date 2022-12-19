没啥好说的，单纯的利用**内置函数**

# 代码
```java [-二维数组]
class Solution {
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        int width = w >> 5, height = length / width, idx = 0;
        char[][] screen = new char[height][w];
        for (char[] row : screen)
            Arrays.fill(row, '0');
        for (int i = x1; i <= x2; ++i)
            screen[y][i] = '1';
        int[] res = new int[length];
        for (char[] row : screen)
            for (int j = 0; j < w; j += 32)
                res[idx++] = Integer.parseUnsignedInt(String.valueOf(row, j, 32), 2);

        return res;
    }
}
```
```java [-一维数组]
class Solution {
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        char[] screen = new char[length << 5];
        Arrays.fill(screen, '0');
        int base = y * w;
        for (int i = x1; i <= x2; ++i)
            screen[base + i] = '1';
        int[] res = new int[length];
        int idx = 0, total_bits = length << 5;
        for (int j = 0; j < total_bits; j += 32)
            res[idx++] = Integer.parseUnsignedInt(String.valueOf(screen, j, 32), 2);

        return res;
    }
}
```
