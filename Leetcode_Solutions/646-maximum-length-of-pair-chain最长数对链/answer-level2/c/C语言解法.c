### 解题思路
与俄罗斯套娃信封问题的解题思路一样

### 代码

```c
int MAX(int a,int b){return a>b?a:b;}
int MIN(int a,int b){return a>b?a:b;}
typedef struct node {
 	int w,h;
 }node;
 
int inc(const void *a, const void *b)
{
	if ((* (node * )a).w == ( * (node * )b).w)
	{
		return (*(node *)a).h -(*(node *)b).h;
	}else
		return (*(node *)a).w -(*(node *)b).w;

} 


int findLongestChain(int** list, int row, int* col){
    int *dp = (int *)malloc(row*sizeof(int));

 	for (int i = 0; i < row; ++i)
 	{
 		dp[i] = 1;//初始化
 	}   
 	int tmax =1;
 	node bf[1000];
 	for (int i = 0; i < row; ++i)
 	{
 		bf[i].w = list[i][0];
 		bf[i].h = list[i][1];
 	}
 	qsort(bf,row,sizeof(node),inc);
 	for(int i=1;i<row;i++){
 		for (int j = 0; j < i; ++j)
 		{
			if (bf[j].h < bf[i].w){
				dp[i] = MAX(dp[i],dp[j]+1);
			}
			tmax = MAX(tmax,dp[i]);
 		}
 	}

 	return tmax;
}
```