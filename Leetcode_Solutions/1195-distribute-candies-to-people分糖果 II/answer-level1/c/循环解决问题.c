### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *res = (int*)calloc(1 , sizeof(int)*num_people);
    *returnSize = num_people;
    for(int i = 1; candies>0 ; i++){
        if(candies-i>=0){
            res[(i-1)%num_people] += i;
            candies -= i;
        }
        else{
            res[(i-1)%num_people] += candies;
            candies = 0;
        }
    }
    return res;
}
```