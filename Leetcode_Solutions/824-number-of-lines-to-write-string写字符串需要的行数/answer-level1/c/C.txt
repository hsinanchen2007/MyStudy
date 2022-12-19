### 解题思路
暴力解决

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    int* arr = (int*)malloc(sizeof(int) * 2);
    //printf(" %d %d ", arr[0], arr[1]);
    memset(arr, 0, sizeof(int) * 2);
    //printf(" %d %d ", arr[0], arr[1]);
    int count = 0;
    int sum = 0;
    int width = 0;
    for (int i = 0; i < strlen(S); i++) {
        sum += widths[S[i] - 'a'];
        width += widths[S[i] - 'a'];
        if (sum > 100) {
            count++;
            sum = 0;
            width = 0;
            i--;
        } 
    }
    *returnSize = 2;
    arr[0] = count + 1;
    arr[1] = width;
    return arr;
}
```