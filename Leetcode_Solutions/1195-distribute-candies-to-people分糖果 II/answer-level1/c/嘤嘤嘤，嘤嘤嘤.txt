### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize=num_people;
    int *array = (int *)malloc(num_people*sizeof(int));
    int num=1,left=candies;
    for(int i=0;i<num_people;i++)
        array[i]=0;
    //printf("nnn");
    for(num=1;;num++){
        if(left>=num){
            array[(num-1)%num_people]+=num;
            left-=num;
        }
        else{
            array[(num-1)%num_people]+=left;
            return array;
        }
    }
    return NULL;
}
```