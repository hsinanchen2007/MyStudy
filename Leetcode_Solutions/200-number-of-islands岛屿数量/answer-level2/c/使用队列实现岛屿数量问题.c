

使用循环队列实现岛屿数量问题：
1、找到陆地，将坐标入队。与此陆地相连的陆地，属于同一块岛屿。
2、将队首陆地的上下左右的陆地坐标入队，队首陆地出队。为了防止重复入队，已经入过队的改为2.
3、直到队列为空，说明遍历完了一块岛屿。
4、继续查找下一块未发现的陆地，重复上面的步骤，直到遍历完所有陆地。
5、队列为空时，每找到一块陆地，就代表又发现了一个岛屿。


/*实现循环队列基本功能，作为lib用:
1、创建队列
2、入队
3、出队
4、判断队列是否为空
5、判断队列是否已满（不能满，队列设计的要足够大）
6、销毁队列
*/
```
typedef struct tagPos
{
    int i;
    int j;
}POS;

typedef struct tagFIFO
{
    int head;
    int tail;
    int len;
    POS *data;;
}FIFO;



FIFO * init_fifo(int len)
{
    POS * data = NULL;
    FIFO *fifo = NULL; 
    data = malloc(len * sizeof(POS));
    if (data == NULL){
        return NULL;
    }
    
    fifo = malloc(sizeof(FIFO));
    if (fifo == NULL) {
        free(data);
        return NULL;
    }
    
    data->i = -1;
    data->j = -1;
    fifo->data = data;
    fifo->head = -1;
    fifo->tail = -1;
    fifo->len = len;
    printf("fifo len: %u\n", len);

    return fifo;
}

void free_fifo(FIFO *fifo)
{
    if (fifo == NULL){
        return;
    }
    if (fifo->data != NULL)
    {
        free(fifo->data);
        fifo->data = NULL;
    }
    free (fifo);
    fifo = NULL;
    
    return;
}

bool fifo_isfull(FIFO * fifo)
{
    if (fifo->tail == -1 || fifo->head == -1){
        return false;
    }
    return (fifo->tail + 1) % fifo->len == fifo->head; 
}
    
bool fifo_isempty(FIFO *fifo)
{
    return fifo->head == -1;
}

bool fifo_enqueue(FIFO *fifo, POS *pos)
{
    if(fifo_isfull(fifo)){
        return false;
    }
    
    if (fifo_isempty(fifo)){
        fifo->head = 0;
        fifo->tail = 0;
        fifo->data[0].i = pos->i;
        fifo->data[0].j = pos->j;
        return true;
    }
    
    fifo->tail = (fifo->tail + 1) % fifo->len;
    fifo->data[fifo->tail].i = pos->i;
    fifo->data[fifo->tail].j = pos->j;
    
    return true;
}

bool fifo_dequeue(FIFO *fifo)
{
    if (fifo_isempty(fifo)){
        return true;
    }
    
    fifo->data[fifo->head].i=-1;
    fifo->data[fifo->head].j=-1;
    
    if (fifo->head == fifo->tail){
        fifo->head = -1;
        fifo->tail = -1;
        return true;
    }
    
    fifo->head = (fifo->head + 1) % fifo->len;
    return true;
}


int numIslands(char** grid, int gridSize, int* gridColSize){
    int i = 0;
    int j = 0;
    FIFO *fifo = NULL;
    int num = 0;
    int fi = 0;
    POS pos = {0};
    int pi = 0;
    int pj = 0;

    if (grid == NULL || gridSize == 0 || gridColSize == NULL){
        //printf("input null\n");
        return 0;
    }
    //printf("size=%d colsize = %d \n", gridSize, *gridColSize);
    fifo = init_fifo(gridSize*(*gridColSize));
    if (fifo == NULL){
        //printf("init failed\n");
        return 0;
    }
    for (i = 0; i < gridSize; i++)
    {
        for(j = 0; j < *gridColSize; j++)
        {
            //printf("grid[%u][%u] = %c\n", i, j, grid[i][j]);
            if(grid[i][j] == '1'){
                //printf("enqueue\n");
                pos.i = i;
                pos.j = j;
                fifo_enqueue(fifo, &pos);
                grid[pos.i][pos.j] = '2';
                num++;
                /*陆地相连形成岛屿*/
                for (fi = fifo->head; ; fi++)
                {
                    if (fi == fifo->len){
                        fi = 0;
                    }
                    
                    pi = fifo->data[fi].i;
                    pj = fifo->data[fi].j;
                    //printf("judge grid[%u][%u] down: ", pi, pj);
                    if (pi + 1 < gridSize && grid[pi+1][pj] == '1'){
                        pos.i = pi+1;
                        pos.j = pj;
                        //printf("grid[%u][%u]-%c enqueue, ", pos.i,pos.j, grid[pos.i][pos.j]);
                        fifo_enqueue(fifo, &pos);
                        grid[pos.i][pos.j] = '2'; 
                    }
                    //printf("judge grid[%u][%u] right: ", pi, pj);
                    if (pj+1 < *gridColSize && grid[pi][pj+1] == '1'){
                        pos.i = pi;
                        pos.j = pj+1;
                        //printf("grid[%u][%u]-%c enqueue, ", pos.i,pos.j, grid[pos.i][pos.j]);
                        fifo_enqueue(fifo, &pos);
                        grid[pos.i][pos.j] = '2';
                    }
                    //printf("judge grid[%u][%u] left: ", pi, pj);
                    if (pj -1 >= 0 && grid[pi][pj-1] == '1'){
                        pos.i = pi;
                        pos.j = pj-1;
                        //printf("grid[%u][%u]-%c enqueue, ", pos.i,pos.j, grid[pos.i][pos.j]);
                        fifo_enqueue (fifo, &pos);
                        grid[pos.i][pos.j] = '2';
                    }
                    
                    //printf("judge grid[%u][%u] up: ", pi, pj);
                    if (pi -1 >= 0 && grid[pi - 1][pj] == '1'){
                        pos.i = pi - 1;
                        pos.j = pj;
                        //printf("grid[%u][%u]-%c enqueue, ", pos.i,pos.j, grid[pos.i][pos.j]);
                        fifo_enqueue (fifo, &pos);
                        grid[pos.i][pos.j] = '2';
                    }
                    fifo_dequeue(fifo);
                    //printf("dequeue, ");
                    if (fifo_isempty(fifo) == true){
                        //printf("fifi empty \n");
                        break;
                    }
                }
                
            }
        }
    }
    
    free_fifo(fifo);
    
    return num;
}

```