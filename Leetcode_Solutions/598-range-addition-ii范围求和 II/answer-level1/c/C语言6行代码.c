### 解题思路
![image.png](https://pic.leetcode-cn.com/0f33b7dba0fe2b2b0586a39390cca982a24938b41a545b6ebb391e20c63d3c91-image.png)


### 代码

```c
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int min1 = m;
    int min2 = n;
    for(int i = 0; i < opsSize; i++) {
        min1 = fmin(min1, ops[i][0]);
        min2 = fmin(min2, ops[i][1]);
    }
    return min1 * min2;
}
```