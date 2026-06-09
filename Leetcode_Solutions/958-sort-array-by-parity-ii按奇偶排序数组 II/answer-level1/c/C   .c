开始是暴力解决， 最后看了官方给的第二种思路 

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    //int* arr = (int*)malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    int odd = 1;
    for (int i = 0; i < ASize; i += 2) {
        if (A[i] % 2 != 0) {
            while (A[odd] % 2 == 1) {
                odd += 2;
            }
            int tmp = A[odd];
            A[odd] = A[i];
            A[i] = tmp;
        }    
    }
    return A;
}
```
