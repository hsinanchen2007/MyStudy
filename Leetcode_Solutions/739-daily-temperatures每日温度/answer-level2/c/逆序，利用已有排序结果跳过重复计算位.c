![image.png](https://pic.leetcode-cn.com/1c8f5d6bcb7e3959b834a2b280b846e48d03aa6eeb7364347d9187cedc66cad0-image.png)
```
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *rst = (int *)malloc(sizeof(int) * TSize);
    if (TSize == 0) {
        *returnSize = 0;
        return rst;
    }
    
    /*逆序*/
    rst[TSize-1] = 0;
    for (int i = TSize-1; i >= 0; i--) {
        for (int j = i+1; j <= TSize-1; j++) {
            //printf("TSize:%d T[%d]:%d T[%d]:%d rst[%d]:%d\n",TSize,i,T[i],j,T[j],j,rst[j]);
            if (T[j] > T[i]) {
                rst[i] = j-i;
                break;
            }else {
                if (rst[j] == 0) {
                    rst[i] = 0;
                    break;
                }else {
                    j+=(rst[j]-1);
                }                
            }
        }
    }
    *returnSize = TSize;
    return rst;
}

```
