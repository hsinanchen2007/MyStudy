### 解题思路
暴力

![image.png](https://pic.leetcode-cn.com/c3b81f426a545b25aeff66aa337d0275c9795d9a307ad3771d4f366f8c94a460-image.png)


### 代码

```c
int cmp(const int *a, const int *b)
{
    return *a > *b;
}
int lastStoneWeight(int* stones, int stonesSize){
    int diff;
    while (stonesSize > 1) {
        qsort(stones, stonesSize, sizeof(int), cmp);
        diff = stones[stonesSize-1] - stones[stonesSize-2];
        if (diff == 0) {
            stonesSize -= 2;
        } else {
            stones[stonesSize-2] = diff;
            stonesSize -= 1;  
        }
    }
    return stonesSize == 1 ? stones[0] : 0;
}
```