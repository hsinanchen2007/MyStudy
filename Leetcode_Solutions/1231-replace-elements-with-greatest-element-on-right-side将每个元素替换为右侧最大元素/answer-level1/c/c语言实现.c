### 解题思路
类似于选择排序但又不相同。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int *num=(int*)malloc(sizeof(int)*arrSize);
    for(int i=1;i<arrSize;i++)
    {
        int temp=arr[i];
        for(int j=i;j<arrSize;j++)
        {
            if(arr[j]>temp)
            {
                temp=arr[j];
            }
        }
        num[i-1]=temp;
    }
    num[arrSize-1]=-1;
    *returnSize=arrSize;
    return num;
}
```