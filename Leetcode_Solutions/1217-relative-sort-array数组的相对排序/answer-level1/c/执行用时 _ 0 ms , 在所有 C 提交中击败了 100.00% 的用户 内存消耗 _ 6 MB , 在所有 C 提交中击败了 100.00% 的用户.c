### 解题思路
hash

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int hash[1001]={0};
    for(int i=0;i<arr1Size;i++){
        hash[arr1[i]]++;
    }
    int *a=(int *)malloc(sizeof(int)*arr1Size);
    
    int len=0;
    for(int i=0;i<arr2Size;i++){
        while(hash[arr2[i]]--){
            a[len++]=arr2[i];
        }
    }
    
   
    for(int i=1;i<1001;i++){
        //printf("%d ",i);
       while(hash[i]>0){
            a[len++]=i;
            hash[i]--;
        }
    }
   
    *returnSize=arr1Size;
    return a;
}
```