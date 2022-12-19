```
#define QUEUE_SIZE  (4096*4096)
typedef struct xy
{
    int x;
    int y;
}s_xy;

s_xy g_queue[QUEUE_SIZE];
int start = 0;
int end = 0;
void queue_init()
{
    start = 0;
    end = 0;
    memset(g_queue,0,sizeof(g_queue));
    return;
}
bool queue_is_empty()
{
    if(start == end)
    return true;

    return false;
}
bool queue_is_full()
{
    if(start == (end +1) % QUEUE_SIZE)
    return true;

    return false;
}
void queue_push(s_xy item)
{
    if(queue_is_full())
    {
        printf("queue is full\r\n");
        return;
    }
    g_queue[end] = item;
    end = (end + 1) % QUEUE_SIZE;
}
s_xy queue_pop()
{
    int tmp = 0;

    if(queue_is_empty())
    {
        printf("quenue is empty\r\n");
    }
    tmp = start;
    start= (start + 1) % QUEUE_SIZE;
    return g_queue[tmp];
}
int queue_size()
{
    if(end >= start)
    {
        return end - start;
    }

    return end - start + QUEUE_SIZE;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int tmp = 0;
    int max = 0;
    int **flg = NULL;

    flg = malloc(sizeof(int*)*(gridSize));
    for(int i = 0; i < gridSize; i++)
    {
        flg[i] = malloc(sizeof(int)*(*gridColSize));
        memset(flg[i], 0, sizeof(int)*(*gridColSize));
    }
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < *gridColSize; j++)
        {
             if(grid[i][j] == 1 && flg[i][j] == 0)
             {
                 s_xy item;
                 tmp = 0;
                 item.x = i;
                 item.y = j;
                 flg[item.x][item.y] = 1;
                 queue_push(item);
                 while(false == queue_is_empty())
                 {
                     int que_size = queue_size();
                     s_xy tmp_item;
                     s_xy tmp_item1;
                     //printf("size = %d.\r\n", que_size);
                     for(int k = 0; k < que_size; k++)
                     {
                         tmp_item = queue_pop();
                         tmp++;
                         if(tmp_item.x - 1 > -1)
                         {
                             if(grid[tmp_item.x - 1][tmp_item.y] == 1 && flg[tmp_item.x - 1][tmp_item.y] == 0)
                             {
                                 tmp_item1.x = tmp_item.x - 1;
                                 tmp_item1.y = tmp_item.y;
                                 flg[tmp_item1.x][tmp_item1.y] = 1;
                                 queue_push(tmp_item1);
                                 //printf("x = %d, y = %d\r\n", tmp_item1.x, tmp_item1.y);
                             }
                         }
                         if(tmp_item.x + 1 < gridSize)
                         {
                             if(grid[tmp_item.x + 1][tmp_item.y] == 1 && flg[tmp_item.x + 1][tmp_item.y] == 0)
                             {
                                 tmp_item1.x = tmp_item.x + 1;
                                 tmp_item1.y = tmp_item.y;
                                 flg[tmp_item1.x][tmp_item1.y] = 1;
                                 queue_push(tmp_item1);
                                  //printf("x = %d, y = %d\r\n", tmp_item1.x, tmp_item1.y);
                             }
                         }
                         if(tmp_item.y - 1 > -1)
                         {
                             if(grid[tmp_item.x ][tmp_item.y - 1] == 1 && flg[tmp_item.x][tmp_item.y - 1] == 0)
                             {
                                 tmp_item1.x = tmp_item.x;
                                 tmp_item1.y = tmp_item.y - 1;
                                 flg[tmp_item1.x][tmp_item1.y] = 1;
                                 queue_push(tmp_item1);
                                 // printf("x = %d, y = %d\r\n", tmp_item1.x, tmp_item1.y);
                             }
                         }
                         if(tmp_item.y + 1 < *gridColSize)
                         {
                             if(grid[tmp_item.x ][tmp_item.y + 1] == 1 && flg[tmp_item.x][tmp_item.y + 1] == 0)
                             {
                                 tmp_item1.x = tmp_item.x ;
                                 tmp_item1.y = tmp_item.y + 1;
                                 flg[tmp_item1.x ][tmp_item1.y] = 1;
                                 queue_push(tmp_item1);
                                 // printf("x = %d, y = %d\r\n", tmp_item1.x, tmp_item1.y);
                             }
                         }

                     }
                 }
                  //printf("-----tmp %d\r\n",tmp);
                 if(max < tmp)
                 {
                     max = tmp;
                 }

             }
        }
    }

    return max;
}
```
