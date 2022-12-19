典型的广度优先遍历（60 ms， 12.7 MB）


    typedef struct {
        int x;
        int y;
    } Vec2;

    bool ClickM(char** board, Vec2 *click)
    {
        if (board[click->y][click->x] == 'M') {
            board[click->y][click->x] = 'X';
            return true;
        }

        return false;
    }

    int GetNeighbourM(char** board, int row, int col, Vec2 *pos)
    {
        int num = 0;
        if (pos->x < col - 1 && board[pos->y][pos->x + 1] == 'M') {
            num++;
        }
        if (pos->x > 0 && board[pos->y][pos->x - 1] == 'M') {
            num++;
        }
        if (pos->y < row - 1 && board[pos->y + 1][pos->x] == 'M') {
            num++;
        }
        if (pos->y > 0 && board[pos->y - 1][pos->x] == 'M') {
            num++;
        }
        if (pos->x < col - 1 && pos->y > 0 && board[pos->y - 1][pos->x + 1] == 'M') {
            num++;
        }
        if (pos->x < col - 1 && pos->y < row - 1 && board[pos->y + 1][pos->x + 1] == 'M') {
            num++;
        }
        if (pos->x > 0 && pos->y < row - 1 && board[pos->y + 1][pos->x - 1] == 'M') {
            num++;
        }
        if (pos->x > 0 && pos->y > 0 && board[pos->y - 1][pos->x - 1] == 'M') {
            num++;
        }

        return num;
    }

    bool ClickNeighbourM(char** board, int row, int col, Vec2 *click)
    {
        int num = GetNeighbourM(board, row, col, click);
        if (num > 0) {
            board[click->y][click->x] = '0' + num;
            return true;
        }
        return false;
    }

    void AddAllNeighbour(bool *vist, Vec2 *vecList, int *tear, int row, int col, Vec2 *pos)
    {
        if (pos->x < col - 1 && !vist[pos->y * col + pos->x + 1]) {
            vecList[*tear].x = pos->x + 1;
            vecList[*tear].y = pos->y;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
        if (pos->x > 0 && !vist[pos->y * col + pos->x - 1]) {
            vecList[*tear].x = pos->x - 1;
            vecList[*tear].y = pos->y;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
        if (pos->y < row - 1 && !vist[(pos->y + 1) * col + pos->x]) {
            vecList[*tear].x = pos->x;
            vecList[*tear].y = pos->y + 1;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
        if (pos->y > 0 && !vist[(pos->y - 1) * col + pos->x]) {
            vecList[*tear].x = pos->x;
            vecList[*tear].y = pos->y - 1;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
        if (pos->x < col - 1 && pos->y > 0 && !vist[(pos->y - 1) * col + pos->x + 1]) {
            vecList[*tear].x = pos->x + 1;
            vecList[*tear].y = pos->y - 1;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
        if (pos->x < col - 1 && pos->y < row - 1 && !vist[(pos->y + 1) * col + pos->x + 1]) {
            vecList[*tear].x = pos->x + 1;
            vecList[*tear].y = pos->y + 1;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
        if (pos->x > 0 && pos->y < row - 1 && !vist[(pos->y + 1) * col + pos->x - 1]) {
            vecList[*tear].x = pos->x - 1;
            vecList[*tear].y = pos->y + 1;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
        if (pos->x > 0 && pos->y > 0 && !vist[(pos->y - 1) * col + pos->x - 1]) {
            vecList[*tear].x = pos->x - 1;
            vecList[*tear].y = pos->y - 1;
            vist[vecList[*tear].y * col + vecList[*tear].x] = true;
            *tear = *tear + 1;
        }
    }

    void ClickE(char** board, int row, int col, Vec2 *click)
    {
        int head = 0;
        int tear = 0;
        int num = 0;
        Vec2 *vecList = (Vec2 *)malloc(sizeof(Vec2) * row * col);
        bool *vist = (bool *)malloc(sizeof(bool) * row * col);
        (void)memset(vist, 0, sizeof(bool) * row * col);

        vecList[tear].x = click->x;
        vecList[tear].y = click->y;
        vist[click->y * col + click->x] = true;
        tear++;

        while (head < tear) {
            num = GetNeighbourM(board, row, col, vecList + head);
            if (num > 0) {
                board[vecList[head].y][vecList[head].x] = '0' + num;
            } else {
                board[vecList[head].y][vecList[head].x] = 'B';
                AddAllNeighbour(vist, vecList, &tear, row, col, vecList + head);
            }
            head++;
        }

        free(vecList);
        free(vist);
    }

    /**
    * Return an array of arrays of size *returnSize.
    * The sizes of the arrays are returned as *returnColumnSizes array.
    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
    */
    char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
        int i;
        int colNum = boardColSize[0];
        char **out = NULL;
        Vec2 clickPos;

        *returnSize = boardSize;
        *returnColumnSizes = (int *)malloc(sizeof(int) * boardSize);
        out = (char **)malloc(sizeof(char *) * boardSize);
        for (i = 0; i < boardSize; i++) {
            (*returnColumnSizes)[i] = boardColSize[i];
            out[i] = (char *)malloc(sizeof(char) * boardColSize[i]);
            memcpy(out[i], board[i], boardColSize[i] * sizeof(char));
        }

        clickPos.x = click[1];
        clickPos.y = click[0];
        if (clickPos.x >= colNum || clickPos.x < 0 || clickPos.y >= boardSize || clickPos.y < 0) {
            return out;
        }

        if (ClickM(out, &clickPos) || ClickNeighbourM(out, boardSize, colNum, &clickPos)) {
            return out;
        }

        ClickE(out, boardSize, colNum, &clickPos);

        return out;
    }