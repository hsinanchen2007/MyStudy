### 解题思路
若满足当前的数组下标和 之前的最大索引差一则满足条件。

### 代码

```c
int numTimesAllBlue(int* light, int lightSize){
    if (light == NULL || lightSize == 0) {
        return 0;
    }
    int maxIndex = light[0]; /* 记录已经处理的灯的最大索引 */
    int ans = 0;
    if (light[0] == 1) {
        ans++;
    }
    /* 检查当前之前所有的灯是否都已经点亮，若都点亮则变为蓝色 */
    for (int i = 1; i < lightSize; i++) {
        maxIndex  = (maxIndex > light[i]) ? maxIndex : light[i];
        if (i == maxIndex - 1) {
            ans++;
        }
    }
    return ans;
}
```