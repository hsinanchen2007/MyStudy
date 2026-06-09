### 解题思路
直接按逻辑写

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int n=0,sum=0;
    *returnSize = num_people;
    int *a=malloc(sizeof(int)*num_people);
    for(int i=0;i<num_people;i++)
    a[i]=0;
while(sum<=candies)
{for(int i=0;i<num_people;i++)
{
    if(candies-sum>=n+(i+1))
    {a[i]+=n+(i+1);
    sum += n+(i+1);}
    else
    {a[i]+=candies-sum;
    return a;}
}
if(sum<candies)
n += num_people;
}
return 0;
}
```