### 解题思路
此处撰写解题思路

### 代码

```c
int max(int* height, int start, int end)
{
    int max = 0;
    for (int i = start; i <= end; i++) {
        max = max < height[i] ? height[i]: max;
    }
    return max;
}

int trap(int* height, int heightSize){
    int high;
    int i, j;
    int maxleft;
    int maxright;
    int sum = 0;

    maxright = max(height, 2, heightSize - 1);
    for (i = 1; i < heightSize - 1; i++) {
        maxleft = max(height, 0, i - 1);
        if (maxleft != 0) {
            if (height[i] >= maxright){
                maxright = max(height, i + 1, heightSize - 1);
            }
            high = maxleft < maxright ? maxleft : maxright;
            sum += ((high - height[i]) < 0 ? 0 : (high - height[i]));
        }
    }
    return sum;
}
```