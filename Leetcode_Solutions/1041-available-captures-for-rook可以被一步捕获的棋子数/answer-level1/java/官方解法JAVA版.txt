### 解题思路
1.定义方向坐标数组dx，dy。
2.for循环找出R位置
3.for循环四次，遍历四个方向

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int eat = 0;
        //找出R位置
		int[] posR = findR(board);
        //定义方向坐标
		int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        //for循环四次，遍历四个方向
        for (int i = 0; i < 4; ++i) {
            for (int step = 0;; ++step) {
                int tx = posR[0] + step * dx[i];
                int ty = posR[1] + step * dy[i];
                //到达边界或者遇到友军
                if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') break;
                //敌军
                if (board[tx][ty] == 'p') {
                    eat++;
                    break;
                }
            }
        }     
		return eat;
    }
    public static int[] findR(char[][] board) {
        //for循环找出R位置
		int[] pos = new int[] {-1,-1};
		for(int i = 0; i < 8 ; i++) {
			for(int j = 0; j < 8 ; j++) {
				if(board[i][j] == 'R') {
					pos[0] = i;
					pos[1] = j;
					return pos;
				}
			}
		}
		return pos;
	}
}
```