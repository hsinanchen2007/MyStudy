```cpp
void dfs(int first,int *path,int depth,int *result,int *price,int priceSize,int **special,int specialSize,int *needs)
{
    //mark
    for(int i=first;i<specialSize;i++)
    {
        //mark,path
        path[depth]=i;
        depth++;
        
        //result
        int sum[priceSize];
        memset(sum,0,sizeof(sum));
        int cost=0;
        for(int i=0;i<depth;i++)
        {
            for(int j=0;j<priceSize;j++)
            {
                sum[j]=sum[j]+special[path[i]][j];
            }
            cost=cost+special[path[i]][priceSize];
        }
        int flag=1;
        int flag1=1;
        for(int i=0;i<priceSize;i++)
        {
                  printf(" %d ",sum[i]);
            if(sum[i]!=needs[i]) flag=0;
            if(sum[i]>needs[i]) flag1=0;
        }
        printf(" cost:%d ",cost);
        if(flag==1&&cost<(*result)) *result=cost;
        printf(" %d %d  \n",flag,flag1);
        
        //dfs
        if(flag1==1&&cost<(*result)) dfs(i,path,depth,result,price,priceSize,special,specialSize,needs);
        depth--; 
    }
    //对于一层兄弟节点，除了上边的结点，还有全散卖这个节点,即[first，specialSize),specialSize-first再+1种情况。
    //mark
    
    int sum[priceSize];
    memset(sum,0,sizeof(sum));
    int cost=0;
    for(int i=0;i<depth;i++)
    {
        for(int j=0;j<priceSize;j++)
        {
            sum[j]=sum[j]+special[path[i]][j];
        }
        cost=cost+special[path[i]][priceSize];
    }

    for(int i=0;i<priceSize;i++)
    {
        cost=cost+(price[i])*(needs[i]-sum[i]);
    }
   
    printf(" cost:%d \n",cost);
    if(cost<(*result)) *result=cost;
 
        
}
int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize){
    int *path=(int *)malloc(sizeof(int)*17000);
    int result=INT_MAX;
    dfs(0,path,0,&result,price,priceSize,special,specialSize,needs);
    return result;
}
```
1,此题mark为可重复挑选元素，即包括first在内的以后的元素。并且多了一种情况，全部散装,多一个结点。每一层兄弟结点要加上这种情况，即first往后个数，再+1.