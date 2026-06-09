### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){

    int *out = calloc(num_people,sizeof(int));
    *returnSize = num_people;
    int index  =0;
    int i=1;
    while(candies >=0)
    {
        if(candies-i>= 0)
            out[index] += i;
        else
            out[index] = (int)(out[index]+ candies);
           ;
        candies -=i;
        i++;
        index++;
        if(index==num_people)
            index = 0;
    }
    return out;
}
```