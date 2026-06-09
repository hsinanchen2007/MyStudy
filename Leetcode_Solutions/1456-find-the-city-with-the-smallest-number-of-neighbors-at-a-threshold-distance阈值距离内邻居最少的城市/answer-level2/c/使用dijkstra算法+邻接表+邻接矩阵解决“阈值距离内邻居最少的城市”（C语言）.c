### 解题思路
经典的无向图最短距离问题，使用dijkstra算法解决，并使用邻接表和邻接矩阵加速。

1.使用邻接表记录链接关系

2.初始化邻接矩阵，用于记录两城市间最短距离。本城间距离为0，未获得距离为-1

3.遍历各个城市，使用dijkstra算法获取城市间最小距离。注意dijkstra算法的C实现。

4.利用邻接矩阵初始化队列，可以利用已经计算出的结果

PS：
dijkastra算法的C实现：

(1)选择起点节点

(2)将起点放入队列，队列记录当前节点，以及起点到当前节点的最小距离

(3)遍历队列，找到队列中节点到所有未访问节点距离的最小值以及对应的节点

(4)将该节点加入队列，记录该最小值

(5)循环往复，直到从队列节点中没有找到未访问节点。

### 代码

```c
#define NODE_NUM    100
#define MMAX(a, b)  ((a) > (b)? (a) : (b))
#define MMIN(a, b)  ((a) < (b)? (a) : (b))

typedef struct _adj_tab_st
{
    int ids[NODE_NUM];
    int ws[NODE_NUM];
    int cnt;
}adj_tab_st;

int adj_mat[NODE_NUM][NODE_NUM];

typedef struct _info_st
{
    int base;   // 记录当前点到起点的最小路径
    int id;     // 记录当前点的id
}info_st;

//【算法思路】Dijkstra+邻接表+邻接矩阵。使用邻接表组织链接关系，使用邻接矩阵记录两点间的最短距离，使用dijkstra算法计算一点到其余个点间的最短距离。
int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold){
    // 将信息组织成邻接表，用于访问加速
    adj_tab_st *tab = (adj_tab_st *)calloc(n, sizeof(adj_tab_st));

    for(int i = 0; i < edgesSize; i++)
    {
        int n0 = edges[i][0];
        int n1 = edges[i][1];
        int w = edges[i][2];

        tab[n0].ids[ tab[n0].cnt ] = n1;
        tab[n0].ws[ tab[n0].cnt ] = w;
        tab[n0].cnt++;

        tab[n1].ids[ tab[n1].cnt ] = n0;
        tab[n1].ws[ tab[n1].cnt ] = w;
        tab[n1].cnt++;
    }
/*
    printf("adj_tab:\n");
    for(int i = 0; i < n; i++)
    {
        printf("< %d >:   ", i);
        for(int j = 0; j < tab[i].cnt; j++)
        {
            printf("[%d, %d]  ", tab[i].ids[j], tab[i].ws[j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    // 将两点间最短距离记录于邻接矩阵，用于计算加速
    // 注意：自身的距离初始化为0，未计算出的为-1
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                adj_mat[i][j] = -1;
            }
        }
    }

    // 遍历各个点，使用dijkstra算法，获得到其余各点的最短距离，注意使用邻接矩阵加速
    for(int id = 0; id < n; id++)
    {
        // 用于记录以获得最短距离信息的队列
        info_st *que = (info_st *)calloc(n, sizeof(info_st));
        int qsize = 0;

        // 用于记录是否已经访问过的路标
        int *flags = (int*)calloc(n, sizeof(int));

        // 向队列中添加自身和邻接矩阵中已经求得的最小距离,加速求解过程
        for(int i = 0; i < n; i++)
        {
            if(adj_mat[id][i] != -1)
            {
                que[qsize].base = adj_mat[id][i];
                que[qsize].id = i;
                qsize++;

                flags[i] = 1;
            }
        }
/*
        for(int i = 0; i < qsize; i++)
        {
            printf("%d[base %d, id %d]   ", i, que[i].base, que[i].id);
        }
        printf("\n");
*/
        // 遍历其余节点，遍历停止的条件是：“无法找到新的最短距离节点”
        bool find;

        do
        {
            find = false;

            int min = INT_MAX;
            int mid = -1;
            for(int i = 0; i < qsize; i++)
            {
                int cid = que[i].id;
                int base = que[i].base;

                //寻找当前节点连接的未访问节点最小距离
                for(int j = 0; j < tab[cid].cnt; j++)
                {
                    int tid = tab[cid].ids[j];
                    int w = tab[cid].ws[j];

                    if(flags[tid] == 0)
                    {
                        if(base + w < min)
                        {
                            min = base + w;
                            mid = tid;

                            find = true;
                        }
                    }
                }
            }

            // 如果找到最小值节点，将其更新入队列中，以及邻接矩阵中
            if(find == true)
            {
                que[qsize].base = min;
                que[qsize].id = mid;

                flags[mid] = 1;
                qsize++;

                adj_mat[id][mid] = min;
                adj_mat[mid][id] = min;
            }
/*
            for(int i = 0; i < qsize; i++)
            {
                printf("%d[base %d, id %d]   ", i, que[i].base, que[i].id);
            }
            printf("\n");
*/
        } while (find == true);
    }
/*
    printf("adj_mat:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d  ", adj_mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    int min = INT_MAX;
    int mid = -1;
    // 遍历邻接矩阵，获得满足条件的结果
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;

        for(int j = 0; j < n; j++)
        {
            if(adj_mat[i][j] > 0 && adj_mat[i][j] <= distanceThreshold)
            {
                cnt++;
            }
        }

        if(cnt <= min)
        {
            min = cnt;
            mid = i;
        }
    }

    return mid;
}
```