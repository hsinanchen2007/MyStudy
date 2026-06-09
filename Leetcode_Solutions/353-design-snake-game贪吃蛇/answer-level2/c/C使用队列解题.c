### 解题思路
C使用队列解题。

### 代码

```c
typedef struct {
    int* index;
    int front;
    int rear;
} SnakeGame;

static int* FOOD;
static int FOODINDEX;
static int FOODLen;
static int ROWS;
static int COLS;

/** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */

SnakeGame* snakeGameCreate(int width, int height, int** food, int foodSize, int* foodColSize) {
    SnakeGame* obj = (SnakeGame*)malloc(sizeof(SnakeGame));
    obj->index = (int*)malloc(7000*sizeof(int));
    memset(obj->index, 0, 7000*sizeof(int));
    obj->front = 0;
    obj->rear = 1;
    FOOD = (int*)malloc(foodSize*sizeof(int));
    for (int i = 0; i < foodSize; i++) {
        FOOD[i] = food[i][0]*width + food[i][1];
    }
    FOODINDEX = 0;
    FOODLen = foodSize;
    ROWS = height;
    COLS = width;
    return obj;
}

bool isFull(SnakeGame* obj)
{
    return obj->rear == 6999;
}

bool addFood(SnakeGame* obj, int x)
{
    if (isFull(obj)) {
        return false;
    }
    else {
        obj->rear++;
        obj->index[obj->rear] = x;
        return true;
    }
}

bool isEmpty(SnakeGame* obj)
{
    return (obj->front == obj->rear);
}

bool deleteFood(SnakeGame* obj)
{
    if (isEmpty(obj)) {
        return false;
    }
    else {
        obj->index[obj->front+1] = 0;
        obj->front++;
        return true;
    }
}

bool isInArea(int x, int y)
{
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

bool alreadyIn(SnakeGame* obj, int x)
{
    for (int i = obj->front+2; i <= obj->rear; i++) {
        if (x == obj->index[i]) {
            return true;
        }
    }
    return false;
}

/** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
int snakeGameMove(SnakeGame* obj, char * direction) {
    int direct[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int n = 0;
    if (strcmp(direction, "U") == 0) {
        n = 0;
    }
    else if (strcmp(direction, "L") == 0) {
        n = 1;
    }
    else if (strcmp(direction, "R") == 0) {
        n = 2;
    }
    else if (strcmp(direction, "D") == 0) {
        n = 3;
    }  
    int newX = obj->index[obj->rear] / COLS + direct[n][0];
    int newY = obj->index[obj->rear] % COLS + direct[n][1];
    int newIndex = newX * COLS + newY;
    if (!isInArea(newX, newY) || alreadyIn(obj, newIndex)) {
        return -1;
    }
    addFood(obj, newIndex);
    if ((FOODINDEX < FOODLen && FOOD[FOODINDEX] != newIndex) || FOODINDEX >= FOODLen) {
        deleteFood(obj);
    }
    else {
        FOODINDEX++;
    }
    return obj->rear - obj->front-1;
}

void snakeGameFree(SnakeGame* obj) {
    free(obj);
}

/**
 * Your SnakeGame struct will be instantiated and called as such:
 * SnakeGame* obj = snakeGameCreate(width, height, food, foodSize, foodColSize);
 * int param_1 = snakeGameMove(obj, direction);
 
 * snakeGameFree(obj);
*/
```