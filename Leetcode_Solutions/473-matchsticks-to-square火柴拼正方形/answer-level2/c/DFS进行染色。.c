### 解题思路
连续写了4次dfs，每次染色一下，我写得好烂呀。

### 代码

```c
int g_valid = 0;




int  dfs(int* nums, int numsSize, int n, int step, int *visit,int  *result, int tk) {

    int ret = 0;
	if(*result == n)
	{
		g_valid += tk;
		return 1;
	}
	else if(*result > n){
		return 0;
	}
	for(int i = 0; i < numsSize; i++) {

		if(!visit[i])
		{
			visit[i] = 1;
			*result += nums[i];		
			ret = dfs(nums,numsSize,n,step+1,visit,result,tk);
			if(ret == 0) //未找到，回退一步，找到一个，则visit不用清了。
			{
				*result -= nums[i];		
				visit[i] = 0;
			}
			else if(ret == 1)
			{
				return 1;
			}
		}

	}

  return 0;
}




int comparearry(const void *a, const void * b)
{
    int *aa = (int *)a;
    int *bb = (int *)b;
    return *bb - *aa;
}


bool makesquare(int* nums, int numsSize){

if(numsSize == 0 || nums==0)
{
    return 0;
}
g_valid = 0;
int total = 0;

int result = {0};

for(int i = 0; i < numsSize;i++) {
   total +=nums[i];	
}

int n = total % 4;
if(n != 0)
{
	return false;
}
n = total /4;

int visit[numsSize];
for(int i = 0; i < numsSize; i++)
{
	visit[i] = 0;
}
qsort(nums,numsSize,sizeof(int),comparearry);


dfs(nums, numsSize, n,0,visit,&result,1);
result = 0;
dfs(nums, numsSize, n,0,visit,&result,1);
result = 0;

dfs(nums, numsSize, n,0,visit,&result,1);
result = 0;

dfs(nums, numsSize, n,0,visit,&result,1);

result = 0;

if(g_valid == 4)
	return true;
return false;

}

```