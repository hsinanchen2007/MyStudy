### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/679e059f0d192536954f33cd371853ca68255f5d8a8ef9548d8b17733660d82e-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void*a,const void*b){
	return *(int*)a - *(int*)b;
}
int delRepeat(int **res,int *returnSize,int **returnColumnSizes,int a[]){
	for(int i=0,j;i<*returnSize;i++)
	{
		for(j=0;j<(*returnColumnSizes)[i];j++)
		{
			if(res[i][j]!=a[j])
				break;
		}
		if(j==(*returnColumnSizes)[i])
			return 1; //重复了，返回1
	}
	return 0;  //无重复，返回0
} 
void backTrack(int **res,int a[],int id,int start,int* candidates, int candidatesSize, 
    int target, int* returnSize, int** returnColumnSizes){
    if(target==0)
	{
		a[id] = '\0';
		if(delRepeat(res,returnSize,returnColumnSizes,a))
			return;	
		res[*returnSize] = (int*)malloc(sizeof(int)*(id+1));
		for(int k=0;k<id;k++)
			res[*returnSize][k] = a[k];
		(*returnColumnSizes)[*returnSize] = id;
		(*returnSize)++;
		return;
	}
	for(int i=start;i<candidatesSize&&target-candidates[i]>=0;i++)
	{
		 //若重复了，则该值无需进行回溯找解，直接跳过，注意加了id=0！！！
		if(id==0&&i>0&&candidates[i]==candidates[i-1])  
			continue;
		a[id] = candidates[i];
		backTrack(res,a,id+1,i+1,candidates,candidatesSize, 
                  target-a[id],returnSize,returnColumnSizes);
	}
	return;	
}
int** combinationSum2(int* candidates, int candidatesSize, 
    int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(int),cmp);
	int **res = (int**)malloc(sizeof(int*)*500);
	int a[candidatesSize+1]; 
	*returnSize = 0;
	backTrack(res,a,0,0,candidates,candidatesSize, 
              target,returnSize,returnColumnSizes);
	return res;	
}
```