### 解题思路
搜k遍每遍找最小的

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *a=(int *)malloc(sizeof(int )*k);
    for(int i=0;i<k;i++)
    {
        int min=10001,jilu;
        for(int j=0;j<arrSize;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                jilu=j;
            }
        }
        a[i]=min;
        arr[jilu]=10000;
        printf("%d\n",a[i]);
    }
    *returnSize=k;
    return a;
}
```