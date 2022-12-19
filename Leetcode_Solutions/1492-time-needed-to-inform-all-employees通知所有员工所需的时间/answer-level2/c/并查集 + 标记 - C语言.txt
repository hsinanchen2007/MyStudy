/*题目转意过来 就是找到最长的路径
我们目的是找到叶子到根的最长路径 
遍历整个表，使用并查集思想，可能遍历是从中间开始的，使用color进行标记*/

```
void Find(int x, int* manager, int* informTime, int *num,int *color) {
    while(manager[x] != -1) {
        color[x] = 1;//标记该点已经访问
        *num += informTime[x];
        x = manager[x];
    }
    *num += informTime[x];
    return;
}

int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize){
    int g_time = 0;
    int *color = malloc(sizeof(int) * n);
    memset(color,0,sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        //如果被访问，不需要搜索，肯定是中间开始的节点，不需要访问；
        if(color[i] == 1) {
            continue;
        }
        int num = 0;
        Find(i, manager, informTime,&num,color);
        if (num > g_time ) {
            g_time = num;
        }
    }
    free(color);
    return g_time;
}
```
