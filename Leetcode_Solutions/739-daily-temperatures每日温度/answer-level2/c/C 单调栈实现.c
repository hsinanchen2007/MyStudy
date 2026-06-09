![image.png](https://pic.leetcode-cn.com/42aa59b1ef63dd0a32899e8ff836f535fc94d04c21be34a61675d83b7b5f256e-image.png)

```
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *result = malloc(TSize * sizeof(int));
    int sTop = 0;
    int *sArr = malloc((TSize + 1) * sizeof(int));

    memset(sArr, 0, (TSize + 1) * sizeof(int));
    memset(result, 0, TSize * sizeof(int));

    for (int i = 0; i < TSize; i++) {
        while (sTop != 0 && T[sArr[sTop]] < T[i]) {

            result[sArr[sTop]] = i - sArr[sTop];
            sTop--;            
        }

        sArr[++sTop] = i;
    }
    
    *returnSize = TSize;
    return result;
}
```
