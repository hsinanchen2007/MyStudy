### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Creat_Hash(int nums[],int len,int* Hash1,int* Hash2);
int Contain(int key,int len,int target,int nums[],int* Hash1,int* Hash2);
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,k,len=numsSize+3;
    int Hash1[len]; int Hash2[len];
	int* ret=(int*)calloc(2,sizeof(int));
	
	for(i=0;i<len;i++){  //Hash初始化 
		Hash1[i]=-1; Hash2[i]=-1;
	}
	
	Creat_Hash(nums,len,Hash1,Hash2);
	
	for(i=0;i<numsSize;i++){//查找 
		int complement=target-nums[i];
		k=Contain(complement,len,target,nums,Hash1,Hash2);
		if((k>-1)&&(k!=i)){
			ret[0]=i; ret[1]=k; *returnSize=2;
			break;
		}
	}

    return ret;
}

void Creat_Hash(int nums[],int len,int* Hash1,int* Hash2)
{
	int i,j;
	for(i=0;i<len-3;i++){
		if(nums[i]>=0){
			j=nums[i]%len;
			while(Hash1[j]!=-1) j=(++j)%len;
			Hash1[j]=i;
		}
		else{
			j=(-nums[i])%len;
			while(Hash2[j]!=-1) j=(++j)%len;
			Hash2[j]=i;
		}
	}
}

int Contain(int key,int len,int target,int nums[],int* Hash1,int* Hash2)
{
	int j,unique=1;
	if((target-key)==key) unique=0;//判断是否有相同元素 
	if(key>=0){
		j=key%len;
		if(unique==0&&nums[Hash1[j]]==key) j=(++j)%len; //存在2个以上相同元素时,排除自身的影响. 
		while((Hash1[j]!=-1)&&nums[Hash1[j]]!=key) j=(++j)%len;
		return Hash1[j];
	}
	else{
		j=(-key)%len;
		if(unique==0&&nums[Hash1[j]]==key) j=(++j)%len;
		while((Hash2[j]!=-1)&&nums[Hash2[j]]!=key) j=(++j)%len;
		return Hash2[j];
	}
}

```