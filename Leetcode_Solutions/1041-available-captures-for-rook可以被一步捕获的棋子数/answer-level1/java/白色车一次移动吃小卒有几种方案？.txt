### 解题思路
1：找到'R'坐标
2：以'R'为坐标中心向四个方向移动，向四个方向找小卒
3：判断：在向某个方向移动过程中，如果到达边界或者遇到象就开始下一个方向寻找，如果先遇到小卒，将方案数res+1再继续开始下一个方向寻找；
4：直到每个方向都寻找完，退出for循环，返回方案数res；

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
    	int[] dx= {1,-1,0,0};
    	int[] dy= {0,0,1,-1};
    	int res=0;
    	for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length; j++) {
				//找到'R'坐标
				if (board[i][j]=='R') {
					//以'R'为坐标中心向四个方向移动
					for (int k = 0; k < 4; k++) {
						int x=i;
						int y=j;
						while (true) {
							x+=dx[k];
							y+=dy[k];
							//在向四个方向移动过程中，如果到达边界或者遇到'B'就退出while循环，开始for循环
							if (x<0||x>7||y<0||y>7||board[x][y]=='B') {
								break;
							}
							if (board[x][y]=='p') {
								res++;
                                break;
							}
								
							}
						}	
					}
				}
			}
    	return res;
		}
  }
```