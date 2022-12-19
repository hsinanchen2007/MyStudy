### 解题思路
将每个人的糖果数当作数组元素的值，通过循环不断对数组元素赋值，赋值前判糖果数量是否够下一次。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize=num_people;
    int *people=(int*)malloc(num_people*sizeof(int));
    for(int i=0;i<num_people;i++)
        people[i]=0;
    int x=candies,sum=0;
    int counts=1;
    for(int i=0;i<=num_people;i++)
    {
        if(i==num_people)
            i=0;
        if(x<=0)
            break;
        x=candies-sum;
        if(x>=counts)
        {
            people[i]=people[i]+counts;
            sum+=counts;
        }   
        else
        {
             people[i]=people[i] + x;
             sum+=x;
        }  
        counts++;
    }
    return people;
}
```