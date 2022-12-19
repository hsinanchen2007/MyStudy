### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
            int *returnA;
            returnA=(int *)malloc(sizeof(int )*(arrSize));
            returnA[arrSize-1]=-1;
            int i=arrSize-2;
            while(i>=0){
                returnA[i]=returnA[i+1]>arr[i+1]?returnA[i+1]:arr[i+1];
            i--;
            }
            *returnSize=arrSize;
            return returnA;
}
```