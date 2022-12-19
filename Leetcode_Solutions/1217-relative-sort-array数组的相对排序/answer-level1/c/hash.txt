### 解题思路
想到了hash来解决这个问题。 

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* p1, const void* p2) 
{
    return *(int*)p1 - *(int*)p2;
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    if (arr2Size == 0) {
        return arr1;
    }
    int* arr = (int*)malloc(sizeof(int) * arr1Size);
    int arr1Bak[1001];
    //int arr2Bak[1001];

    memset(arr1Bak, 0, sizeof(int) * 1001);
    //memset(arr2Bak, 0, sizeof(int) * 1001);
    
    int i = 0;
    for (i = 0; i < arr1Size; i++) {
        arr1Bak[arr1[i]]++;
    }
    //printf("%d", 1);
 
    int count = 0;
    for (i = 0; i < arr2Size; i++) {
        while(arr1Bak[arr2[i]]) {
            arr1[count] = arr2[i];
            arr1Bak[arr2[i]]--;
            count++;
            //printf("%d ", count);
        }
    }
    if (count != arr1Size) {
        for (int i = 0; i < 1001; i++) {
            while (arr1Bak[i] > 0) {
                arr1[count] = i;
                arr1Bak[i]--;
                count++;
            }
        }
    }
    *returnSize = arr1Size;
    return arr1;
}
```