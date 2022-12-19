### 解题思路
冒泡排序的每一趟都能选出一个最大或者最小的数，循环k趟即可 O(K*N)
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize=k;
    int* result=(int*)malloc(sizeof(int)*k);

    for(int i=0;i<k;++i)
    {
        for(int j=0;j<arrSize-i-1;++j)
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        result[i]=arr[arrSize-1-i];
    }

    return result;
}
```