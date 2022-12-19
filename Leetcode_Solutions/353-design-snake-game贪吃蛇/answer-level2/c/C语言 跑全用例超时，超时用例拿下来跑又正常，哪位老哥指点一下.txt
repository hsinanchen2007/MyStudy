时间关系，队列是裸奔的实现
```
#define MAX_SIZE 1000000
typedef struct {
    int width;
    int height;
    int que[MAX_SIZE][2];
    int hash[MAX_SIZE];
    int **food;
    int foodSize;
    int foodIndex;
    int head;
    int tail;
    int score;
} SnakeGame;
SnakeGame* snakeGameCreate(int width, int height, int** food, int foodSize, int* foodColSize) {
    SnakeGame* game = (SnakeGame*)malloc(sizeof(SnakeGame));
    memset(game, 0, sizeof(SnakeGame));
    game->width = width;
    game->height = height;
    game->food = food;
    game->foodSize = foodSize;
    game->que[0][0] = 0;
    game->que[0][1] = 0;
    game->hash[0] = 1;
    game->tail++;
    return game;
}
int Valid(int width, int height, int x, int y) {
    return x >= 0 && y >= 0 && x < height && y < width;
}
int snakeGameMove(SnakeGame* obj, char * direction) {
    int x = obj->que[obj->tail - 1][0];
    int y = obj->que[obj->tail - 1][1];
    if (direction[0] == 'U') {
        x -=1;
    } else if (direction[0] == 'R') {
        y += 1;
    } else if (direction[0] == 'L') {
        y -= 1;
    } else if (direction[0] == 'D') {
        x += 1;
    }
    if (!Valid(obj->width, obj->height, x, y)) {
        obj->score = -1;
        return -1;
    }
    if (obj->foodIndex == obj->foodSize 
        && obj->tail - obj->head <= 4) {
        obj->que[obj->tail][0] = x;
        obj->que[obj->tail][1] = y;
        obj->tail++;
        obj->head++;
        return obj->score;
    }
    obj->que[obj->tail][0] = x;
    obj->que[obj->tail][1] = y;
    obj->tail++;
    if (obj->foodIndex < obj->foodSize 
        && obj->food[obj->foodIndex][0] == x 
        && obj->food[obj->foodIndex][1] == y) {
            obj->foodIndex++;
        obj->score++;
        obj->hash[x * obj->width + y] = 1;
        return obj->score;
    }
    int tailx = obj->que[obj->head][0];
    int taily = obj->que[obj->head][1];
    obj->head++;
    obj->hash[tailx * obj->width + taily] = 0;
    
    if (obj->hash[x * obj->width + y] == 0) {
        obj->hash[x * obj->width + y] = 1;
        return obj->score;
    } else {
        obj->score = -1;
        return -1;
    }
    return 0;
}
```
