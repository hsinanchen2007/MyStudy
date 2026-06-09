求问各位大佬，我的代码为啥超出内存限制了？太长了评论写不下。。

```
int inc(const void * a,const void *b)
{
     return *(int *)a- *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **res=(int**)malloc(sizeof(int*));
    (*returnColumnSizes)=(int*)calloc(1,sizeof(int));
    int pstart=0,pleft=1,pright=numsSize-1;
    int temp=0;
    (*returnSize)=0;
    if(numsSize<3)
    {
        return res;
    }
    qsort(nums,numsSize,sizeof(int),inc);
    for(pstart=0;(nums[pstart]<=0)&&(pstart<numsSize-2);pstart++)
    {
        pleft=pstart+1;
        pright=numsSize-1;
        if(pstart>0&&nums[pstart]==nums[pstart-1])
        {
            continue;
        }
        while(pleft<pright)
        {
            temp=nums[pstart]+nums[pleft]+nums[pright];
            if(temp==0)
            {
                res=(int**)realloc(res,((*returnSize)+1)*sizeof(int*));
                res[*returnSize] = (int *)calloc(3,sizeof(int));
                res[*returnSize][0]=*(nums+pstart);
                res[*returnSize][1]=*(nums+pleft);
                res[*returnSize][2]=*(nums+pright);
                (*returnColumnSizes)=(int *)realloc((*returnColumnSizes),((*returnSize)+1)*sizeof(int));
                (*returnColumnSizes)[*returnSize]=3;
                (*returnSize)++;
                while(pleft<pright&&nums[++pleft]==nums[pleft-1]);
                continue;
            }
            if(nums[pleft]==nums[pright])
            {
                break;
            }
            if(temp<0)
            {
                while(pleft<pright&&nums[++pleft]==nums[pleft-1]);
            }
            else 
            {
                while(pleft<pright&&nums[--pright]==nums[pright+1]);
            }
        }
    }
    return res;
}
```
