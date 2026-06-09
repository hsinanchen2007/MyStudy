```
#define WALL -1
#define DOOR 0
#define ROOM 2147483647
#define INVALID -1
#define SUCCESS 0
#define FAIL 1
#define FOUR_DIR 4
#define DIM 2


typedef struct _queue {
    int cap;
    int size;
    int *index;
    int head;
    int tail;
} Queue;

void Reset_queue(Queue *input)
{
    input->size = 0;
    input->head = 0;
    input->tail = INVALID;
}

void Create_queue(Queue* queue, int size)
{
    if (size == 0) {
        return;
    }
    Reset_queue(queue);
    queue->cap = size;
    queue->index = malloc(size * sizeof(int));
    return;
}

int Is_full(Queue *input)
{
    return (input->size >= input->cap);
}

int Is_empty(Queue *input)
{
    return (input->size == 0);
}

int Push_back(Queue *input, int value)
{
    if (Is_full(input)) {
        return FAIL;
    }
    input->tail++;
    input->tail = input->tail % input->cap;
    input->size++;
    input->index[input->tail] = value;

    return SUCCESS;
}

int Pop(Queue *input)
{
    int retVal;
    if (Is_empty(input)) {
        return FAIL;
    }

    retVal = input->index[input->head];
    input->head++;
    input->head = input->head % input->cap;
    input->size--;

    return retVal;
}
void Queue_Destroy(Queue *queue) {
    free(queue->index);
    queue->index = NULL;
    Reset_queue(queue);
}
int Get_index(int x, int y, int maxY)
{
    return x * maxY + y;
}

static const int s_dirs[FOUR_DIR][DIM] = {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }};

int Is_out_of_maze(int x, int y, int maxX, int maxY) {
    return ((x < 0) || (y < 0) || (x >= maxX) || (y >= maxY));
}

void BFS(int **rooms, Queue *queue, int startX, int startY, int maxX, int maxY)
{
    Reset_queue(queue);
    Push_back(queue, Get_index(startX, startY, maxY));

    while (!Is_empty(queue)) {
        int curX, curY, nextX, nextY;
        int current = Pop(queue);
        curX = current / maxY;
        curY = current % maxY;
        for (int i = 0; i < FOUR_DIR; i++) {
            nextX = curX + s_dirs[i][0];
            nextY = curY + s_dirs[i][1];

            if (Is_out_of_maze(nextX, nextY, maxX, maxY)) {
                continue;
            }
            if ((rooms[nextX][nextY] == WALL) || (rooms[nextX][nextY] <= rooms[curX][curY])){
                continue;
            }
            rooms[nextX][nextY] = rooms[curX][curY] + 1;
            Push_back(queue, Get_index(nextX, nextY, maxY));

        }
    }
    return;
}

void wallsAndGates(int **rooms, int roomsSize, int *roomsColSize)
{
    if ((roomsSize == 0) || (*roomsColSize == 0)) {
        return;
    }

    Queue queue;
    Create_queue(&queue, roomsSize * (*roomsColSize));

    for (int x = 0; x < roomsSize; x++) {
        for (int y = 0; y < *roomsColSize; y++) {
            if (rooms[x][y] == DOOR) {
                BFS(rooms, &queue, x, y, roomsSize, *roomsColSize);
            }
        }
    }
    Queue_Destroy(&queue);
    return;
}
```
