### 解题思路
代码懒得一批：BFS

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int i;
    int j;
}INDEX_ID;
 typedef struct {
     INDEX_ID index[3000];
     int head;
     int tail; 
 }QUEUE;
 int visit[51][51];
 bool isM(int i, int j, char** board, int boardSize, int* boardColSize)
{
    if((i > 0 && board[i-1][j] == 'M') || 
        (j > 0 && board[i][j-1] == 'M') ||
        (i > 0 && j > 0 && board[i-1][j-1] == 'M') || 
        (i < boardSize-1 && j < boardColSize[0]-1 && board[i+1][j+1] == 'M') ||
        (i < boardSize-1 && j > 0 && board[i+1][j-1] == 'M') ||
        (i > 0 && j < boardColSize[0]-1 && board[i-1][j+1] == 'M') ||
        (j < boardColSize[0]-1 && board[i][j+1] == 'M') ||
        (i < boardSize-1 && board[i+1][j] == 'M')) {
        return true;
    }
    return false;
}
bool isOkPro(int i, int j, char** board, int boardSize, int* boardColSize)
{
    if((board[i][j] == 'B') || (board[i][j] == 'E' && isM(i, j, board, boardSize, boardColSize) == false)) {
        return true;
    }
    return false;
}
bool isOk(int i, int j, char** board, int boardSize, int* boardColSize)
{
    if((i > 0 && (isOkPro(i-1, j, board, boardSize, boardColSize) == true)) || 
        (j > 0 && (isOkPro(i, j-1, board, boardSize, boardColSize) == true)) ||
        (i > 0 && j > 0 && (isOkPro(i-1, j-1, board, boardSize, boardColSize) == true)) || 
        (i < boardSize-1 && j < boardColSize[0]-1 && (isOkPro(i+1, j+1, board, boardSize, boardColSize) == true)) ||
        (i < boardSize-1 && j > 0 && (isOkPro(i+1, j-1, board, boardSize, boardColSize) == true)) ||
        (i > 0 && j < boardColSize[0]-1 && (isOkPro(i-1, j+1, board, boardSize, boardColSize) == true)) ||
        (j < boardColSize[0]-1 && (isOkPro(i, j+1, board, boardSize, boardColSize) == true)) ||
        (i < boardSize-1 && (isOkPro(i+1, j, board, boardSize, boardColSize) == true))) {
        return true;
    }
    return false;
}
void funb(int i, int j, char **board, int *mNum)
{
    if(board[i][j] == 'M') {
        (*mNum)++;
    }
}
void funq(int i, int j, char **board, QUEUE* q)
{
    if(visit[i][j] != 1 && (board[i][j] == 'E')) {
        q->index[q->tail].i = i;
        q->index[q->tail].j = j;
        q->tail++;
        visit[i][j] = 1;
    }
}
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    *returnSize = boardSize;
    *returnColumnSizes = boardColSize;
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    memset(q, 0, sizeof(QUEUE));
    
    memset(visit, 0, 51*51*sizeof(int));
    if(board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
        free(q);
        return board;
    }

    //将第一个元素加入队列
    q->index[q->tail].i = click[0];
    q->index[q->tail].j = click[1];
    q->tail++;

    //遍历队列
    while(q->tail != q->head) {
        int head = q->head;
        int tail = q->tail;
        for(int i = head; i < tail; i++) {            
            int headi = q->index[i].i;
            int headj = q->index[i].j;
            visit[headi][headj] = 1;
            //找head节点的邻接点加入队列
            int mNum = 0;//相邻的地雷数
            if(headi > 0) {
                funb(headi-1, headj, board, &mNum);
                if(headj > 0) {
                    funb(headi-1, headj-1, board, &mNum);
                }
                if(headj < boardColSize[0]-1) {
                    funb(headi-1, headj+1, board,  &mNum);
                }
            }
            if(headj > 0) {
                funb(headi, headj-1, board, &mNum);
                if(headi < boardSize-1) {
                    funb(headi+1, headj-1, board, &mNum);                    
                }
            }
            if(headi < boardSize-1) {
                funb(headi+1, headj, board, &mNum);
                if(headj < boardColSize[0]-1) {
                    funb(headi+1, headj+1, board, &mNum);
                }
            }
            if(headj < boardColSize[0]-1) {
                funb(headi, headj+1, board, &mNum);
            }
            if(board[headi][headj] == 'M') {

            } else if(mNum == 0) {
                board[headi][headj] = 'B';
            } else {
			    if(isOk(headi, headj, board, boardSize, boardColSize) == true || (headi == click[0] && headj == click[1])) {
                    board[headi][headj] = mNum + '0';
                }
            }
			if(board[headi][headj]-'0' >= 1 && board[headi][headj]-'0' <= 8) {
				
			} else {
				if(headi > 0) {
					funq(headi-1, headj, board, q);
					if(headj > 0) {
						funq(headi-1, headj-1, board, q);
					}
					if(headj < boardColSize[0]-1) {
						funq(headi-1, headj+1, board, q);
					}
				}
				if(headj > 0) {
					funq(headi, headj-1, board, q);
					if(headi < boardSize-1) {
						funq(headi+1, headj-1, board, q);                    
					}
				}
				if(headi < boardSize-1) {
					funq(headi+1, headj, board, q);
					if(headj < boardColSize[0]-1) {
						funq(headi+1, headj+1, board, q);
					}
				}
				if(headj < boardColSize[0]-1) {
					funq(headi, headj+1, board, q);
				}
			}
			
            q->head++;

        }
    }

    free(q);
    return board;
}
```