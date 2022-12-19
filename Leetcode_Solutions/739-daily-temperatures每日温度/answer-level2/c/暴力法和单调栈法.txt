# 代码供参考
**暴力法**
```
#define MAXSIZE 50000
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    
    int *Next=(int *)malloc(sizeof(int)*101);
    memset(Next,MAXSIZE,sizeof(int)*101);
    
    int *ans=(int *)malloc(sizeof(int)*TSize);
    int index;
    int i,j;
    for(i=TSize-1;i>=0;i--)
    {
        index=MAXSIZE;
        for(j=T[i]+1;j<=100;j++)
        {
            if(Next[j]<index)
                index=Next[j];
        }
        if(index<MAXSIZE)
        {
            ans[i]=index-i;
        }
        else
        {
            ans[i]=0;
        }
        Next[T[i]]=i;
    }
    * returnSize=TSize;
    return ans;
}
```
**单调栈**
```
#define MAXSIZE 50000
int* dailyTemperatures(int* T, int TSize, int* returnSize){    
    
    int *stack=(int *)malloc(sizeof(int)*MAXSIZE);
    memset(stack,0,sizeof(int)*MAXSIZE);
    
    int *ans=(int *)malloc(sizeof(int)*TSize);
    int top=0,i;
    for(i=TSize-1;i>=0;i--)
    {
        while(top!=0&&T[i]>=T[stack[top-1]])
                top--;
        stack[top++]=i;
        //int t1=stack[top-1];
        //int t2=stack[top-2];
        if(top==1)
            ans[i]=0;
        else
            ans[i]=stack[top-2]-stack[top-1];
    }
    * returnSize=TSize;
    return ans;
}
```
