### 解题思路
如果是求最大，最小的，最好用BFS，非要用DFS，注意回溯。

### 代码

```c

#define min(a,b) a<b?a:b
int g_minstep = INT_MAX;
int ismatch(char *bank, char *cur)
{
    int cnt = 0;
    while(*bank !='\0'){
        if(*bank != *cur)
        {
           cnt++;    
        }
        bank++;
        cur++;
    }
    if(cnt ==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dfs(char * start, char * end, char ** bank, int bankSize, int step, int *visit)
{
   if(strcmp(start,end) == 0)
   {
       g_minstep = min(step, g_minstep);
       return;
   }
   for(int i = 0; i <bankSize; i++) {
       if(!visit[i]) {
        if(ismatch(bank[i],start))
        {
            visit[i] = 1;
            dfs(bank[i], end, bank, bankSize,step+1,visit);
            visit[i] = 0;
        }
       }
   }
    

}


int minMutation(char * start, char * end, char ** bank, int bankSize){
   if(bankSize == 0)
   {
        return -1;
   }
   int visit[bankSize];
   for(int i = 0; i < bankSize; i++) {
       visit[i] = 0;
   }
   g_minstep = INT_MAX;
   dfs(start, end, bank, bankSize,0, visit);
   if(g_minstep == INT_MAX) {
       return -1;
   }
   return g_minstep;
}
```