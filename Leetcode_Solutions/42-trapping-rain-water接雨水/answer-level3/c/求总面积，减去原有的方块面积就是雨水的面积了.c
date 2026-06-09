### 解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int trap(int* height, int heightSize){
    int i;
    int max = -1;
    int x;
    int sum = 0;
    int sumz = 0;

    if (heightSize < 3) {
        return 0;
    }
    for (i = 0; i < heightSize; i++) {
        sum +=  height[i];
        max = max > height[i] ? (max) : ( x = i, height[i]);
    }
    for (i = 1; i < x; i++) {
        if (height[i] < height[i - 1]) {
            height[i] = height[i - 1];
        }
    }
    for (i = heightSize - 2; i > x; i--) {
        if (height[i] < height[i + 1]) {
            height[i] = height[i + 1];
        }
    }
    for (i = 0; i < heightSize; i++) {
        sumz += height[i];
    }

    return sumz -sum;

}
```