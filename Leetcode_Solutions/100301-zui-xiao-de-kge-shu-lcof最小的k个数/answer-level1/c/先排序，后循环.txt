### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
} 
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
*returnSize=k;
int*list=(int*)malloc(sizeof(int)*arrSize);
if(arrSize==0)
return NULL;
qsort(arr,arrSize,sizeof(arr[0]),compare);
int i;
for(i=0;i<k;i++)
list[i]=arr[i];
return list;
}
```