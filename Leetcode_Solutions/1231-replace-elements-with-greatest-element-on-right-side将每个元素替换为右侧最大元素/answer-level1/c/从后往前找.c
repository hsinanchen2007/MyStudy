### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int max(int a,int b);
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int *res = malloc(sizeof(int)*arrSize);
    int max_value = -1;
    *returnSize = arrSize;
    for(int i = arrSize-1;i>=0;i--){
        res[i] = max_value;
        max_value = max(max_value,arr[i]);
    }
    return res;
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
```