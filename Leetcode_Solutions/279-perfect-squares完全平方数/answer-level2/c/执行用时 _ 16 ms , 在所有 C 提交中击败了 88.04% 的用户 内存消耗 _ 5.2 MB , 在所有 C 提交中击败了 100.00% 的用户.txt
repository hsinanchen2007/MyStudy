### 解题思路
建立题目问题的数学模型，也就是一个加权树状图，相邻节点差一个平方数，以给的n为初始节点，逐层递减，用bfs，当第一次减少到0时，步骤数就是答案

### 代码

```c
int numSquares(int n){
    
    int fount=0,rear=1;int step=0;
int a[10000];int hash[10000]={0};
a[0]=n;
   while(rear>fount)
   {step++;int m=rear-fount;
   for(int j=0;j<m;j++){
       for(int i=1;(a[fount]-i*i)>=0;i++)
       {   if(a[fount]-i*i==0)
           {
               return step;
           }
           if(hash[a[fount]-i*i]==0)
           {a[rear++]=a[fount]-i*i;
            hash[a[fount]-i*i]=1;
           }else
           continue;
       }fount++;}
   }
return -1;
}
```