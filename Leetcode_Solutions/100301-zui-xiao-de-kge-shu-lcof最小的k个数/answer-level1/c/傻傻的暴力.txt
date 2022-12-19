### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(!arr||!arrSize||!k) {
        *returnSize=0;
        return NULL;
    }
    int *returns=(int *)malloc(k*sizeof(int)),* temp;
    temp=returns;
    *returnSize=k;
    int log=0;
    while(k--){
        int min=arr[0];
        for(int i=1;i<arrSize;i++){
           if(arr[i]<min) {
               min=arr[i];
               log=i;
           }
        }
        arr[log]=65535;
        *returns=min;
        returns++;
    }
    return temp;
}
```