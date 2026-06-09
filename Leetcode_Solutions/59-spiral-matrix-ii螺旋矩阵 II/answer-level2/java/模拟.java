### 解题思路
**其实这道题目不难以理解，往右下左上四个方向进行扩展即可，数组元素为零表示的意思是之前没有元素填到这个地方，所以循环的条件是数组没有超出边界并且即将要填的位置的元素为零**
第一次写题解写的不好请大佬们多多包含啊，主要是习惯在csdn写博客

### 代码

```java
import java.util.Scanner;
public class Solution {
    public int[][] generateMatrix(int n) {
        if (n == 0) return null;
        int arr[][] = new int[n][n];
        int count = 2;
        int x = 0, y = 0;
        arr[0][0] = 1;
        while (count <= n * n){
            while (y + 1 < n && arr[x][y + 1] == 0){
                arr[x][y + 1] = count++;
                ++y;
            }
            while (x + 1 < n && arr[x + 1][y] == 0){
                arr[x + 1][y] = count++;
                ++x;
            }
            while (y - 1 >= 0 && arr[x][y - 1] == 0){
                arr[x][y - 1] = count++;
                --y;
            }
            while (x - 1 >= 0 && arr[x - 1][y] == 0){
                arr[x - 1][y] = count++;
                --x;
            }
        }
        return arr;
    }
}

