### 解题思路
先对信封数组进行排序，使其递增有序
再套用 最长递增子序列（LIS）(非连续) 的动态规划思想
即可

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
int maxEnvelopes(int** list, int row, int* col){
 	int *dp = (int *)malloc(row*sizeof(int));
    if(row<=1) return row;
 	for (int i = 0; i < row; ++i)
 	{
 		dp[i] = 1;//初始化
 	}   
 	int tmax =1;
 	node bf[10000];
 	for (int i = 0; i < row; ++i)
 	{
 		bf[i].w = list[i][0];
 		bf[i].h = list[i][1];
 	}
 	qsort(bf,row,sizeof(node),inc);

 	// for (int i = 0; i < row; ++i)
 	// {
 	// 	printf("(%d,%d)\n",bf[i].w,bf[i].h);
 	// }

 	for(int i=1;i<row;i++){
 		for (int j = 0; j < i; ++j)
 		{
			if (bf[j].w < bf[i].w && bf[j].h < bf[i].h){
				dp[i] = MAX(dp[i],dp[j]+1);
			}
			tmax = MAX(tmax,dp[i]);
 		}
 	}

 	return tmax;
}
```