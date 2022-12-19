### 解题思路
还有糖的时候就保持循环
{
根据剩余糖果数量和需要派发数量 给小朋友发糖
下一个小朋友
}

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize=num_people;
    int *result=(int *)malloc(sizeof(int)*num_people);
    for(int i=0;i<num_people;++i)
        result[i]=0;

    int i=0,j=1;
    while(candies>0)
    {
        if(candies>j)
        {
            result[i]+=j;
            candies-=j;
            ++j;
            i=(i+1)%num_people;
        }
        else
        {
            result[i]+=candies;
            candies=0;
        }
    }
    return result;
}
```