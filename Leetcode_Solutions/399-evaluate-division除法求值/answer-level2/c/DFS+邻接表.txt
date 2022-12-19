弄了一个下午才弄出来,我太菜了
先构建一个无向图的邻接表,然后就可以dfs了,开始想直接用key来判断某条边是否访问,后来发现因为要多次dfs,这样每次dfs都要更新key,比较麻烦,因此用一个visit数组配合每条边的key不一样的特点来判断,这样只需要每次更新visit数组就行了
```
struct arcnode{
    int index;//字符串对应的顶点下标
    double ans;//结果
    struct arcnode*next;
    int key;//和visit数组一起用于判断是否访问过这个顶点
};//边
struct vernode{
    char*str;
    struct arcnode*first;
}node[1000];//顶点

bool dfs(int x1,int x2,struct vernode*node,double*res,int i,int*visit){
    if(x1==x2)return true;
        struct arcnode*p=node[x1].first->next;
    if(visit[p->key]==1)return false;
    while(p){
        visit[p->key]=1;
        res[i]*=p->ans;
        if(dfs(p->index,x2,node,res,i,visit))return true;
        res[i]/=p->ans;
        visit[p->key]=0;
        p=p->next;
    }
    return false;
}

double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    double*res=(double*)malloc(queriesSize*sizeof(double));
    memset(res,-1,sizeof(double)*queriesSize);
    *returnSize=queriesSize;
    if(equationsSize==0)return res;
    int top=0;
    for(int i=0;i<queriesSize;i++)
        res[i]=1;
    int rear=0;
    for(int i=0;i<equationsSize;i++){
        int ver=-1,arc=-1;
        for(int j=0;j<top;j++){
            if(strcmp(equations[i][0],node[j].str)==0)
                ver=j;
            if(strcmp(equations[i][1],node[j].str)==0)
                arc=j;
        }
        if(ver==-1){//等于-1说明当前数组还没有这个顶点,直接新建
            node[top].str=(char*)malloc(sizeof(char)*4);
            node[top].str=equations[i][0];
            node[top].first=(struct arcnode*)malloc(sizeof(struct arcnode));
            node[top].first->next=NULL;
            ver=top;
            top++;
        }
        if(arc==-1){
            node[top].str=(char*)malloc(sizeof(char)*4);
            node[top].str=equations[i][1];
            node[top].first=(struct arcnode*)malloc(sizeof(struct arcnode));
            node[top].first->next=NULL;
            arc=top;
            top++;
        }
        
        struct arcnode*p=(struct arcnode*)malloc(sizeof(struct arcnode));//向两个顶点插入边
        p->index=arc;
        p->ans=values[i];
        p->next=node[ver].first->next;
        node[ver].first->next=p;
        p->key=rear++;
        struct arcnode*s=(struct arcnode*)malloc(sizeof(struct arcnode));
        s->index=ver;
        double a=1;
        s->ans=a/values[i];
        s->next=node[arc].first->next;
        node[arc].first->next=s;
        s->key=rear++;//每条边的key值是唯一的,以便判断是否重复访问过
    }//构建邻接表
    
    int*visit=(int*)calloc(rear,sizeof(int*));//用于判断是否访问过某条边
    for(int i=0;i<queriesSize;i++){
        int x1=-1,x2=-1;
        for(int j=0;j<top;j++){//找两个字符串对应的下标
            if(strcmp(queries[i][0],node[j].str)==0)
                x1=j;
            if(strcmp(queries[i][1],node[j].str)==0)
                x2=j;
            if(x1!=-1&&x2!=-1)
                break;//优化一下
        }
        if(x1==-1||x2==-1){
            res[i]=-1;
            continue;
        }
        else if(x1==x2){
            res[i]=1;
            continue;
        }
        else{
           if(!dfs(x1,x2,node,res,i,visit))
               res[i]=-1;
           memset(visit,0,rear*sizeof(int));//每结束一次重新将数组元素置为0
        }
    }
    return res;
}
```
