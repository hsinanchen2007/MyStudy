虽然有些点满足**行坐标和列坐标的数位之和不大于k**但是这些点是到达不了的
```java
public static void main(String[] args) {
    int m = 16, n = 8, k = 4;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (new Solution().add(i, j) <= k) {
                System.out.print("(" + i + "," + j + ")" + "[" + new Solution().add(i, j) + "]√" + "\t");
            } else {
                System.out.print("(" + i + "," + j + ")" + "[" + new Solution().add(i, j) + "]" + "\t");
            }
        }
        System.out.println();
    }
}
```
```java
/**
 * 行坐标和列坐标的数位之和
 */
private int add(int a, int b) {
    int res = 0;
    String str = a + "" + b;
    for (int i = 0; i < str.length(); i++) {
        res += str.charAt(i) - '0';
    }
    return res;
}
```
![image.png](https://pic.leetcode-cn.com/602e08bfbbc5e33c7ad29d467637f7dc09a2450e9af145ed3426385a71633b23-image.png)


用一个数组标记出所有满足条件的点，然后从(0, 0)出发，寻找能和(0, 0)连通的点即可
```java
class Solution {
    private int[][] d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    private int count;
    private boolean[][] arr;
    public int movingCount(int m, int n, int k) {
        arr = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (add(i, j) <= k) {
                    arr[i][j] = true;
                }
            }
        }
        dfs(0, 0);
        return count;
    }
    private void dfs(int x, int y) {
        //不满足条件
        if (!arr[x][y]) {
            return;
        }
        if (arr[x][y]) {
            count++;
            arr[x][y] = false;
            //下一个点
            for (int i = 0; i < 4; i++) {
                int newX = x + d[i][0];
                int newY = y + d[i][1];
                if (judgment(newX, newY) && arr[newX][newY]) {
                    dfs(newX, newY);
                }
            }
        }
    }
    /**
     * @param i 横坐标
     * @param j 纵坐标
     * @return 判断是否越界
     */
    private boolean judgment(int i, int j) {
        return i >= 0 && i < arr.length && j >= 0 && j < arr[0].length;
    }
    /**
     * 行坐标和列坐标的数位之和
     */
    private int add(int a, int b) {
        int res = 0;
        String str = a + "" + b;
        for (int i = 0; i < str.length(); i++) {
            res += str.charAt(i) - '0';
        }
        return res;
    }
}
```

```java
//public static void main(String[] args) {
//    //System.out.println(new Solution().add(35, 38));
//    //System.out.println(new Solution().movingCount(2, 3, 1));
//    //System.out.println(new Solution().movingCount(3, 1, 0));
//    //15
//    System.out.println(new Solution().movingCount(16, 8, 4));
//}
```



[https://blog.csdn.net/qq_40794973/article/details/102473737](floodfill)
[https://blog.csdn.net/qq_40794973/article/details/102944107](Union Find)
