### 解题思路
染色

### 代码

```c
//思路：每做次车，对能到达的地方进行染色。这样被染色的点会逐渐扩散。
//方法：1）遍历路线，某条路线发现有可达站点，便将这个路线的其他站点都染色为可达站点。
//     2）一条路线，完成对路线内站点的染色后，该路线便失去再次遍历的意义，下次可以不再遍历，使用roadused记录已经完成使命的路线。

bool flag[1000000]={0};       //置1的站点说明可达
bool flag_update[1000000]={0}; //在某一次遍历中，刚刚被染色的点不能直接放到falg中，防止对本次遍历的其他节点有影响
int  * colsize =0;
#define printf(fmt, args...) ((void)0)    //调试开关
int setroad(int *road,int k)
{   

    int isin=0;

    for(int i=0;i<colsize[k];i++){
        printf("colsize[%d]=%d\n",i,colsize[i]);
        if(flag[road[i]]==1){//判断是否在上一轮已染色
            printf("[%d]is in!\n",road[i]);
            isin=1;break;
        }
    }
    if(isin==0)return 0;
    for(int i=0;i<colsize[k];i++){
        printf("set other %d in road \n",road[i]);
        flag_update[road[i]]=1;//在当前一轮染色
    }
    return 1;
}


int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int S, int T){
    colsize=routesColSize;
    memset(flag,0,sizeof(bool)*1000000);
    memset(flag_update,0,sizeof(bool)*1000000);
    int times=0;
    int ran =0;
    int * roadused=0;
    roadused=calloc(sizeof(int),routesSize);
    flag[S]=1;
    flag_update[S]=1;
    if(flag[T]==1)return times;//刚开始就在目标站点的情况，没考虑到！
    while(1){
        memcpy(flag,flag_update,sizeof(bool)*1000000);//更新flag
        times++;
        printf("start once search times=%d\n",times);
        ran = 0;
        for(int i=0;i<routesSize;i++)
        {   

            if(roadused[i]==1)continue;
            printf("search  road [%d]\n",i);
            if(setroad(routes[i],i)==1){
                ran=1;
                roadused[i]=1;
            }
        }
        if(flag_update[T]==1)return times;
        if(ran==0) return -1;
    }

}
```