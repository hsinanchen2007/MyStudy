```
    dfs(tickets,ticketsSize,returnSize,newstart,ret,visited);
    if((*returnSize)==ticketsSize)return;//开始没有这三句，
    (*returnSize)--;
    visited[i]=0;
```
问题一：
    开始没有写后面这三句，出错用例如下，在找到“KUL”后直接记录并返回了。分析之后，对这种只进不出的节点，应该通过回退覆盖掉。
    输入：
    [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    输出：
    ["JFK","KUL","NRT","JFK"]
    预期：
    ["JFK","NRT","JFK","KUL"]

问题2： 
    ```
    if((*returnSize)==ticketsSize)return;
    ```
    如果没有这句，在有环时，会覆盖以得出的答案
    出错如下：
    输入
    [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    输出
    ["JFK","SFO","ATL","SFO","ATL","SFO"]
    预期结果
    ["JFK","ATL","JFK","SFO","ATL","SFO"]
    因此要得到结果就返回。

    在写代码时参考了这位兄弟：https://leetcode-cn.com/problems/reconstruct-itinerary/solution/c-dfs-chu-xue-by-helloword-14/

```
int cmp(const void *str1, const void *str2)
{
    const char **p = *(char***)str1;
    const char **q = *(char***)str2;
    int ret = strcmp(p[0], q[0]);
    if (ret == 0) {
        return strcmp(p[1], q[1]);
    }
    return ret;
}

void dfs(char ***tickets, int ticketsSize,int *returnSize,char *start,char **ret,int *visited){
    for(int i=0;i<ticketsSize;i++){
        if(visited[i]==0&&strcmp(tickets[i][0],start)==0){
            ret[*returnSize]=malloc(4);
            memcpy(ret[*returnSize],tickets[i][1],4);
            //printf("%d  %s\n",*returnSize,tickets[i][1]);
            (*returnSize)++;
            visited[i]=1;
            char *newstart=tickets[i][1];
        }
    }
}

char ** findItinerary(char*** tickets, int ticketsSize,int* ticketsColSize,int* returnSize){
    char **ret=malloc(sizeof(char *)*(ticketsSize+1));
    ret[0]=malloc(4);
    memcpy(ret[0],"JFK",4);
    *returnSize=1;
    int *visited=malloc(sizeof(int)*(ticketsSize));
    memset(visited,0,sizeof(int)*(ticketsSize));
    qsort(tickets,ticketsSize,sizeof(tickets[0]),cmp);
    //printf("%s  %s",tickets[0][0],tickets[0][1]);
    dfs(tickets,ticketsSize,returnSize,"JFK",ret,visited);
    *returnSize=ticketsSize+1;
    return ret;
}
```
