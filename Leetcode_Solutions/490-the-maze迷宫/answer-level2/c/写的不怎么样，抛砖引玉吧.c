```
typedef struct {
    int x;
    int y;
}Point;

typedef struct Node{
    Point p;
    struct Node *next;
}NODE;

typedef struct {
    NODE *head;
    NODE *rear;
}Queue;

int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void PushQueue(Queue *queue, Point p) {
    NODE *tmp = malloc(sizeof(NODE));
    (tmp->p).x = p.x;
    (tmp->p).y = p.y;
    if (queue->head == NULL) {
        queue->head = queue->rear = tmp;
    } else {
        queue->rear->next = tmp;
        queue->rear = queue->rear->next;
    }
    return;
}

void PopQueue(Queue *queue) {
    if (queue->head == NULL) {
        return;
    }
    NODE *tmp = queue->head;
    if (queue->head == queue->rear) {
        queue->head = queue->rear = NULL;
    }else {
        queue->head = queue->head->next;
    }
    free(tmp);
    return;
}

bool hasPath(int** maze, int mazeSize, int* mazeColSize, int* start, int startSize, int* destination, int destinationSize){
    Point star;
    Point end;
    int row = mazeSize;
    int col = mazeColSize[0];
    star.x = start[0];
    star.y = start[1];
    end.x = destination[0];
    end.y = destination[1];
    
    Queue queue;
    queue.head = queue.rear = NULL;
    int flag[mazeSize][mazeColSize[0]];
    memset(flag, 0, sizeof(int) * mazeSize * mazeColSize[0]);
    
    PushQueue(&queue, star);
    flag[star.x][star.y] = 1;
    
    while (queue.head != NULL) {
        Point curP;
        curP.x = (queue.head->p).x;
        curP.y = (queue.head->p).y;
        
        PopQueue(&queue);
        
        for (int i = 0; i < 4;i++) {
            Point tmp;
            
            tmp.x = curP.x + dire[i][0];
            tmp.y = curP.y + dire[i][1];
            while ((tmp.x >=0 && tmp.x < row) && 
                   (tmp.y >=0 && tmp.y < col) && 
                   (maze[tmp.x][tmp.y] == 0)) {
               tmp.x += dire[i][0];
               tmp.y += dire[i][1]; 
            }
            
            tmp.x -= dire[i][0];
            tmp.y -= dire[i][1];
            
            if (tmp.x == end.x && tmp.y == end.y) {
                return true;
            }
            
            if ((tmp.x >=0 && tmp.x < row) && 
                (tmp.y >=0 && tmp.y < col) && 
                (flag[tmp.x][tmp.y] != 1) && 
                (maze[tmp.x][tmp.y] == 0)) {
                
                PushQueue(&queue, tmp);
                flag[tmp.x][tmp.y] = 1;
            }
        }
    }
    return false;
}
```
