### 解题思路
c和其他不同的地方，就是题目给的函数参数一定要写！*returnSize=num_people;
之前没注意一直报错

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){

    int *ans=(int*)malloc(sizeof(int)*num_people);
    int i,k,j;
    for(i=0;i<num_people;i++)
    ans[i]=0;
    i=0;
    while(candies>0){
        
        if(candies<(i+1))  k=candies;
            else   k=i+1;
        ans[i%num_people]=ans[i%num_people]+k;
        if(candies<(i+1))   j=candies;
            else   j=i+1;
        candies=candies-j;
        ++i;
    }
 
  *returnSize=num_people;
return ans;
}
```