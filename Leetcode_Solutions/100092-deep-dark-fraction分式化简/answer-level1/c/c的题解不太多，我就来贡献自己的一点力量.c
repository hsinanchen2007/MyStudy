### 解题思路
首先理清思路，这里我是从an-1开始推知道a0，会发现用通分会比较方便，但是会发现每再进行一步，都需要将结果倒置。（此处我想的是先倒置在通分会简单一点，因此就有了我下面的代码）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fraction(int* cont, int contSize, int* returnSize){
    int n = cont[contSize - 1], m = 1;
    *returnSize = 2;
    int *returnShow = (int *)malloc(sizeof(int) * 2);
    for(int i = contSize - 1; i > 0; i--){
        int tmp = m;
        m = n;
        n = tmp;
        n = m * cont[i - 1] + n;
    }
    returnShow[0] = n, returnShow[1] = m;
    return returnShow;
}
```