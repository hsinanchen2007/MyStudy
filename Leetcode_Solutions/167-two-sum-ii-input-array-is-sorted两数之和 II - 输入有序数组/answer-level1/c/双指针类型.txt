### 解题思路
首尾两端各分配一个指针（双指针），让两个指针指向的数相加，若和为目标值target,则退出，并返回两个数的所在位置，若和大于目标值，则指向末端的指针前移一个单位，若和小于目标值则指向前端的指针后移一个单位，若找不到相对应的两个元素，则返回空指针NULL.

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i=0;
    int j=numbersSize-1;
    int *a=(int *)malloc(sizeof(int)*2);
    while(i<j)
    {
        if((numbers[i]+numbers[j])==target)
        {
            a[0]=i+1;
            a[1]=j+1;
            *returnSize = 2;
            break;
        }
        else if((*(numbers+i)+*(numbers+j)) > target)
        {
            j--;
        }
        else if((*(numbers+i)+*(numbers+j)) < target)
        {
            i++;
        }
    }
    if(i<j)
    {
        
        return a;
    }
    else{
        return NULL;
    }
    
}
```