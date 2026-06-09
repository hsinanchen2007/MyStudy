### 解题思路
基本思路：先找到R的位置，然后再上下左右进行遍历。 并且分为if B 与 else if P 两种方式
C语言和java代码实现基本类似，python更简洁
### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
	int res = 0;
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < *boardColSize; j++){
			if (board[i][j] == 'R'){               //找到时
				for (int l = j - 1; l >= 0; l--){
					if (board[i][l] == 'B')
						break;
					else if (board[i][l] == 'p'){
						res++;
						break;
					}
				}
				for (int r = j + 1; r <*boardColSize; r++){
					if (board[i][r] == 'B')
						break;
					else if (board[i][r] == 'p'){
						res++;
						break;
					}
				}
				for (int u = i - 1; u >= 0; u--){
					if (board[u][j] == 'B')
						break;
					else if (board[u][j] == 'p'){
						res++;
						break;
					}
				}
				for (int d = i + 1; d<boardSize; d++){
					if (board[d][j] == 'B')
						break;
					else if (board[d][j] == 'p'){
						res++;
						break;
					}
				}
				return res;
			}
		}
	}
    return res;
}

// python实现
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        cnt, st, ed = 0, 0, 0
        dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]   #构造上下左右数组很秀
        for i in range(8):
            for j in range(8):
                if board[i][j] == "R":
                    st, ed = i, j     #基本步骤找到R位置
        for i in range(4):                #for循环提供step
            step = 0
            while True:
                tx = st + step * dx[i]
                ty = ed + step * dy[i]    #妙！ 计数进行位置移动
                if tx < 0 or tx >= 8 or ty < 0 or ty >= 8 or board[tx][ty] == "B":  #break的边界与B条件
                    break
                if board[tx][ty] == "p":
                    cnt += 1
                    break
                step += 1    #y如果没遇到，则步数++
        return cnt
```