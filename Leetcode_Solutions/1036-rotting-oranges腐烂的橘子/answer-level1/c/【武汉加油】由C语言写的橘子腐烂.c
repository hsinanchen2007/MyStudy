定义了一个结构体，里面用来存放腐烂的橘子以及橘子腐烂的时间
在函数中，首先一次for遍历，找出所有值为2的橘子，存放如结构体中，定初始时间为0
从结构体中拿出一个个初始的坐标值，检测对应的橘子旁边是否有值为1的正常橘子，如果有在结构体中记录坐标，并时间定为原橘子的时间加一
用time获取最新的结构体中time[]信息，并返回

typedef struct Node         //存放腐烂橘子坐标、时间信息
{
    int x[100];
    int y[100];
    int time[100];
}coordinate;

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    coordinate a;
    int N = 0;
    for(int i = 0; i < gridSize; i++)   一次遍历，找出初始状态里所有腐烂的橘子
    {
        for(int j = 0; j < gridColSize[0]; j++)
        {
            if(grid[i][j] == 2) 
            {
                a.x[N] = i;
                a.y[N] = j;
				a.time[N++] = 0;
            }
        }
    }
    int time = 0;
    for(int i = 0 ; i < N; i++) //根据橘子腐烂规则判断腐烂蔓延情况，直至所有的腐烂橘子都被发现
    {
        int xx, yy, b, c;
        b = a.x[i];
        c = a.y[i];
        int x_list[] = {1, -1, 0, 0};   //数组用来找到该点上下左右四个方位的坐标
        int y_list[] = {0, 0, 1, -1};
        for(int j = 0; j < 4; j++)
        {
            xx = b + x_list[j];
            yy = c + y_list[j];
            if(xx < 0 || yy < 0 || xx > (gridSize - 1) || yy > (gridColSize[0]-1)) 
            {
                continue;
            }
            if(grid[xx][yy] == 1)   //如果有新鲜橘子被感染，存放坐标并时间加一
            {
                grid[xx][yy] = 2;
                a.x[N] = xx;
                a.y[N] = yy;
                if(i == 0) {a.time[N] = 1; time = a.time[N++];}
                else  {a.time[N] = a.time[i] + 1; time = a.time[N++];}      //time获取最新腐烂时间
            }
        }
    }
    for(int i = 0; i < gridSize; i++)   //如果始终有橘子未腐烂，返回-1
        for(int j = 0; j < gridColSize[0]; j++)
        {
            if(grid[i][j] == 1) return -1;
        }
    }
    return time;
}