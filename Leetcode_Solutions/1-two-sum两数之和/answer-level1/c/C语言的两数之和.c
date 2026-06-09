#include <stdio.h>
#include <malloc.h>
int *twoSum(int *nums,int numsSize,int target)
{
	int * res=(int *)malloc(sizeof(int)*2);
	int i,j;
	for(i=0;i<numsSize-1;i++)
	{
		for(j=i+1;j<numsSize;i++)
		{
			if(nums[i]+nums[j]==target)
			{
			res[0]=i;
			res[1]=j;
			return res; 
		}
	}
}
return NULL;
}
int main()
{
	int numsSize=10;
	int *nums=(int*)malloc(sizeof(int)*numsSize);
	int i,j;
	for(i=0;i<numsSize;i++)
	{
		scanf("%d",&nums[i]);
	}
	int target;
	printf("input a target:");
	scanf("%d",target);
	int *res=twoSum(nums,numsSize,target);
	if(res!=NULL)
	printf("%d %d",res[0],res[1]);
	else
	printf("error");
}
