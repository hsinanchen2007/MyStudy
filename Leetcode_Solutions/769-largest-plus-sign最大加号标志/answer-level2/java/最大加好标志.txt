### 解题思路
暴力解法，
很容易超时，要把能够减少运算的方式都考虑一下。
### 代码

```java
class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        int maxResult = 0;
        int[][] map = new int[N][N];
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = 1;
            }
        }
        for (int i = 0; i < mines.length; i++) {
            map[mines[i][0]][mines[i][1]] = 0;
        }
    
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1) {
                    int minLength = min(min(min(i+1, j+1), N-i), N-j);
                    if (minLength <= maxResult) {
                        continue;
                    }
                    int up = upDFS(map, N, i, j);
                    if (up < maxResult) {
                        continue;
                    }
                    int down = downDFS(map, N, i, j);
                    if (down < maxResult) {
                        continue;
                    }
                    int left = leftDFS(map, N, i, j);
                    if (left < maxResult) {
                        continue;
                    }
                    int right = rightDFS(map, N, i, j);
                    if (right < maxResult) {
                        continue;
                    }
                    int length = min(min(min(up, down), left), right);
                    maxResult = maxResult > length ? maxResult : length;
                }
            }
        }
        return maxResult;
    }
    int min(int X, int Y) {
        return X > Y ? Y : X;
    }
    int upDFS(int [][]map, int N, int curX, int curY) {
        if (curX < 0 || curX >= N || curY < 0 || curY >= N || map[curX][curY] == 0) {
            return 0;
        }
       
        return upDFS(map, N, curX-1, curY)+1;
    }
    int downDFS(int [][]map, int N, int curX, int curY) {
        if (curX < 0 || curX >= N || curY < 0 || curY >= N || map[curX][curY] == 0) {
            return 0;
        }
        return downDFS(map, N, curX+1, curY)+1;
    }
    int leftDFS(int [][]map, int N, int curX, int curY) {
        if (curX < 0 || curX >= N || curY < 0 || curY >= N || map[curX][curY] == 0) {
            return 0;
        }
        
        return leftDFS(map, N, curX, curY-1)+1;
    }
    int rightDFS(int [][]map, int N, int curX, int curY) {
        if (curX < 0 || curX >= N || curY < 0 || curY >= N || map[curX][curY] == 0) {
            return 0;
        }
        return rightDFS(map, N, curX, curY+1)+1;
    }
}
```